#ifndef GENERATE_CHECK_IN_DATA_HPP
#define GENERATE_CHECK_IN_DATA_HPP

#include "../../../shared/system_libraries.hpp"
#include "../../../shared/types.hpp"

void GenerateChekedInData(tOutputFile &output_file, const int row_count,
                          const int row_length,
                          const int even_section_distribution,
                          const int seats_between_walkway);

#endif
