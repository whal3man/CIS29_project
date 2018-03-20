#include "../include/Commands.h"

#ifdef _WIN32
std::string clsCommand = "cls";
#else
std::string clsCommand = "clear";
#endif

#ifdef _WIN32
std::string pauseCommand = "pause";
#else
std::string pauseCommand = "read -n 1 -s -p \"Press any key to continue...\"; echo";
#endif
