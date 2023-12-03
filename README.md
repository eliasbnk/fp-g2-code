# README

## Naming Conventions

### Crucial Constants
- **Convention**: CamelCase
- **Prefix**: 'k'
- **Example**: `kVariableName`
- **Location**: Shared directory

### Reusable Types
- **Convention**: CamelCase
- **Prefix**: 't'
- **Example**: `tStringVector`
- **Location**: Shared directory/types.hpp

### Regular Variables
- **Convention**: snake_case
- **Example**: `variable_name`
- **Clarity**: Use clear, descriptive names.

***including regular constant variables***

### Functions/Modules

- **Convention**: PascalCase
- **Explanation**: First word describes action.
- **Examples**: `GetVenueSize`, `Get`, `Draw`, `Print`, `Create`, `Generate`, `Validate`, etc.

- **Boolean Functions**: Start with 'Is', framed as questions.
- **Example**: `IsValidNumber` (returns true/false)

## Directory Structure

- **Booking Menu**: Code related to booking menu.
- **Creator Menu**: Code for event creation menu.
- **Utils**: Functions shared across the project.
- **Shared**: Shared key data.
- **Event Data**: Data for events:
  - `map_data`: Venue seating info
  - `name_data`: Bookers' names
  - `price_data`: Seat prices
  - `ticket_data`: Bookers' ticket numbers
