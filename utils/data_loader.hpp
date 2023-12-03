#ifndef DATA_LOADER_HPP
#define DATA_LOADER_HPP

#include "../shared/system_libraries.hpp"
#include "../shared/types.hpp"

/**
 * @brief Loads and processes data from a file into a matrix.
 *
 * @param  file_path - The path to the file to be read.
 * @return A matrix with the data from the file.
 */

bool LoadDataFromFile(const tString &file_path, tStringMatrix &data);

#endif
