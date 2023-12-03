# README

# Ticket Booker Application

## Introduction

The Ticket Booker Application is a command-line application that enables customers to book tickets for events and event managers to create new events. This documentation provides an overview of the application's functionality, code structure, and usage.

## Key Features

- Booking tickets for events.
- Creating new events with customizable seating arrangements.
- Managing ticket data and event information.

## Usage

To use the Ticket Booker Application, you have two options:

1. **Online Version**: Visit our online version at [Ticket Booker on Replit](https://replit.com/@eliasbnk/fp-g2s).

2. **Download and Run Locally**:
   - Download the source code from [GitHub](https://github.com/eliasbnk/fp-g2s/archive/refs/heads/main.zip).
   - Unzip the downloaded file.
   - Ensure your compiler is using **C++ version 17 or higher**.
   - Compile and run the application.

**Warning**: If you download the source code, ensure that your compiler is using **C++ version 17 or higher**, or the application will not function correctly.


## Authors

- ROBERT MURDOCH
- SYED SHAH
- TSELMEN ANUURAD
- IVAN BENEDYCHUK
- JACOB JACKMAN
- ILYA BABENKO

## License

This project is licensed under the GNU Affero General Public License (AGPL). See the LICENSE file for details.

---

# Naming Conventions

## Crucial Constants

- **Convention**: CamelCase
- **Prefix**: 'k'
- **Example**: `kVariableName`
- **Location**: Shared directory

## Reusable Types

- **Convention**: CamelCase
- **Prefix**: 't'
- **Example**: `tStringVector`
- **Location**: Shared directory/types.hpp

## Regular Variables

- **Convention**: snake_case
- **Example**: `variable_name`
- **Clarity**: Use clear, descriptive names.
- *Including regular constant variables*

## Functions/Modules

- **Convention**: PascalCase
- **Explanation**: First word describes action.
- **Examples**: `GetVenueSize`, `Get`, `Draw`, `Print`, `Create`, `Generate`, `Validate`, etc.
- **Boolean Functions**: Start with 'Is', framed as questions.
- **Example**: `IsValidNumber` (returns true/false)

# Directory Structure

- **Booking Menu**: Code related to booking menu.
- **Creator Menu**: Code for event creation menu.
- **Utils**: Functions shared across the project.
- **Shared**: Shared key data.
- **Event Data**: Data for events:
  - `check_in_data`: Holds attendee info
  - `sold_data`: Holds seat status
  - `map_data`: Venue seating info
  - `name_data`: Bookers' names
  - `price_data`: Seat prices
  - `ticket_data`: Bookers' ticket numbers
