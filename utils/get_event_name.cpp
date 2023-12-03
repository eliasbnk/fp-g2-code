#include "./get_event_name.hpp"

tString GetEventName(const tString &event_folder_path) {
  size_t first_slash_pos = event_folder_path.find('/');
  if (first_slash_pos != std::string::npos) {
    size_t second_slash_pos = event_folder_path.find('/', first_slash_pos + 1);
    if (second_slash_pos != std::string::npos) {
      size_t third_slash_pos =
          event_folder_path.find('/', second_slash_pos + 1);
      if (third_slash_pos != std::string::npos) {
        return event_folder_path.substr(second_slash_pos + 1,
                                        third_slash_pos - second_slash_pos - 1);
      }
    }
  }
  return ""; // Return an empty string if the slash is not found as expected.
}

tString ExtractEventName(const tString &input) {
  size_t pos = input.find_first_of("0123456789");
  tString event_name = input.substr(0, pos - 1);
  std::replace(event_name.begin(), event_name.end(), '-', ' ');
  return event_name;
}