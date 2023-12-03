#ifndef BOOKING_MENU_HPP
#define BOOKING_MENU_HPP

#include "../shared/system_libraries.hpp"
#include "../shared/types.hpp"
/**
 * @file booking_menu.hpp
 *
 * This file contains functions for managing event reservations.
 */

/**
 * @brief Manages event reservations.
 *
 * Guides users through booking event seats:
 * 1. Lists available events.
 * 2. Prompts for event selection.
 * 3. Handles seat selection and booking.
 * 4. Provides reservation details and tickets.
 * 5. Allows additional bookings.
 *
 * @note Assumes a valid data structure in data files.
 */
void EventBookingMenu();

#endif
