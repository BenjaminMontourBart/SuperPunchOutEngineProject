#pragma once
#include <string>

namespace Homer
{
    class ILogger
    {
    public:
        virtual void Log(std::string message) = 0;
    };
}