#include "./generate_booker_data.hpp"
#include "../../../shared/character_constants.hpp"

void GenerateBookerNameAndTicketNumberDataWalkwayRow(tOutputFile &output_file,
                                                     const int row_length) {
  output_file << kNotAvailableComma;

  for (int i = 1; i <= row_length; i++) {
    output_file << kNotAvailable;
    if (i != row_length) {
      output_file << kSeparatorChar;
    }
  }
  output_file << std::endl;
}

void GenerateBookerNameAndTicketNumberDataSeatRow(
    tOutputFile &output_file, const int row_length,
    const int seats_between_walkway) {
  output_file << kNotAvailableComma;

  for (int i = 1; i <= row_length; i++) {
    if (i % (seats_between_walkway + 1) == 0) {
      output_file << kNotAvailable;
    } else {
      output_file << kEmpty;
    }

    if (i != row_length) {
      output_file << kSeparatorChar;
    }
  }
  output_file << std::endl;
}

void GenerateBookerNameAndTicketNumberData(tOutputFile &output_file,
                                           const int row_count,
                                           const int row_length,
                                           const int even_section_distribution,
                                           const int seats_between_walkway) {
  for (int row = 0; row <= row_count; row++) {
    if (row % even_section_distribution == 0) {
      GenerateBookerNameAndTicketNumberDataWalkwayRow(output_file, row_length);
    } else {
      GenerateBookerNameAndTicketNumberDataSeatRow(output_file, row_length,
                                                   seats_between_walkway);
    }
    output_file.flush();
  }
}
