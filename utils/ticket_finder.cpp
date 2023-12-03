#include "./ticket_finder.hpp"

tString GetTicketNumber(const tString &prompt) {
  tString ticket_number;
  std::cout << prompt;
  std::getline(std::cin, ticket_number);
  return ticket_number;
}

bool WasTicketNumberIssued(const tStringMatrix &ticket_data,
                           const tString &ticket_number) {

  for (int row = 0; row < ticket_data.size(); row++) {
    for (int col = 0; col < ticket_data[row].size(); col++) {
      if (ticket_data[row][col] == ticket_number) {
        return true;
      }
    }
  }
  return false;
}

bool WasTicketNumberIssuedGetLocation(const tStringMatrix &ticket_data,
                                      const tString &ticket_number,
                                      int *row_ptr, int *col_ptr) {

  for (int row = 0; row < ticket_data.size(); row++) {
    for (int col = 0; col < ticket_data[row].size(); col++) {
      if (ticket_data[row][col] == ticket_number) {
        *row_ptr = row;
        *col_ptr = col;
        return true;
      }
    }
  }
  return false;
}
