#ifndef GENERATE_PRICE_DATA_HPP
#define GENERATE_PRICE_DATA_HPP

#include "../../../shared/system_libraries.hpp"
#include "../../../shared/types.hpp"

void GeneratePriceData(tOutputFile &output_file, int row_count, int row_length,
                       int even_section_distribution,
                       int seats_between_walkway);

#endif
