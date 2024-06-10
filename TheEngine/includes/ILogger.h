#pragma once
#include <string>
class ILogger
{
public:
    virtual void Log(std::string message) = 0;
};