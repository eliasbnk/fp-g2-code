#include "./input_validator.hpp"
#include "../shared/color_constants.hpp"


bool IsInputValidAlpha(const tString &input) {
  if (input.empty()) {
    return false;
  }

  return std::all_of(input.begin(), input.end(), ::isalpha);
}

bool IsInputValidNumber(const tString &input) {
  if (input.empty()) {
    return false;
  }

  return std::all_of(input.begin(), input.end(), ::isdigit);
}

bool IsInputValidName(const tString &input) {
  static const std::regex pattern(
      R"(^[\p{L}]+[\p{M}]*([\p{L}\p{M} '.-]*[\p{L}\p{M}])?$)",
      std::regex_constants::ECMAScript);
  return std::regex_match(input, pattern);
}

bool IsInputValidNumberGreaterThanZero(const tString &input) {
  if (input.empty()) {
    return false;
  }

  if (!std::all_of(input.begin(), input.end(), ::isdigit)) {
    // Not all characters are digits
    return false;
  }

  // Convert the input string to an integer
  int const number = std::stoi(input);

  // Check if the number is greater than zero
  return number > 0;
}

char ValidateYesNoInput(const tString &prompt) {
  char input_char = 'N';

  while (true) {
    tString user_input;

    std::cout << prompt;
    std::getline(std::cin, user_input);

    if (!IsInputValidAlpha(user_input) || std::cin.fail()) {
      std::cout << "\nInvalid input. Please enter " << kCyanColor << "Y"
                << kResetColor << " or " << kCyanColor << "N" << kResetColor
                << "." << std::endl;
      continue;
    }

    // Convert the input to uppercase for case-insensitive comparison
    std::transform(user_input.begin(), user_input.end(), user_input.begin(),
                   ::toupper);

    if (user_input != "Y" && user_input != "YES" && user_input != "N" &&
        user_input != "NO") {
      std::cout << "\nInvalid input. Please enter " << kCyanColor << "Y"
                << kResetColor << " or " << kCyanColor << "N" << kResetColor
                << "." << std::endl;
    } else if (user_input == "N" || user_input == "NO") {
      input_char = 'N';
      break;
    } else if (user_input == "Y" || user_input == "YES") {
      input_char = 'Y';
      break;
    }
  }

  return input_char;
}

bool GetUserConfirmation(const tString &prompt) {
  return ValidateYesNoInput(prompt) == 'Y';
}

bool PromptRetry(){
  tString try_again_prompt = "\nTry again? (" + kCyanColor + "y" + kResetColor +
                             "/" + kCyanColor + "n" + kResetColor + "): ";
  return GetUserConfirmation(try_again_prompt);
}