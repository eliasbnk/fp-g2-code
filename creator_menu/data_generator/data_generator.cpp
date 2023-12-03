#include "./data_generator.hpp"
#include "../../shared/character_constants.hpp"
#include "../../shared/color_constants.hpp"
#include "../../shared/file_constants.hpp"
#include "../../shared/types.hpp"
#include "../../utils/input_validator.hpp"
#include "./generate_sold_data/generate_sold_data.hpp"
#include "./generate_booker_data/generate_booker_data.hpp"
#include "./generate_seat_data/generate_seat_data.hpp"
#include "./generate_price_data/generate_price_data.hpp"
#include "./generate_check_in_data/generate_check_in_data.hpp"


/**
 * @brief Get user input with validation for a positive integer within a specified limit.
 *
 * @param prompt [in] The message to display to the user as a prompt.
 * @param value  [out] The reference to the integer variable where the validated input will be stored.
 */

void GetInputWithValidation(const tString &prompt, int &value) {
  while (true) {
    tString input;
    std::cout << prompt;
    getline(std::cin, input);
    if (!IsInputValidNumber(input) || stoi(input) < 1 || std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "\nInvalid input. Please enter a positive integer.\n";
    } else if (stoi(input) > 15) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "\nOur platform currently supports venues smaller than 15 "
                   "units.\n";
    } else {
      value = stoi(input);
      break;
    }
  }
}

/**
 * @brief Guides the user to set venue size parameters.
 *
 * @param  row_count - Number of venue rows.
 * @param  row_length - Length of each row.
 * @param  seats_between_walkway - Number of seats between vertical walkways.
 */

void GetVenueSize(int &row_count, int &row_length, int &seats_between_walkway) {
  GetInputWithValidation("\nEnter row count: ", row_count);
  GetInputWithValidation("\nEnter row length: ", row_length);
  GetInputWithValidation("\nEnter the number of seats between walkways: ",
                         seats_between_walkway);
}

/**
 * @brief Generates event-related data files with proper data formatting.
 *
 * @param  output_file - The data file to which the data is written.
 * @param  file_name - The name of the data file.
 * @param  row_count - Number of venue rows.
 * @param  row_length - Length of each row.
 * @param  seats_between_walkway -  Number of seats between vertical walkways.
 */
void GenerateDataFile(tOutputFile &output_file, const tString file_name,
                      const int row_count, const int row_length,
                      const int seats_between_walkway) {
  // Calculate max even distribution
  int even_section_distribution = 0;
  for (int distr_factor = 2; distr_factor <= sqrt(row_count + 1);
       distr_factor++) {
    if (row_count % distr_factor == 0) {
      even_section_distribution = row_count / distr_factor;
    }
    if ((row_count + 1) % distr_factor == 0) {
      even_section_distribution = (row_count + 1) / distr_factor;
    }
  }

  // Select function to run
  if (file_name == kSoldDataFile) {
    GenerateSoldData(output_file, row_count, row_length,
                     even_section_distribution, seats_between_walkway);
  } else if (file_name == kSeatDataFile) {
    GenerateSeatMapData(output_file, row_count, row_length,
                        even_section_distribution, seats_between_walkway);
  } else if (file_name == kPriceDataFile) {
    GeneratePriceData(output_file, row_count, row_length,
                      even_section_distribution, seats_between_walkway);
  } else if (file_name == kNamesDataFile || file_name == kTicketDataFile) {
    GenerateBookerNameAndTicketNumberData(output_file, row_count, row_length,
                                          even_section_distribution,
                                          seats_between_walkway);
  } else if (file_name == kChekedInDataFile) {
    GenerateChekedInData(output_file, row_count, row_length,
                         even_section_distribution, seats_between_walkway);
  } else {
    std::cout << kRedColor << "\nError: Invalid filepath." << kResetColor
              << std::endl;
  }
}