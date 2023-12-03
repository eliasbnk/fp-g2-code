#include "./screen_cleaner.hpp"


#ifdef _WIN32

void ClearScreen() {
  if (system("cls") != 0) {
    std::cerr << "Clearing the screen failed." << std::endl;
  }
}
#else

void ClearScreen() {
  if (system("clear") != 0) {
    std::cerr << "Clearing the screen failed." << std::endl;
  }
}
#endif
