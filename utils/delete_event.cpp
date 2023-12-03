#include "./delete_event.hpp"

/**
 * @brief Delete an event folder and its contents.
 *
 * @param folder_path The path to the event folder to be deleted.
 * @return True if the folder and its contents were successfully deleted, false otherwise.
 */
bool DeleteEventFolder(tFilePath folder_path){
  try {
    std::filesystem::remove_all(folder_path);
  } catch (const std::filesystem::filesystem_error &e) {
    std::cerr << "Filesystem error: " << e.what() << '\n';
    return false;
  } catch (const std::exception &e) {
    std::cerr << "Standard exception: " << e.what() << '\n';
    return false;
  }
  return true;
}
