#include "./load_event_data.hpp"
#include "../../shared/color_constants.hpp"
#include "../../shared/file_constants.hpp"
#include "../../utils/choose_event.hpp"
#include "../../utils/data_loader.hpp"
#include "../../utils/get_event_name.hpp"

tIntVector CalculateColumnWidths(const tStringMatrix &venue_layout) {
  tIntVector max_column_width(venue_layout[0].size(), 0);

  for (int i = 0; i < venue_layout.size(); ++i) {
    for (int j = 0; j < venue_layout[i].size(); ++j) {
      max_column_width[j] = std::max(
          max_column_width[j], static_cast<int>(venue_layout[i][j].size()));
    }
  }

  return max_column_width;
}

bool LoadEventData(const tString &event_directory, tString &event_name,
                   tStringMatrix &venue_layout,
                   tStringMatrix &seat_availability, tStringMatrix &seat_prices,
                   tStringMatrix &customer_info, tStringMatrix &issued_tickets,
                   tIntVector &seating_capacity, tString &customer_file,
                   tString &seats_availability_file, tString &ticket_file) {
  if (event_directory == "file error" || event_directory == "no events") {
    std::cerr << kRedColor << "\nNo events found!" << kResetColor << std::endl;
    return false;
  } else if (event_directory == "exit") {
    return false;
  }

  event_name = GetEventName(event_directory);

  customer_file = event_directory + kNamesDataFile;
  seats_availability_file = event_directory + kSoldDataFile;
  const tString seat_file = event_directory + kSeatDataFile;
  const tString price_file = event_directory + kPriceDataFile;
  ticket_file = event_directory + kTicketDataFile;

  if (!LoadDataFromFile(seat_file, venue_layout)) {
    return false;
  }
  if (!LoadDataFromFile(seats_availability_file, seat_availability)) {
    return false;
  }
  if (!LoadDataFromFile(price_file, seat_prices)) {
    return false;
  }
  if (!LoadDataFromFile(customer_file, customer_info)) {
    return false;
  }
  if (!LoadDataFromFile(ticket_file, issued_tickets)) {
    return false;
  }

  seating_capacity = CalculateColumnWidths(venue_layout);

  return true;
}
