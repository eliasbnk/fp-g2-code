#ifndef FILE_CONSTANTS_HPP
#define FILE_CONSTANTS_HPP

#include "./system_libraries.hpp"
#include "./types.hpp"

/**
 * @file file_constants.hpp
 * @brief Constants for file names and directories related to event data.
 */

const tString kSeatDataFile = "map_data.txt";     /**< File for venue layout data */
const tString kSoldDataFile = "sold_data.txt";    /**< File for seat availability data */
const tString kPriceDataFile = "price_data.txt";  /**< File for seat price data */
const tString kNamesDataFile = "names_data.txt";  /**< File for booker names data */
const tString kTicketDataFile = "ticket_data.txt"; /**< File for ticket numbers data */
const tString kChekedInDataFile = "check_in_data.txt"; /**< File for keeping track of who came to event */
const tString kParentDirectory = "./event_data/"; /**< Parent directory for event data */

#endif
