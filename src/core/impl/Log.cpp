#include "../include/Log.h"

void Log::Info(const char* message)
{
    std::cout << "[" << std::put_time(&tm, "%X") << "] " << message << '\n';
}

void Log::Warn(const char* message)
{
    std::cout << red << "[" << std::put_time(&tm, "%X") << "] " << message << '\n';
}