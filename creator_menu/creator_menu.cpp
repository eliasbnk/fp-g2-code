#include "../shared/color_constants.hpp"
#include "../shared/file_constants.hpp"
#include "../shared/types.hpp"
#include "../utils/delete_event.hpp"
#include "../utils/input_validator.hpp"
#include "../utils/screen_cleaner.hpp"
#include "./data_generator/data_generator.hpp"
#include "./event_creator/event_creator.hpp"

void CreateEventMenu() {
  tString event_name;
  int row_count, row_length, seats_between_walkways;
  int session_attempts = 0;
  while (true) {
    ClearScreen();
    std::cout << "--------------------------------------\n";
    std::cout << "           EVENT CREATOR MENU\n";
    std::cout << "--------------------------------------\n";
    if (session_attempts > 0) {
      std::string continue_prompt = "\nContinue? (" + kCyanColor + "y" +
                                    kResetColor + "/" + kCyanColor + "n" +
                                    kResetColor + "): ";
      if (!GetUserConfirmation(continue_prompt)) {
        return;
      }
    }
    session_attempts += 1;
    std::cout << "\nNew event name: ";
    std::getline(std::cin, event_name);

    if (event_name.empty() || std::cin.fail()) {
      std::cout << "\nPlease enter a valid event name" << std::endl;
      std::cin.clear();
      continue;
    } else {
      tString event_name_prompt = "\nIs " + kYellowColor + event_name +
                                  kResetColor + " the correct event name? (" +
                                  kCyanColor + "y" + kResetColor + "/" +
                                  kCyanColor + "n" + kResetColor + "): ";

      if (GetUserConfirmation(event_name_prompt)) {
        break;
      }
    }
  }
  tFilePath folder_path = kParentDirectory + event_name;
  if (!std::filesystem::exists(folder_path)) {
    GetVenueSize(row_count, row_length, seats_between_walkways);
    if (CreateEventDataFolder(event_name, row_count, row_length,
                              seats_between_walkways, folder_path)) {
      std::cout << kGreenColor << "\nFiles created successfully." << kResetColor
                << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      return;
    } else {
      std::cout << kRedColor << "\nFailed to create files." << kResetColor
                << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      return;
    }
  } else {
    std::cout << kRedColor << "\nFolder already exists." << kResetColor
              << std::endl;
    std::string continue_prompt = "\nContinue? (" + kCyanColor + "y" +
                                  kResetColor + "/" + kCyanColor + "n" +
                                  kResetColor + "): ";
    if (!GetUserConfirmation(continue_prompt)) {
      return;
    } else {
      if (!DeleteEventFolder(folder_path)) {
        std::cout << kRedColor << "\nFailed to delete files." << kResetColor
                  << std::endl;
      } else {

        GetVenueSize(row_count, row_length, seats_between_walkways);
        CreateEventDataFolder(event_name, row_count, row_length,
                              seats_between_walkways, folder_path);
        std::cout << kGreenColor << "\nFiles created successfully."
                  << kResetColor << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
      }
    }
  }
}
