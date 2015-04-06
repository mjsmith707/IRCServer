// Holds all configuration data as read from a file specified in the ctor

#ifndef CONFIG_H_
#define CONFIG_H_
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <mutex>

class Config {
    private:
    bool Debug;
    bool Daemon;
    unsigned int Port;
    std::string ListenAddress;
    std::string LogFile;
    std::string ConfigFile;

    void readConfigFile(std::string fileName);
    void readParameters(std::vector<std::string> parameters);

    public:
    Config(int& argc, char**& argv, std::string cfgFile);
    Config(std::string cfgFile);
    void reloadConfig();
    bool getDebug();
    bool getDaemon();
    unsigned int getPort();
    std::string getListenAddress();
    std::string getLogFile();
    std::string getConfigFile();
    void setDebug(bool val);
    void setDaemon(bool val);
    void setPort(unsigned int val);
    void setListenAddress(std::string address);
    void setLogFile(std::string logFile);
    void setConfigFile(std::string cfgFile);
};

#endif
