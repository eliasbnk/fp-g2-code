#include "./choose_seat.hpp"
#include "../../shared/character_constants.hpp"
#include "../../shared/color_constants.hpp"
#include "../../utils/data_saver.hpp"
#include "../../utils/input_validator.hpp"
#include "../../utils/screen_cleaner.hpp"
#include "./ask_to_buy_another_seat/ask_to_buy_another_seat.hpp"
#include "./issue_ticket_number/issue_ticket_number.hpp"
#include "./save_customer_info/save_customer_info.hpp"

tString FormatLegendItem(const tString &item_color, const tString &item_name,
                         const tString &item_character,
                         bool last_item = false) {
  tString key_label = item_color + "(" + item_character + ") " + item_name +
                      kResetColor + (last_item ? "" : " - ");
  return key_label;
}

void DisplayMapLegend() {
  std::cout << "Legend: " << FormatLegendItem(kRedColor, "sold", kTakenSeatChar)
            << FormatLegendItem(kGreenColor, "available", kAvaliableSeatChar)
            << FormatLegendItem(kYellowColor, "your selection",
                                kSelectedSeatChar)
            << FormatLegendItem(kBlueColor, "row", kRowChar)
            << FormatLegendItem(kMagentaColor, "column", kColumnChar)
            << FormatLegendItem(kResetColor, "door", kDoorChar, true)
            << std::endl;
}

void DisplayVenueLayout(const tStringMatrix &venue_layout,
                        const tStringMatrix &seat_availability,
                        const tIntVector &seating_capacity,
                        const tString &event_name, int selected_row,
                        int selected_seat) {
  tStringMatrix layout_map = venue_layout;
  ClearScreen();
  std::cout << "Event: " << event_name << "\n\n";
  DisplayMapLegend();
  std::cout << "\n\n";
  std::cout << "Event seat map:\n\n";
  for (int row = 0; row < layout_map.size(); ++row) {
    for (int column = 0; column < layout_map[0].size(); ++column) {
      tString color_code;
      if (seat_availability[row][column] == kNotAvailable) {
        color_code = kResetColor;
        if (column == 0 && IsInputValidNumber(layout_map[row][0])) {
          color_code = kBlueColor;
        }
        if (row == 0 && IsInputValidNumber(layout_map[0][column])) {
          color_code = kMagentaColor;
        }
      }
      if (seat_availability[row][column] == kSold) {
        layout_map[row][column] = kTakenSeatChar;
        color_code = kRedColor;
      }
      if (seat_availability[row][column] == kAvailable) {
        layout_map[row][column] = kAvaliableSeatChar;
        color_code = kGreenColor;
      }
      if (row == selected_row && column == selected_seat) {
        layout_map[selected_row][selected_seat] = kSelectedSeatChar;
        color_code = kYellowColor;
      }

      std::cout << color_code << std::setw(seating_capacity[column])
                << layout_map[row][column] << kResetColor << " ";
    }
    std::cout << std::endl;
  }
}

bool HandleSoldOut(bool &seats_are_full) {
  if (seats_are_full) {
    std::cout << "\nSorry, the event/seat is sold out!" << std::endl;
    seats_are_full = false;
    return true;
  }
  return false;
}

bool IsSeat(const tStringMatrix &venue_layout, const int &row, int col = 1) {
  return venue_layout[row][col] == kSeatChar;
}

bool IsWithinValidRange(const int &input_value, const int &max_boundary) {

  return input_value > 0 && input_value < max_boundary;
}

bool IsSeatAvailable(const tStringMatrix &venue_layout,
                     const tStringMatrix &seat_availability, int row, int col) {
  return IsWithinValidRange(row, venue_layout.size()) &&
         IsWithinValidRange(col, venue_layout[0].size()) &&
         seat_availability[row][col] == kAvailable;
}

bool IsRowAvailable(const tStringMatrix &venue_layout,
                    const tStringMatrix &seat_availability, int row) {
  if (IsWithinValidRange(row, venue_layout.size())) {
    for (int col = 0; col < venue_layout[row].size(); col++) {
      if (IsSeat(venue_layout, row, col) &&
          seat_availability[row][col] == kAvailable) {
        return true;
      }
    }
  }
  return false;
}

