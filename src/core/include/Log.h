#pragma once

#include "../../gpch.h"

class GameLog
{
private:
    enum class LogLevel
    {
        NONE = 0,
        INFO, WARN, ERROR
    };
    LogLevel m_DefaultLogLevel;
public:
    GameLog() : m_DefaultLogLevel(LogLevel::NONE) {};
    void Info(const char* message);
};