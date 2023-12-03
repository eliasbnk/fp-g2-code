#ifndef EVENT_CREATOR_HPP
#define EVENT_CREATOR_HPP

#include "../../shared/system_libraries.hpp"
#include "../../shared/types.hpp"

/**
 * @brief Creates an event data folder with associated data files.
 *
 * @param  event_name - The name of the event.
 * @param  row_count - Number of venue rows.
 * @param  row_length - Length of each row.
 * @param  seats_between_walkways - Number of seats between vertical walkways.
 * @param  folder_path - The path to the event data folder.
 * @return True if the folder and data files are created successfully; otherwise, false.
 */


bool CreateEventDataFolder(const tString &event_name, const int &row_count,
 const int &row_length,
 const int &seats_between_walkways,
 const tFilePath &folder_path);


#endif

