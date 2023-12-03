#ifndef CHARACTER_CONSTANTS_HPP
#define CHARACTER_CONSTANTS_HPP

#include "./system_libraries.hpp"
#include "./types.hpp"

/**
 * @file character_constants.hpp
 * @brief Constants for character representations.
 */

// Constants for character representations
const tString kSold = "s";                      /**< Sold seat */
const tString kAvailable = "a";                 /**< Available seat */
const tString kNotAvailable = "na";             /**< Not available seat */
const tString kNotAvailableComma = "na,";       /**< The first seat is not available */
const tString kNotCheckedIn = "no"; 
const tString kCheckedIn = "yes";
const tString kPriceNotAvailable = "-1";         /**< Price for not a seat element */
const tString kPriceNotAvailableComma = "-1,";  /**< The price for the first not a seat element */
const tString kDoor = "door";                   /**< Door */
const tString kSeat = "seat";                   /**< Seat */
const tString kWalkway = "walk";               /**< Walkway */
const tString kDoorChar = "H";                  /**< Door character */
const tString kSeatChar = "#";                  /**< Seat character */
const tString kAvaliableSeatChar = "O";         /**< Available seat character */
const tString kTakenSeatChar = "Ø";             /**< Taken seat character */
const tString kSelectedSeatChar = "X";          /**< Selected seat character */
const tString kWalkwayChar = " ";               /**< Walkway character */
const tString kEmpty = " ";                     /**< Empty space character */
const tString kRowChar = "↕";                   /**< Row character */
const tString kColumnChar = "↔";                /**< Column character */
const char kSeparatorChar = ',';                /**< Data separator character */
const char kSpinnerChar = '*';
const char kSpinnerBackgroundChar = '-';

#endif
