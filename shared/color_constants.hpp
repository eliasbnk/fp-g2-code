#ifndef COLOR_CONSTANTS_HPP
#define COLOR_CONSTANTS_HPP

#include "./system_libraries.hpp"
#include "./types.hpp"

/**
 * @file color_constants.hpp
 * @brief Constants for ANSI terminal text colors.
 */

const tString kResetColor = "\033[0;0m";      /**< Reset color to default */
const tString kRedColor = "\033[0;31m";       /**< Red text color */
const tString kGreenColor = "\033[0;32m";     /**< Green text color */
const tString kYellowColor = "\033[0;93m";    /**< Yellow text color */
const tString kBlueColor = "\033[0;34m";      /**< Blue text color */
const tString kMagentaColor = "\033[0;95m";   /**< Magenta text color */
const tString kCyanColor = "\033[0;96m";      /**< Cyan text color */

#endif
