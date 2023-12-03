#include "./data_loader.hpp"
#include "../shared/character_constants.hpp"
#include "../shared/color_constants.hpp"


bool LoadDataFromFile(const tString &file_path, tStringMatrix &data) {

  tInputFile input_file(file_path);

  if (!input_file.is_open()) {
    std::cerr << kRedColor << "Error opening the file for reading."
              << kResetColor << std::endl;
    return false;
  }

  tString line;

  // Read each line from the file.
  while (std::getline(input_file, line)) {
    // Create a vector to store the individual cells (values) in the line.
    tStringVector row;

    // Create a string stream to parse the line by comma.
    std::istringstream iss(line);

    // Read and process each cell in the line.
    tString cell;

    while (std::getline(iss, cell, kSeparatorChar)) {
      // Check if cell is empty
      if (cell.empty()) {
        cell = kEmpty;
      }
      // Handle specific cell values, and convert them to appropriate character
      else if (cell == kDoor) {
        cell = kDoorChar; // Replace 'door' with its corresponding character 'H'
      } else if (cell == kSeat) {
        cell = kSeatChar; // Replace 'seat' with its corresponding character '#'
      } else if (cell == kWalkway) {
        cell =
            kWalkwayChar; // Replace 'walk' with its corresponding character ' '
      }

      // Add the processed cell to the row vector.
      row.push_back(cell);
    }

    data.push_back(row);
  }

  // Close the input file stream.
  input_file.close();

  return true;
}
