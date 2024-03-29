// Provides timestamped logging to a file specified by the runningConfig
// as well as console output if Debug=true
// The only thing you want to use from here is sendMsg(printfFormatString, params...)

#ifndef LOGGER_H_
#define LOGGER_H_
#include <atomic>
#include <thread>
#include <chrono>
#include <queue>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <cstdarg>
#include <ctime>
#include <mutex>
#include <memory>
#include "Config.h"

class Logger {
    private:
    Config* runningConfig;
    time_t unixTime;
    struct tm* localTime;
    std::atomic<bool> running;
    std::mutex msgMute;
    std::queue<std::string> messageList;

    bool writeMsg(std::string& message);
    void printMsg(std::string& message);

    std::string doubleToString(double& val);
    std::string intToString(int& val);
    std::string uintToString(unsigned int& val);
    std::string longToString(long& val);

    public:
    Logger(Config* configuration);
    void run();
    void stop();
    Config* getConfig();
    void setConfig(Config* configuration);
    //void sendMsg(const char* strFormat, ...);
    void sendMsg(std::string message);
};

#endif
