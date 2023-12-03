#include "./event_creator.hpp"
#include "../../shared/color_constants.hpp"
#include "../../shared/file_constants.hpp"
#include "../../shared/types.hpp"
#include "../../utils/input_validator.hpp"
#include "../data_generator/data_generator.hpp"

bool DoesFileExist(const tFilePath &file_path) {
  return std::filesystem::exists(file_path);
}

bool CreateDataFile(const tString &file, const tFilePath &file_path,
                    const int &row_count, const int &row_length,
                    const int &seats_between_walkways) {

  tOutputFile output_file(file_path);

  if (output_file.is_open()) {
    GenerateDataFile(output_file, file, row_count, row_length,
                     seats_between_walkways);

    output_file.close();
    return true;
  } else {
    std::cerr << "\nFailed to open the file for writing." << std::endl;
    return false;
  }
}

bool CreateEventDataFolder(const tString &event_name, const int &row_count,
                           const int &row_length,
                           const int &seats_between_walkways,
                           const tFilePath &folder_path) {

  tStringVector data_files = {kSeatDataFile,   kSoldDataFile,
                              kPriceDataFile,  kNamesDataFile,
                              kTicketDataFile, kChekedInDataFile};
  bool success = true; // Assume success initially

  if (std::filesystem::exists(folder_path) &&
      std::filesystem::is_directory(folder_path)) {

    if (GetUserConfirmation("\nEvent: " + kYellowColor + event_name +
                            kResetColor + " already exists. \nDo you want to " +
                            kRedColor + "override it" + kResetColor + "? (" +
                            kCyanColor + "y" + kResetColor + "/" + kCyanColor +
                            "n" + kResetColor + "): ")) {

      for (const tString &file : data_files) {
        tFilePath file_path = folder_path / file;

        if (DoesFileExist(file_path)) {
          std::filesystem::remove(file_path); // Delete the existing file
        }
        success = CreateDataFile(file, file_path, row_count, row_length,
                                 seats_between_walkways) &&
                  success; // Create the file and update success flag
      }
    } else {
      success = false; // User chose not to override
    }
  } else if (std::filesystem::create_directories(folder_path)) {
    for (const tString &file : data_files) {
      tFilePath file_path = folder_path / file; // Declare file_path here
      success = CreateDataFile(file, file_path, row_count, row_length,
                               seats_between_walkways) &&
                success; // Create the file and update success flag
    }
  } else {
    std::cerr << kRedColor << "\nError creating directory: " << kResetColor
              << kYellowColor << folder_path << kResetColor << std::endl;
    success = false; // There was an error, set success to false
  }

  return success;
}
