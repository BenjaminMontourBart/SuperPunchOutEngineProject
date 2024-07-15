#pragma once
#include "ILogger.h"

namespace Homer
{
	class Console : public ILogger
	{
	public:

		Console();
		~Console();

		void Log(std::string message);
	};
}