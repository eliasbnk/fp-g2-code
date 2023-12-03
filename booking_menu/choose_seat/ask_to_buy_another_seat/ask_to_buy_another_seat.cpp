#include "../../../utils/input_validator.hpp"
#include "../../../shared/color_constants.hpp"
#include "./ask_to_buy_another_seat.hpp"

bool AskToBuyAnotherSeat()
{
    tString finished_prompt = "\nWould you like to buy another seat? (" +
                              kCyanColor + "y" + kResetColor + "/" +
                              kCyanColor + "n" + kResetColor + "): ";
    return GetUserConfirmation(finished_prompt);
}
