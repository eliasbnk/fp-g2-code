#include "./data_saver.hpp"
#include "../shared/character_constants.hpp"



void UpdateAndSaveDataToFile(tStringMatrix &data, const tString &file_path,
                             const int &selected_row, const int &selected_col,
                             const tString &new_value) {

  tOutputFile output_file(file_path);

  if (!output_file.is_open()) {
    std::cerr << "Error opening the file for writing." << std::endl;
    exit(1); // Exit the program with an error code.
  }

  data[selected_row][selected_col] = new_value;

  for (const auto &row : data) {
    // Iterate through each cell in the row.
    for (int cell = 0; cell < row.size(); ++cell) {
      output_file << row[cell];

      // Add a comma after the cell value if it's not the last cell in the row.
      if (cell < row.size() - 1) {
        output_file << kSeparatorChar;
      }
      output_file.flush();
    }

    output_file << std::endl;
  }

  // Close the output file stream.
  output_file.close();
}
