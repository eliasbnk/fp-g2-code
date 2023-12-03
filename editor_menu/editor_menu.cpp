#include "./editor_menu.hpp"
#include "../shared/color_constants.hpp"
#include "../shared/file_constants.hpp"
#include "../utils/choose_event.hpp"
#include "../utils/get_event_name.hpp"
#include "../utils/input_validator.hpp"

void PrintErrorMessage(const std::string &message) {
  std::cerr << kRedColor << "\nError: " << kResetColor << kYellowColor
            << message << kResetColor << std::endl;
}

void CopyDirectory(const std::filesystem::path &source,
                   const std::filesystem::path &destination) {

  std::filesystem::create_directories(destination);

  for (const auto &file :
       std::filesystem::recursive_directory_iterator(source)) {
    const auto &relativePath = std::filesystem::relative(file.path(), source);
    std::filesystem::copy(
        file, destination / relativePath,
        std::filesystem::copy_options::recursive |
            std::filesystem::copy_options::overwrite_existing);
  }
}

std::string GetValidInput(const std::string &prompt) {
  std::string input;
  while (true) {
    std::cout << prompt;
    std::getline(std::cin, input);

    if (std::cin.fail() || input.empty()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      PrintErrorMessage("Invalid input. Please enter a valid value.\n");
    } else {
      break;
    }
  }
  return input;
}

void RenameEventMenu() {
  while (true) {

    const tString event_directory = ChooseEvent("editor");

    if (event_directory == "file error" || event_directory == "no events") {
      break;
    } else if (event_directory == "exit") {
      break;
    }

    tString event_name = GetEventName(event_directory);

    std::filesystem::path source_path;
    std::string new_folder_name;

    source_path = kParentDirectory + event_name;

    if (!std::filesystem::exists(source_path)) {
      PrintErrorMessage(event_name + " does not exist.");
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::string continue_prompt = "\nContinue? (" + kCyanColor + "y" +
                                    kResetColor + "/" + kCyanColor + "n" +
                                    kResetColor + "): ";
      if (!GetUserConfirmation(continue_prompt)) {
        break;
      }
    }

    new_folder_name = GetValidInput("\nWhat would you like to rename it to? ");

    std::filesystem::path destination_path = kParentDirectory + new_folder_name;

    if (!std::filesystem::exists(destination_path)) {
      try {
        std::filesystem::rename(source_path, destination_path);
        std::cout << kGreenColor << "\nFolder renamed successfully"
                  << kResetColor << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        break;
      } catch (const std::filesystem::filesystem_error &e) {
        if (e.code() == std::make_error_code(std::errc::cross_device_link)) {
          // Handle cross-device renaming
          try {
            CopyDirectory(source_path, destination_path);
            try {
              std::filesystem::remove_all(source_path);
            } catch (const std::filesystem::filesystem_error &e) {
              std::cerr << "Filesystem error: " << e.what() << '\n';
            } catch (const std::exception &e) {
              std::cerr << "Standard exception: " << e.what() << '\n';
            }
            std::cout << kGreenColor
                      << "\nFolder renamed successfully"
                      << kResetColor << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
          } catch (const std::filesystem::filesystem_error &copyError) {
            std::cerr << "Error during copy: " << copyError.what() << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
          }
        } else {
          std::cerr << "Error during rename: " << e.what() << '\n';
          std::this_thread::sleep_for(std::chrono::seconds(1));
          break;
        }
      }
    } else {
      PrintErrorMessage(kResetColor + "A folder with the name " + kYellowColor +
                        new_folder_name + kResetColor + " already exists.");
      std::string continue_prompt = "\nContinue? (" + kCyanColor + "y" +
                                    kResetColor + "/" + kCyanColor + "n" +
                                    kResetColor + "): ";
      if (!GetUserConfirmation(continue_prompt)) {
        break;
      } else {
        try {
          std::filesystem::remove_all(destination_path);
        } catch (const std::filesystem::filesystem_error &e) {
          std::cerr << "Filesystem error: " << e.what() << '\n';
        } catch (const std::exception &e) {
          std::cerr << "Standard exception: " << e.what() << '\n';
        }
        try {
          std::filesystem::rename(source_path, destination_path);
          std::cout << kGreenColor << "\nFolder renamed successfully"
                    << kResetColor << std::endl;
          std::this_thread::sleep_for(std::chrono::seconds(1));
          break;
        } catch (const std::filesystem::filesystem_error &e) {
          if (e.code() == std::make_error_code(std::errc::cross_device_link)) {
            // Handle cross-device renaming
            try {
              CopyDirectory(source_path, destination_path);
              // Remove the original directory
              try {
                std::filesystem::remove_all(source_path);
              } catch (const std::filesystem::filesystem_error &e) {
                std::cerr << "Filesystem error: " << e.what() << '\n';
              } catch (const std::exception &e) {
                std::cerr << "Standard exception: " << e.what() << '\n';
              }
              std::cout << kGreenColor
                        << "\nFolder renamed successfully"
                        << kResetColor << std::endl;
              std::this_thread::sleep_for(std::chrono::seconds(1));
              break;
            } catch (const std::filesystem::filesystem_error &copyError) {
              std::cerr << "Error during copy: " << copyError.what() << '\n';
              std::this_thread::sleep_for(std::chrono::seconds(1));
              break;
            }
          } else {
            std::cerr << "Error during rename: " << e.what() << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
          }
        }
      }
    }
  }
}
