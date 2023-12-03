#include "./check_in_menu.hpp"
#include "../shared/character_constants.hpp"
#include "../shared/color_constants.hpp"
#include "../shared/file_constants.hpp"
#include "../shared/types.hpp"
#include "../utils/data_loader.hpp"
#include "../utils/data_saver.hpp"
#include "../utils/get_event_name.hpp"
#include "../utils/input_validator.hpp"
#include "../utils/screen_cleaner.hpp"
#include "../utils/ticket_finder.hpp"

void CheckInMenu() {
  tString event_name, check_in_file, ticket_file, customer_file;
  while (true) {
    ClearScreen();
    std::cout << "--------------------------------------\n";
    std::cout << "             CHECK IN MENU\n";
    std::cout << "--------------------------------------\n";
    tString ticket_number =
        GetTicketNumber("Please enter your ticket number to enter: ");

    if (ticket_number.empty()) {
      std::cout << "Invalid ticket number.\n";
      if (!PromptRetry()) {
        break;
      } else {
        continue;
      }
    }

    event_name = ExtractEventName(ticket_number);
    int *seat_row = new int;
    int *seat_column = new int;

    // Construct file paths
    check_in_file = kParentDirectory + event_name + "/" + kChekedInDataFile;
    ticket_file = kParentDirectory + event_name + "/" + kTicketDataFile;
    customer_file = kParentDirectory + event_name + "/" + kNamesDataFile;
    tStringMatrix customer_info;

    if (!LoadDataFromFile(customer_file, customer_info)) {
      std::cout << kRedColor << "Failed to load customer data." << kResetColor
                << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      if (!PromptRetry()) {
        break;
      } else {
        continue;
      }
    }
    tStringMatrix issued_tickets;
    if (!LoadDataFromFile(ticket_file, issued_tickets)) {
      std::cout << kRedColor << "Failed to load ticket data." << kResetColor
                << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      if (!PromptRetry()) {
        break;
      } else {
        continue;
      }
    }

    tStringMatrix checked_in;
    if (!LoadDataFromFile(check_in_file, checked_in)) {
      std::cout << kRedColor << "Failed to load check in data." << kResetColor
                << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      if (!PromptRetry()) {
        break;
      } else {
        continue;
      }
    }

    if (WasTicketNumberIssuedGetLocation(issued_tickets, ticket_number,
                                         seat_row, seat_column)) {

      int row = *seat_row;
      int column = *seat_column;
      tString check_in_status = checked_in[row][column];
      if (check_in_status == kNotCheckedIn) {
        UpdateAndSaveDataToFile(checked_in, check_in_file, row, column,
                                kCheckedIn);
        std::cout << "\nHello, " << kYellowColor << customer_info[row][column]
                  << kResetColor << "!\n";
        std::cout << "Thank you for checking in!\n";
        std::cout << "Your seat is row " << kYellowColor << row << kResetColor
                  << " and column " << kYellowColor << column << kResetColor
                  << ".\n";
        std::cout << "Enjoy the event!\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
        delete seat_row;
        delete seat_column;
        break;
      } else {
        std::cout << "\nHello, " << kYellowColor << customer_info[row][column]
                  << kResetColor << "!\n";
        std::cout << "You have already checked in.\n";
        std::cout << "Your seat is row " << kYellowColor << row << kResetColor
                  << " and column " << kYellowColor << column << kResetColor
                  << ".\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
        delete seat_row;
        delete seat_column;
        break;
      }
    } else {
      std::cout << kRedColor << "Ticket number not found." << kResetColor
                << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      delete seat_row;
      delete seat_column;
      if (!PromptRetry())
        break;
    }
  }
}
