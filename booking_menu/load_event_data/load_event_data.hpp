#ifndef LOAD_EVENT_DATA_HPP
#define LOAD_EVENT_DATA_HPP

#include "../../shared/system_libraries.hpp"
#include "../../shared/types.hpp"

bool LoadEventData(const tString &event_directory, tString &event_name, tStringMatrix &venue_layout,
                   tStringMatrix &seat_availability, tStringMatrix &seat_prices, tStringMatrix &customer_info,
                   tStringMatrix &issued_tickets, tIntVector &seating_capacity, tString &customer_file, tString &seats_availability_file, tString &ticket_file);

#endif
