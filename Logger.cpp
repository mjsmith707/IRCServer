#include "Logger.h"

Logger::Logger(Config* configuration) {
    runningConfig = configuration;
    running = false;
}

void Logger::run() {
    running = true;
    while (running) {
        try {
            std::lock_guard<std::mutex> lock(msgMute);
            while (!messageList.empty()) {
                if (runningConfig->getDaemon()) {
                    if (!writeMsg(messageList.front())) {
                        // If we've failed to write over 200 messages
                        // Flush the queue and hope next time goes better
                        if (messageList.size() > 200) {
                            while (!messageList.empty()) {
                                messageList.pop();
                            }
                        }
                        break;
                    }
                    messageList.pop();
                }
                else {
                    printMsg(messageList.front());
                    if (!writeMsg(messageList.front())) {
                        // If we've failed to write over 200 messages
                        // Flush the queue and hope next time goes better
                        if (messageList.size() > 200) {
                            while (!messageList.empty()) {
                                messageList.pop();
                            }
                        }
                        break;
                    }
                    messageList.pop();
                }
            }
        }
        catch (std::exception e) {
            if (!runningConfig->getDaemon()) {
                std::cerr << "Logging thread exited unexpectedly. Error: " << e.what() << std::endl;
            }
            running = false;
            return;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    // Flush remaining messages.
    try {
        std::lock_guard<std::mutex> lock(msgMute);
        while (!messageList.empty()) {
            printMsg(messageList.front());
            writeMsg(messageList.front());
            messageList.pop();
        }
    }
    catch (std::exception e) {
        if (!runningConfig->getDaemon()) {
            std::cerr << "Logging thread exited unexpectedly. Error: " << e.what() << std::endl;
        }
        running = false;
        return;
    }
    std::string thread_end = "Logging thread stopped";
    printMsg(thread_end);
    writeMsg(thread_end);
    running = false;
}

void Logger::stop() {
    running = false;
}

Config* Logger::getConfig() {
    return runningConfig;
}

void Logger::setConfig(Config* configuration) {
    runningConfig = configuration;
}



void Logger::sendMsg(std::string message) {
	std::lock_guard<std::mutex> lock(msgMute);
	messageList.push(message);
}

bool Logger::writeMsg(std::string& message) {
    std::string logPath = runningConfig->getLogFile();
    try {
        std::ofstream logFile;
        logFile.open(logPath.c_str(), std::fstream::app);
        if (!logFile.is_open()) {
            logFile.open(logPath.c_str(), std::fstream::out);
            if (!logFile.is_open()) {
                throw std::runtime_error("Failed to create log file.");
            }
        }
        time(&unixTime);
        localTime = localtime(&unixTime);
        std::string logtime = asctime(localTime);
        logtime.erase(logtime.length()-1, 1);
        logFile << "[" << logtime << "] " << message << std::endl;
        logFile.flush();
        logFile.close();
    }
    catch (std::runtime_error e) {
        if (!runningConfig->getDaemon()) {
            //std::cerr << "ERROR: " << e.what() << std::cerr;
        }
        return false;
    }
    return true;
}

void Logger::printMsg(std::string& message) {
    if (runningConfig->getDaemon()) {
        return;
    }

    if (runningConfig->getDebug()) {
        std::cout << "DEBUG: " << message << std::endl;
    }
}
