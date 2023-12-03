#include "./generate_price_data.hpp"
#include "../../../shared/character_constants.hpp"

void GeneratePriceDataWalkwayRow(tOutputFile &output_file,
                                 const int row_length) {
  output_file << kPriceNotAvailableComma;

  for (int i = 1; i <= row_length; i++) {
    output_file << kPriceNotAvailable;
    if (i != row_length) {
      output_file << kSeparatorChar;
    }
  }
  output_file << std::endl;
}

void GeneratePriceDataSeatRow(tOutputFile &output_file, const int row_length,
                              const int seats_between_walkway, const int row,
                              const int even_section_distribution,
                              const double max_section_price,
                              const double section_price_decrement) {
  output_file << kPriceNotAvailableComma;

  for (int i = 1; i <= row_length; i++) {
    if (i % (seats_between_walkway + 1) == 0) {
      output_file << kPriceNotAvailable;
    } else {
      output_file << max_section_price - (section_price_decrement *
                                          (row / even_section_distribution));
    }
    if (i != row_length) {
      output_file << kSeparatorChar;
    }
  }
  output_file << std::endl;
}

void GeneratePriceData(tOutputFile &output_file, int row_count, int row_length,
                       int even_section_distribution,
                       int seats_between_walkway) {
  // Constant values for default price settings
  const double max_section_price = 573.99, section_price_decrement = 124.00;
  for (int row = 0; row <= row_count; row++) {
    if (row % even_section_distribution == 0) {
      GeneratePriceDataWalkwayRow(output_file, row_length);
    } else {
      GeneratePriceDataSeatRow(output_file, row_length, seats_between_walkway,
                               row, even_section_distribution,
                               max_section_price, section_price_decrement);
    }
    output_file.flush();
  }
}
