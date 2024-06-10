#pragma once
#include "ILogger.h"

class Console: public ILogger
{
public:

	Console();
	~Console();

	void Log(std::string message);
};