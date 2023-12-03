#include "./generate_check_in_data.hpp"
#include "../../../shared/character_constants.hpp"

void GenerateChekedInDataWalkwayRow(tOutputFile &output_file,
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

void GenerateChekedInDataSeatRow(tOutputFile &output_file, const int row_length,
                                 const int seats_between_walkway) {
  output_file << kNotAvailableComma;

  for (int i = 1; i <= row_length; i++) {
    if (i % (seats_between_walkway + 1) == 0) {
      output_file << kNotAvailable;
    } else {
      output_file << kNotCheckedIn;
    }

    if (i != row_length) {
      output_file << kSeparatorChar;
    }
  }
  output_file << std::endl;
}

void GenerateChekedInData(tOutputFile &output_file, const int row_count,
                          const int row_length,
                          const int even_section_distribution,
                          const int seats_between_walkway) {
  for (int row = 0; row <= row_count; row++) {
    if (row % even_section_distribution == 0) {
      GenerateChekedInDataWalkwayRow(output_file, row_length);
    } else {
      GenerateChekedInDataSeatRow(output_file, row_length,
                                  seats_between_walkway);
    }
    output_file.flush();
  }
}
