#ifndef DATA_GENERATOR_HPP
#define DATA_GENERATOR_HPP

#include "../../shared/system_libraries.hpp"
#include "../../shared/types.hpp"


/**
 * @brief Generates event-related data files with proper data formatting.
 *
 * @param  output_file - The data file to which the data is written.
 * @param  file_name - The name of the data file.
 * @param  row_count - Number of venue rows.
 * @param  row_length - Length of each row.
 * @param  seats_between_walkway -  Number of seats between vertical walkways.
 */


void GenerateDataFile(tOutputFile &output_file, tString file_path,
                      int row_count, int row_length,
                      int seats_between_walkway);


/**
 * @brief Guides the user to set venue size parameters.
 *
 * @param  row_count - Number of venue rows.
 * @param  row_length - Length of each row.
 * @param  seats_between_walkway - Number of seats between vertical walkways.
 */
void GetVenueSize(int &row_count, int &row_length,
                  int &seats_between_walkway);

#endif
