#include "Console.h"
#include "Windows.h"

Homer::Console::~Console()
{
	FreeConsole();
}

void Homer::Console::Log(std::string message)
{
}

Homer::Console::Console()
{
	AllocConsole();
}
