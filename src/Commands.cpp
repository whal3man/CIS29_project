#include "../include/Commands.h"
#include <string>
using namespace std;

#ifdef _WIN32
string clsCommand = "cls";
#else
string clsCommand = "clear";
#endif

#ifdef _WIN32
string pauseCommand = "pause";
#else
string pauseCommand = "read -n 1 -s -p \"Press any key to continue...\"; echo";
#endif
