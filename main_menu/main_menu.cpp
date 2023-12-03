#include "./main_menu.hpp"
#include "../booking_menu/booking_menu.hpp"
#include "../check_in_menu/check_in_menu.hpp"
#include "../creator_menu/creator_menu.hpp"
#include "../delete_event/delete_event.hpp"
#include "../editor_menu/editor_menu.hpp"
#include "../refund_menu/refund_menu.hpp"
#include "../shared/color_constants.hpp"
#include "../shared/types.hpp"
#include "../utils/input_validator.hpp"
#include "../utils/screen_cleaner.hpp"

const int kNumberOfOptions = 7;

void DisplayMainMenu() {
  std::cout << "======================================\n";
  std::cout << "          TICKET BOOKER SYSTEM\n";
  std::cout << "======================================\n";
  std::cout << "\n               MAIN MENU\n";
  std::cout << "--------------------------------------\n";

  // Define menu options with enumerated numbers
  std::string menu_options[kNumberOfOptions] = {
      "Book a ticket",   "Check In Desk",   "Refund Ticket", "Create an event",
      "Rename an event", "Delete an Event", "Exit"};

  // Display menu options using a loop with enumeration
  for (int i = 0; i < kNumberOfOptions; ++i) {
    std::cout << "  " << kYellowColor << i + 1 << kResetColor << ". "
              << menu_options[i] << "\n";
  }

  std::cout << "--------------------------------------\n";
}

int GetValidMenuChoice() {
  int selection;
  std::string menuInput;

  while (true) {
    std::cout << "\nEnter your choice: ";
    getline(std::cin, menuInput);

    if (IsInputValidNumber(menuInput)) {
      try {
        selection = std::stoi(menuInput);
      } catch (const std::invalid_argument &e) {
        std::cerr << kRedColor
                  << "\nInvalid input. Please enter a valid number between "
                  << kResetColor << kYellowColor << 1 << kResetColor << " and "
                  << kResetColor << kYellowColor << kNumberOfOptions
                  << kResetColor << kRedColor << " to exit.\n"
                  << kResetColor;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        continue;
      }
      if (selection >= 1 && selection <= kNumberOfOptions) {
        break;
      }
    } else {
      std::cerr << kRedColor
                << "\nInvalid input. Please enter a valid number between "
                << kResetColor << kYellowColor << 1 << kResetColor << " and "
                << kResetColor << kYellowColor << kNumberOfOptions
                << kResetColor << kRedColor << " to exit.\n"
                << kResetColor;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      continue;
    }
  }
  return selection;
}

void MainMenu() {
  int selection;

  while (true) {
    ClearScreen();
    DisplayMainMenu();
    selection = GetValidMenuChoice();

    switch (selection) {
    case 1:
      EventBookingMenu();
      break;
    case 2:
      CheckInMenu();
      break;
    case 3:
      RefundTicketMenu();
      break;
    case 4:
      CreateEventMenu();
      break;
    case 5:
      RenameEventMenu();
      break;
    case 6:
      DeleteEventMenu();
      break;
    case 7:
      std::cout << "\nThank you for using Ticket Booker!\n\n\n";
      exit(0);
    default:
      std::cout << "\nInvalid selection.\n\n";
    }
  }
}
