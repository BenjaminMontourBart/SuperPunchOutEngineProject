#include "Console.h"
#include "Windows.h"

Console::~Console()
{
	FreeConsole();
}

void Console::Log(std::string message)
{
}

Console::Console()
{
	AllocConsole();
}
