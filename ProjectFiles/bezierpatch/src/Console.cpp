#include "Console.h"


void CreateConsole()
{
#ifdef OS_WINDOWS
	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);
	freopen_s(&fp, "CONIN$", "r", stdin);

	std::ios::sync_with_stdio();

#endif
	std::cout << "Console Created or Present Already!" << std::endl;
}
