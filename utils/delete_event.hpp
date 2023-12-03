#ifndef DELETE_FOLDER_HPP
#define DELETE_FOLDER_HPP

#include "../shared/system_libraries.hpp"
#include "../shared/types.hpp"

/**
 * @brief Delete an event folder and its contents.
 *
 * @param folder_path The path to the event folder to be deleted.
 * @return True if the folder and its contents were successfully deleted, false otherwise.
 */
bool DeleteEventFolder(tFilePath folder_path);

#endif
