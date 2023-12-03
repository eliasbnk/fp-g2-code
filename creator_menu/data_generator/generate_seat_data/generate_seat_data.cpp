#include "./generate_seat_data.hpp"
#include "../../../shared/character_constants.hpp"

void GenerateSeatMapDataWalkwayRow(tOutputFile &output_file,
                                   const int row_length,
                                   const int seats_between_walkway,
                                   const int row) {
  output_file << kSeparatorChar;

  if (row == 0) {
    for (int i = 1; i <= row_length; i++) {
      if (i % (seats_between_walkway + 1) != 0) {
        output_file << i;
      } else {
        output_file << kWalkwayChar;
      }

      if (i != row_length) {
        output_file << kSeparatorChar;
      }
    }
  } else {
    for (int i = 1; i <= row_length; i++) {
      if (i == 1 || i == row_length) {
        output_file << kDoor;
      } else {
        output_file << kWalkway;
      }

      if (i != row_length) {
        output_file << kSeparatorChar;
      }
    }
  }
  output_file << std::endl;
}

void GenerateSeatMapDataSeatRow(tOutputFile &output_file, const int row_length,
                                const int seats_between_walkway,
                                const int row) {
  output_file << row << kSeparatorChar;

  for (int i = 1; i <= row_length; i++) {
    if (i % (seats_between_walkway + 1) == 0) {
      output_file << kWalkway;
    } else {
      output_file << kSeat;
    }

    if (i != row_length) {
      output_file << kSeparatorChar;
    }
  }

  output_file << std::endl;
}

void GenerateSeatMapData(tOutputFile &output_file, const int row_count,
                         const int row_length,
                         const int even_section_distribution,
                         const int seats_between_walkway) {
  for (int row = 0; row <= row_count; row++) {
    if (row % even_section_distribution == 0) {
      GenerateSeatMapDataWalkwayRow(output_file, row_length,
                                    seats_between_walkway, row);
    } else {
      GenerateSeatMapDataSeatRow(output_file, row_length, seats_between_walkway,
                                 row);
    }
    output_file.flush();
  }
}
