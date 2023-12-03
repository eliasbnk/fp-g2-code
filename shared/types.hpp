#ifndef TYPES_HPP
#define TYPES_HPP

/**
 * @file types.hpp
 * @brief Defines custom type aliases used throughout the project.
 */

#include "./system_libraries.hpp"

typedef std::vector<std::vector<std::string>> tStringMatrix;  /**< Type alias for a matrix of strings */
typedef std::vector<std::string> tStringVector;              /**< Type alias for a vector of strings */
typedef std::vector<int> tIntVector;                         /**< Type alias for a vector of integers */
typedef std::string tString;                                 /**< Type alias for a string */
typedef std::filesystem::path tFilePath;                    /**< Type alias for a file path */
typedef std::ofstream tOutputFile;                           /**< Type alias for an output file stream */
typedef std::ifstream tInputFile;                            /**< Type alias for an input file stream */
typedef std::invalid_argument tInvalidArgumentException;      /**< Type alias for an invalid argument exception */

#endif
