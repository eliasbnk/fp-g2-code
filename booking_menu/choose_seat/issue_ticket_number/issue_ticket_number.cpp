
#include "./issue_ticket_number.hpp"
#include "../../.././utils/data_saver.hpp"
#include "../../.././utils/ticket_finder.hpp"
#include "../../.././shared/color_constants.hpp"

tString GenerateRandomTicketId(const int &id_length)
{
    const tString characters =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 generator(
        std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(0, characters.size() - 1);

    tString random_id;
    for (int i = 0; i < id_length; ++i)
    {
        random_id += characters[distribution(generator)];
    }

    return random_id;
}

tString GenerateTicketNumber(const tString &event_name, const int &selected_row,
                             const int &selected_col,
                             const int &random_id_length = 4)
{
    tString ticket;
    tString ticketEventName = event_name;

    for (size_t i = 0; i < event_name.length(); i++)
    {
        if (ticketEventName[i] == ' ')
        {
            ticketEventName[i] = '-';
        }
    }

    ticket += ticketEventName + "-";
    ticket += std::to_string(selected_row) + "-";
    ticket += std::to_string(selected_col) + "-";
    ticket += GenerateRandomTicketId(random_id_length);
    return ticket;
}

void DisplayTicketNumber(const tString &ticket)
{
    std::cout << "\nYour ticket number is: " << kYellowColor << ticket
              << kResetColor << "\n";
    std::cout << "\nMake sure to write it down.\n";
    std::cout
        << "\nYou will need to present this number to get into your event.\n";
}

void IssueTicketNumber(const tString &event_name, const tString &ticket_file,
                       tStringMatrix &issued_tickets, int selected_row, int selected_seat)
{
    tString ticket_number;
    do
    {
        ticket_number = GenerateTicketNumber(event_name, selected_row, selected_seat);
    } while (WasTicketNumberIssued(issued_tickets, ticket_number));

    UpdateAndSaveDataToFile(issued_tickets, ticket_file, selected_row,
                            selected_seat, ticket_number);

    std::cout << "\nThank you for booking a seat at " << kBlueColor << "row "
              << kResetColor << kYellowColor << selected_row << kResetColor
              << kMagentaColor << " column " << kResetColor << kYellowColor
              << selected_seat << kResetColor << ".\n";
    DisplayTicketNumber(ticket_number);
}
