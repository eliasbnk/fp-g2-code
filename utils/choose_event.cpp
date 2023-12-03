#include "./choose_event.hpp"
#include "../shared/character_constants.hpp"
#include "../shared/color_constants.hpp"
#include "../shared/file_constants.hpp"
#include "../utils/screen_cleaner.hpp"
#include "./input_validator.hpp"
#include "./screen_cleaner.hpp"

tStringVector FindAvailableEvents(const tString &folder_path,
                                  const tString &get_event_for) {
  tStringVector event_folders;

  try {
    for (const auto &entry : std::filesystem::directory_iterator(folder_path)) {
      if (std::filesystem::is_directory(entry)) {
        event_folders.push_back(entry.path().filename().string());
      }
    }
  } catch (const std::filesystem::filesystem_error &error) {
    std::cerr << "Error: " << error.what() << std::endl;
    throw std::runtime_error("file error");
  }

  return event_folders;
}

bool ListAvailableEvents(tStringVector &event_folders,
                         const tString &get_event_for) {
  bool is_empty = false;

  std::string menu_title = get_event_for == "booking"  ? "EVENT BOOKING MENU"
                           : get_event_for == "editor" ? "RENAME EVENT MENU"
                                                       : "DELETE EVENT MENU";

  int total_width = 40; // Total width of the output field
  int padding = (total_width - menu_title.length()) / 2;

  if (event_folders.empty()) {
    std::cerr << "We are sorry. We don't have any events right now.\n"
              << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    is_empty = true;
    return is_empty;
  }

  std::sort(event_folders.begin(), event_folders.end());
  ClearScreen();
  std::cout << "--------------------------------------\n";
  std::cout << std::setw(padding + menu_title.length()) << menu_title << "\n";
  std::cout << "--------------------------------------\n";
  std::cout << (get_event_for == "booking"
                    ? "These are the events we have available:"
                    : "Available Events")
            << std::endl;
  int folder_position = 0;
  for (const auto &eventFolder : event_folders) {
    std::cout << kYellowColor << ((folder_position++) + 1) << kResetColor
              << ". " << eventFolder << "\n";
  }
  std::cout << "\n";
  return is_empty;
}

int HandleEventSelection(const tStringVector &event_names,
                         const tString &get_event_for) {
  int selected_event_index = -1;
  int max_events = event_names.size();

  while (true) {
    tString user_input;
    // Prompt the user for input
    std::cout
        << (get_event_for == "booking"
                ? "\nEnter the number of the event you want to open."
                : (get_event_for == "editor"
                       ? "\nEnter the number of the event you want to rename."
                       : "\nEnter the number of the event you want to delete."))
        << "\nEnter " << kRedColor << "0 " << kResetColor
        << "to return to main menu: ";

    getline(std::cin, user_input);

    if (IsInputValidNumber(user_input)) {
      try {
        selected_event_index = std::stoi(user_input);
      } catch (const tInvalidArgumentException &e) {
        std::cerr << "\nInvalid input. Please enter a valid number between "
                  << kYellowColor << "1" << kResetColor << " and "
                  << kYellowColor << max_events << kResetColor << ", or "
                  << kRedColor << "0" << kResetColor
                  << " to return to main menu.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        continue;
      }
      if (selected_event_index == 0 ||
          (selected_event_index >= 1 && selected_event_index <= max_events)) {
        break;
      }
    } else {
      std::cout << "\nInvalid input. Please enter a valid number between "
                << kYellowColor << "1" << kResetColor << " and " << kYellowColor
                << max_events << kResetColor << ", or " << kRedColor << "0"
                << kResetColor << " to return to main menu.\n";
      std::this_thread::sleep_for(std::chrono::seconds(1));

      continue;
    }
  }

  return selected_event_index;
}

tString ChooseEvent(const tString &get_event_for) {
  tStringVector event_folders =
      FindAvailableEvents(kParentDirectory, get_event_for);
  ClearScreen();
  if (!ListAvailableEvents(event_folders, get_event_for)) {

    int user_choice = HandleEventSelection(event_folders, get_event_for);

    if (user_choice == 0) {
      return "exit"; // Return "exit" if the user chooses to exit the program.
    }
    tString event_folder_path =
        kParentDirectory + event_folders[user_choice - 1] + "/";
    return event_folder_path;
  } else {
    return "no events";
  }
}
