#include "./refund_menu.hpp"
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

void RefundTicketMenu() {
  tString event_name, customer_file, seats_availability_file, ticket_file,
      check_in_file;
  while (true) {
    ClearScreen();
    std::cout << "--------------------------------------\n";
    std::cout << "           TICKET REFUND MENU\n";
    std::cout << "--------------------------------------\n";
    tString ticket_number =
        GetTicketNumber("Please enter the ticket number you want to refund: ");

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
    customer_file = kParentDirectory + event_name + "/" + kNamesDataFile;
    seats_availability_file =
        kParentDirectory + event_name + "/" + kSoldDataFile;
    ticket_file = kParentDirectory + event_name + "/" + kTicketDataFile;
    check_in_file = kParentDirectory + event_name + "/" + kChekedInDataFile;

    tStringMatrix seat_availability;
    if (!LoadDataFromFile(seats_availability_file, seat_availability)) {
      std::cout << kRedColor << "Error loading seats availability file."
                << kResetColor << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      if (!PromptRetry()) {
        break;
      } else {
        continue;
      }
    }
    tStringMatrix customer_info;
    if (!LoadDataFromFile(customer_file, customer_info)) {
      std::cout << kRedColor << "Error loading customer file." << kResetColor
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
      std::cout << kRedColor << "Error loading ticket file." << kResetColor
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
      std::cout << kRedColor << "Error loading checked in file." << kResetColor
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
        UpdateAndSaveDataToFile(customer_info, customer_file, row, column,
                                kEmpty);
        UpdateAndSaveDataToFile(seat_availability, seats_availability_file, row,
                                column, kAvailable);
        UpdateAndSaveDataToFile(issued_tickets, ticket_file, row, column,
                                kEmpty);
        std::cout << kGreenColor << ticket_number << " refunded successfully"
                  << kResetColor << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        delete seat_row;
        delete seat_column;
        break;
      } else {
        std::cout << kRedColor
                  << "\nTicket number was already used, unfortunately we can't "
                     "refund you."
                  << kResetColor << std::endl;

        delete seat_row;
        delete seat_column;
        if (!PromptRetry())
          break;
      }
    } else {
      std::cout << kRedColor << "Ticket number not found." << kResetColor
                << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(2));
      delete seat_row;
      delete seat_column;
      break;
    }
  }
}
