#pragma once

#include <iomanip>
#include <iostream>
#include <ctime>

class Log
{
private:
    enum class LogLevel
    {
        NONE = 0,
        INFO, WARN, ERROR
    };

    LogLevel m_DefaultLogLevel;
    static Log* m_Log;
private:
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
private:
    std::string red;
public:
    Log() : m_DefaultLogLevel(LogLevel::NONE), red("\033[0;31m") {};

    static Log* GetLogInstance() { return m_Log; }

    void Info(const char* message);
    void Warn(const char* message);
    void Assert();
};