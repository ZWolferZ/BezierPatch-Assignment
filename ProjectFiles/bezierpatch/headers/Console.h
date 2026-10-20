#ifndef CONSOLE_H
#define CONSOLE_H
// A class that makes a console so I can better test runtime stuff on windows so I dont explode.

#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#define OS_WINDOWS
#endif

// Make a console on windows
void CreateConsole();

#endif // CONSOLE_H