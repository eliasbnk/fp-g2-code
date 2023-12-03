#ifndef DELETE_EVENT_MENU_HPP
#define DELETE_EVENT_MENU_HPP

#include "../shared/system_libraries.hpp"
/**
 * @brief Delete an existing event folder.
 *
 * Allows users to choose an event folder and confirm deletion. If the folder exists,
 * it asks for confirmation and provides a second confirmation for irreversible deletion.
 * Users can choose to proceed with caution or cancel the deletion. If the folder is deleted
 * successfully, it displays a success message.
 */
void DeleteEventMenu();

#endif
