#ifndef ISSUE_TICKET_NUMBER_HPP
#define ISSUE_TICKET_NUMBER_HPP

#include "../../../shared/system_libraries.hpp"
#include "../../../shared/types.hpp"

void IssueTicketNumber(const tString &event_name, const tString &ticket_file,
                       tStringMatrix &issued_tickets, int selected_row, int selected_seat);

#endif