void HandleSeatSelection(const tStringMatrix &venue_layout,
                         const tStringMatrix &seat_availability,
                         int &selected_row, int &selected_seat,
                         bool &seats_are_full) {
  bool seat_selection_complete = false;

  while (!seat_selection_complete && !seats_are_full) {
    int row = -1;
    while (true) {
      tString input_row = "";
      std::cout << "\nEnter your preferred " << kBlueColor << "row"
                << kResetColor << " number: ";
      std::getline(std::cin, input_row);
      if (IsInputValidNumberGreaterThanZero(input_row)) {
        row = std::stoi(input_row);
        if (IsWithinValidRange(row, venue_layout.size())) {
          if (IsSeat(venue_layout, row)) {
            if (IsRowAvailable(venue_layout, seat_availability, row)) {
              break;
            }
            std::cout << "\n"
                      << kBlueColor << "Row" << kResetColor << " is "
                      << kRedColor << "fully sold out" << kResetColor
                      << "! Please choose a different " << kBlueColor << "row"
                      << kResetColor << "." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            selected_row = -1;
            selected_seat = -1;
            seats_are_full = true;
            break;
          }

          std::cout << "\n"
                    << kBlueColor << "Row " << kResetColor << kYellowColor
                    << row << kResetColor << " is " << kRedColor
                    << "not available" << kResetColor
                    << "! Please choose a different " << kBlueColor << "row"
                    << kResetColor << "." << std::endl;
        } else {
          std::cout << "\nInvalid " << kBlueColor << "row" << kResetColor
                    << ". Please choose a " << kBlueColor << "row"
                    << kResetColor << " between 1 and "
                    << (venue_layout.size() - 1) << "." << std::endl;
        }
      } else {
        std::cout << "\nInvalid input. Please enter a valid " << kBlueColor
                  << "row" << kResetColor
                  << " number, "
                     "between 1 and "
                  << (venue_layout.size() - 1) << "." << std::endl;
      }
    }

    while (true && !seats_are_full) {
      tString input_col = "";

      std::cout << "\nEnter your preferred " << kMagentaColor << "column"
                << kResetColor << " number: ";
      std::getline(std::cin, input_col);

      if (IsInputValidNumberGreaterThanZero(input_col)) {
        int const col = std::stoi(input_col);
        if (IsSeat(venue_layout, row, col)) {
          if (IsWithinValidRange(col, venue_layout[0].size())) {
            if (IsSeatAvailable(venue_layout, seat_availability, row, col)) {
              selected_row = row;
              selected_seat = col;
              seat_selection_complete = true;
              break;
            }
            std::cout << "\nSeat is " << kRedColor << "sold out" << kResetColor
                      << "! Please choose a different " << kMagentaColor
                      << "column" << kResetColor << "." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            selected_row = -1;
            selected_seat = -1;
            seats_are_full = true;
          }
          std::cout << "\nInvalid seat. Please enter a valid " << kMagentaColor
                    << "column" << kResetColor
                    << " number, "
                       "between "
                    << kYellowColor << "1" << kResetColor << " and "
                    << kYellowColor << (venue_layout[0].size() - 1)
                    << kResetColor << "." << std::endl;
        } else {
          std::cout << "\n"
                    << kMagentaColor << "Column " << kResetColor << kYellowColor
                    << col << kResetColor << " is " << kRedColor
                    << "not available" << kResetColor
                    << "! Please choose a different " << kMagentaColor
                    << "column" << kResetColor << "." << std::endl;
        }
      } else {
        std::cout << "\nInvalid seat. Please enter a valid " << kMagentaColor
                  << "column" << kResetColor
                  << " number, "
                     "between "
                  << kYellowColor << "1" << kResetColor << " and "
                  << kYellowColor << (venue_layout[0].size() - 1) << kResetColor
                  << "." << std::endl;
      }
    }
  }
}

void ChooseSeat(bool &booking_in_session, const tStringMatrix &venue_layout,
                const tStringMatrix &seat_prices,
                tStringMatrix &seat_availability,
                const tString &seats_availability_file,
                tStringMatrix &customer_info, const tString &customer_file,
                const tString &ticket_file, tStringMatrix &issued_tickets,
                int selected_row, int selected_seat, bool &seats_are_full,
                const tIntVector &seating_capacity, const tString &event_name) {

  while (true) {
    selected_row = -1;
    selected_seat = -1;
    DisplayVenueLayout(venue_layout, seat_availability, seating_capacity,
                       event_name, selected_row, selected_seat);

    tString continue_prompt = "\nContinue? (" + kCyanColor + "y" + kResetColor +
                              "/" + kCyanColor + "n" + kResetColor + "): ";
    if (GetUserConfirmation(continue_prompt)) {
      booking_in_session = true;
    } else {
      booking_in_session = false;
      break;
    }

    HandleSeatSelection(venue_layout, seat_availability, selected_row,
                        selected_seat, seats_are_full);

    if (HandleSoldOut(seats_are_full)) {
      continue;
    }

    DisplayVenueLayout(venue_layout, seat_availability, seating_capacity,
                       event_name, selected_row, selected_seat);

    tString seat_prompt = "\nIs this the correct seat? (" + kCyanColor + "y" +
                          kResetColor + "/" + kCyanColor + "n" + kResetColor +
                          "): ";
    if (!GetUserConfirmation(seat_prompt) || seats_are_full) {
      continue;
    }

    if (!booking_in_session) {
      break;
    }

    std::cout << "\nThe selected seat at " << kBlueColor << "row "
              << kResetColor << kYellowColor << selected_row << kResetColor
              << kMagentaColor << " column " << kResetColor << kYellowColor
              << selected_seat << kResetColor << " costs $"
              << seat_prices[selected_row][selected_seat] << ".\n";

    tString price_prompt = "\nAre you okay with that price? (" + kCyanColor +
                           "y" + kResetColor + "/" + kCyanColor + "n" +
                           kResetColor + "): ";
    if (!GetUserConfirmation(price_prompt)) {
      continue;
    }
    UpdateAndSaveDataToFile(seat_availability, seats_availability_file,
                            selected_row, selected_seat, kSold);
    SaveCustomerInfo(customer_info, customer_file, selected_row, selected_seat);

    IssueTicketNumber(event_name, ticket_file, issued_tickets, selected_row,
                      selected_seat);

    if (!AskToBuyAnotherSeat()) {
      booking_in_session = false;
      break;
    }
  }
}
