#include "./booking_menu.hpp"
#include "../shared/color_constants.hpp"
#include "../utils/choose_event.hpp"
#include "./choose_seat/choose_seat.hpp"
#include "./load_event_data/load_event_data.hpp"

void EventBookingMenu() {
  while (true) {
    const tString event_directory = ChooseEvent("booking");

    if (event_directory == "file error" || event_directory == "no events") {
      break;
    } else if (event_directory == "exit") {
      break;
    }

    tString event_name, customer_file, seats_availability_file, ticket_file;
    tStringMatrix venue_layout, seat_availability, seat_prices, customer_info,
        issued_tickets;
    tIntVector seating_capacity;

    if (!LoadEventData(event_directory, event_name, venue_layout,
                       seat_availability, seat_prices, customer_info,
                       issued_tickets, seating_capacity, customer_file,
                       seats_availability_file, ticket_file)) {
      std::cerr << "Error loading event data" << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      break;
    }

    bool booking_in_session = false;
    bool seats_are_full = false;

    while (true) {
      int selected_row = -1;
      int selected_seat = -1;

      ChooseSeat(booking_in_session, venue_layout, seat_prices,
                 seat_availability, seats_availability_file, customer_info,
                 customer_file, ticket_file, issued_tickets, selected_row,
                 selected_seat, seats_are_full, seating_capacity, event_name);
      if (!booking_in_session || seats_are_full) {
        break;
      }
    }
  }
}
