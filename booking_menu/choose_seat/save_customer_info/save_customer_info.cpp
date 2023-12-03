#include "./save_customer_info.hpp"
#include "../../../shared/color_constants.hpp"
#include "../../../utils/data_saver.hpp"
#include "../../../utils/input_validator.hpp"

void SaveCustomerInfo(tStringMatrix &customer_info,
                      const tString &customer_file, int selected_row,
                      int selected_seat) {
  tString name = "";

  while (true) {
    std::cout << "\nWhat name should go on the ticket? ";
    std::getline(std::cin, name);

    if (IsInputValidName(name) || name.empty() || std::cin.fail()) {
      std::cout << "\nPlease enter a valid name" << std::endl;
      std::cin.clear();
      continue;
    } else {
      tString name_prompt = "\nIs " + kYellowColor + name + kResetColor +
                            " the correct name? (" + kCyanColor + "y" +
                            kResetColor + "/" + kCyanColor + "n" + kResetColor +
                            "): ";

      if (GetUserConfirmation(name_prompt)) {
        break;
      }
    }
  }

  UpdateAndSaveDataToFile(customer_info, customer_file, selected_row,
                          selected_seat, name);
}
