#ifndef CHOOSE_SEAT_HPP
#define CHOOSE_SEAT_HPP

#include "../../shared/system_libraries.hpp"
#include "../../shared/types.hpp"

void ChooseSeat(bool &booking_in_session, const tStringMatrix &venue_layout, const tStringMatrix &seat_prices, tStringMatrix &seat_availability, const tString &seats_availability_file, tStringMatrix &customer_info, const tString &customer_file, const tString &ticket_file,
tStringMatrix &issued_tickets, int selected_row, int selected_seat,
                bool &seats_are_full, const tIntVector &seating_capacity, const tString &event_name);

#endif
