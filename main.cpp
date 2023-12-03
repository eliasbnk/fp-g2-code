
#include "./main_menu/main_menu.hpp"
#include "./shared/system_libraries.hpp"
#include "./utils/startup_loader.hpp"
/**
 * @mainpage Ticket Booker Application
 *
 * @section intro Introduction
 *
 * The Ticket Booker Application is a command-line application that enables
 * customers to book tickets for events and event managers to create new events.
 * This documentation provides an overview of the application's functionality,
 * code structure, and usage.
 *
 * @section features Key Features
 *
 * - Booking tickets for events.
 * - Creating new events with customizable seating arrangements.
 * - Managing ticket data and event information.
 *
 * @section usage Usage
 *
 * To use the Ticket Booker Application, visit our online version: [Ticket
 * Booker on Replit](https://replit.com/@eliasbnk/fp-g2s).
 * @warning If you download the source code, ensure that your compiler is using
 * **C++ version 17 or higher**, or the application will not function correctly.
 *
 * @section authors Authors
 *
 * - ROBERT MURDOCH
 * - SYED SHAH
 * - TSELMEN ANUURAD
 * - IVAN BENEDYCHUK
 * - JACOB JACKMAN
 * - ILYA BABENKO
 *
 * @section license License
 *
 * This project is licensed under the GNU Affero General Public License (AGPL).
 * See the LICENSE file for details.
 */

/**
 * @brief Main menu for the Ticket Booker app.
 */

int main()
{
  StartUpLoader();
  MainMenu();
  return 0;
}
