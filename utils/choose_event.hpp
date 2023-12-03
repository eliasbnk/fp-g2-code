#ifndef CHOOSE_EVENT_HPP
#define CHOOSE_EVENT_HPP

#include "../shared/system_libraries.hpp"
#include "../shared/types.hpp"

/**
 * @file event_finder.hpp
 *
 * This file contains functions for handling event .
 */

/**
 * @brief Handles event discovery and selection.
 *
 * Locates available event folders, displays them, and prompts for event selection.
 *
 * @return The path to the selected event folder or "exit."
 */
tString ChooseEvent(const tString &get_event_for);


#endif
