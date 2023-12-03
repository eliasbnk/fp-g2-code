#ifndef GET_EVENT_NAME_HPP
#define GET_EVENT_NAME_HPP

#include "../shared/system_libraries.hpp"
#include "../shared/types.hpp"

tString GetEventName(const tString &event_folder_path);

tString ExtractEventName(const std::string &input);

#endif
