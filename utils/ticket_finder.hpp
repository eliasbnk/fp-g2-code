#ifndef TICKET_FINDER_HPP
#define TICKET_FINDER_HPP

#include "../shared/system_libraries.hpp"
#include "../shared/types.hpp"

/**
 * @brief Checks if a ticket number exists in the event's ticket data and returns its seat location.
 *
 * @param  ticket_data - The matrix containing the event's ticket data.
 * @param  ticket_number - The ticket number to look for.
 * @param  found_row - The row index where the ticket number is found.
 * @param  found_col - The column index where the ticket number is found.
 *
 * @return True if the ticket number is found; false otherwise.
 */

bool WasTicketNumberIssuedGetLocation(const tStringMatrix &ticket_data, const tString &ticket_number, int *row_ptr = nullptr, int *col_ptr = nullptr);

/**
 * @brief Checks if a ticket number exists in the event's ticket data.
 *
 * @param  ticket_data - The matrix containing the event's ticket data.
 * @param  ticket_number - The ticket number to look for.
 *
 * @return True if the ticket number is found, false otherwise.
 */
bool WasTicketNumberIssued(const tStringMatrix &ticket_data,
                         const tString &ticket_number);

/**
 * @brief Prompts the user to input a ticket number.
 *
 * @param  prompt - The prompt message.
 *
 * @return The entered ticket number.
 */
tString GetTicketNumber(const tString &prompt = "\nEnter your ticket number: ");

#endif
