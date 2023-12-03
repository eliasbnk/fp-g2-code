#ifndef DATA_SAVER_HPP
#define DATA_SAVER_HPP

#include "../shared/system_libraries.hpp"
#include "../shared/types.hpp"

/**
 * @brief Modifies a cell within the data matrix and writes the updated data to a file.
 *
 * @param   data - The matrix to be modified.
 * @param  file_path - The file path where the updated data will be stored.
 * @param  selected_row - The index of the row to be modified.
 * @param  selected_col - The index of the column to be modified.
 * @param  new_value - The new value to be assigned to the specified cell.
 */

void UpdateAndSaveDataToFile(tStringMatrix &data,
                             const tString &file_path, const int &selected_row,
                             const int &selected_col, const tString &new_value);


#endif
