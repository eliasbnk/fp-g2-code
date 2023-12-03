#ifndef INPUT_VALIDATOR_HPP
#define INPUT_VALIDATOR_HPP

#include "../shared/system_libraries.hpp"
#include "../shared/types.hpp"

/**
 * @defgroup InputValidation Input Validation
 * @brief Functions for validating user input.
 */

/**
 * @ingroup InputValidation
 * @brief Validates and processes yes/no input from the user.
 *
 * @param  prompt - The message displayed to the user as a prompt.
 *
 * Prompts the user for a yes/no response and validates the input.
 * It accepts variations such as 'Y', 'YES', 'N', and 'NO' (case-insensitive).
 *
 * @return 'Y' if the user enters 'Y' or 'YES', 'N' if the user enters 'N' or 'NO'.
 */
bool GetUserConfirmation(const tString &prompt);

/**
 * @ingroup InputValidation
 * @brief Verifies if a string follows a valid name format.
 *
 * @param  input - The input string to be validated.
 *
 * @return True if the input is in valid name format, otherwise false.
 */
bool IsInputValidName(const tString &input);

/**
 * @ingroup InputValidation
 * @brief Checks if a string contains only alphabetic characters.
 *
 * @param  input  - The input string to be validated.
 *
 * @return True if the input consists of only alphabetic characters, otherwise false.
 */
bool IsInputValidAlpha(const tString &input);

/**
 * @ingroup InputValidation
 * @brief Checks if a string contains only numeric digits.
 *
 * @param  input - The input string to be validated.
 *
 * @return True if the input string consists of only numeric digits, otherwise false.
 */
bool IsInputValidNumber(const tString &input);

/**
 * @ingroup InputValidation
 * @brief Checks if a string is a valid positive integer.
 *
 * @param  input - The input string to be validated.
 *
 * @return True if the input is a valid positive integer, otherwise false.
 */
bool IsInputValidNumberGreaterThanZero(const tString &input);

bool PromptRetry();

#endif
