#include "./delete_event.hpp"
#include "../shared/color_constants.hpp"
#include "../shared/file_constants.hpp"
#include "../utils/choose_event.hpp"
#include "../utils/delete_event.hpp"
#include "../utils/get_event_name.hpp"
#include "../utils/input_validator.hpp"
#include "../utils/screen_cleaner.hpp"

/**
 * @brief Delete an existing event folder.
 *
 * Allows users to choose an event folder and confirm deletion. If the folder
 * exists, it asks for confirmation and provides a second confirmation for
 * irreversible deletion. Users can choose to proceed with caution or cancel the
 * deletion. If the folder is deleted successfully, it displays a success
 * message.
 */
void DeleteEventMenu() {
  while (true) {
    ClearScreen();
    const tString event_directory = ChooseEvent("delete");

    if (event_directory == "file error" || event_directory == "no events") {
      break;
    } else if (event_directory == "exit") {
      break;
    }

    tString event_name = GetEventName(event_directory);

    std::filesystem::path source_path;
    source_path = kParentDirectory + event_name;

    if (!std::filesystem::exists(source_path)) {
      std::cout << kRedColor << "Error: " << kResetColor << kYellowColor
                << event_name << kResetColor << kRedColor
                << " does not exist.\n"
                << kResetColor;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::string continue_prompt = "\nContinue? (" + kCyanColor + "y" +
                                    kResetColor + "/" + kCyanColor + "n" +
                                    kResetColor + "): ";
      if (!GetUserConfirmation(continue_prompt)) {
        break;
      }
    }

    std::string override_prompt =
        "\n" + kRedColor + "Are you sure you want to delete " + kResetColor +
        kYellowColor + event_name + kResetColor + kRedColor + " ?" +
        kResetColor + " (" + kCyanColor + "y" + kResetColor + "/" + kCyanColor +
        "n" + kResetColor + "): ";
    if (!GetUserConfirmation(override_prompt)) {
      break;
    } else {
      std::string override_confirmation_prompt =
          "\n" + kRedColor + "Are you really sure you want to delete " +
          kResetColor + kYellowColor + event_name + kResetColor + kRedColor +
          " ? PROCEED WITH EXTREME CAUTION! THIS ACTION IS IRREVERSIBLE!" +
          kResetColor + " (" + kCyanColor + "y" + kResetColor + "/" +
          kCyanColor + "n" + kResetColor + "): ";
      if (!GetUserConfirmation(override_confirmation_prompt)) {
        break;
      } else {
        std::string continue_prompt = "\nContinue? (" + kCyanColor + "y" +
                                      kResetColor + "/" + kCyanColor + "n" +
                                      kResetColor + "): ";
        if (!DeleteEventFolder(source_path)) {
          std::cout << kRedColor << "\nFailed to delete files." << kResetColor
                    << std::endl;
          std::this_thread::sleep_for(std::chrono::seconds(1));
          if (!GetUserConfirmation(continue_prompt)) {
            break;
          } else {
            continue;
          }
        }
        break;
      }
    }
  }
}
