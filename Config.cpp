#include "Config.h"

Config::Config(int& argc, char**& argv, std::string cfgFile) {
    Debug = true;
    Daemon = false;
    Port = 6112;
    ListenAddress = "0.0.0.0";
    LogFile = "irc-srv.log";
    ConfigFile = "irc-srv.conf";

    std::vector<std::string> parameters;
    for (int i=1; i<argc; i++) {
        std::string param = "";
        param += argv[i];
        parameters.push_back(param);
    }

    Config::readConfigFile(cfgFile);
    // readParams when finished..
}

Config::Config(std::string cfgFile) {
    Debug = true;
    Daemon = false;
    Port = 6112;
    ListenAddress = "0.0.0.0";
    LogFile = "./irc-srv.log";
    ConfigFile = cfgFile;

    Config::readConfigFile(cfgFile);
}

void Config::readConfigFile(std::string fileName) {
    int lineNum = 0;
    try {
        std::fstream cfgFile;
        cfgFile.open(fileName.c_str(), std::fstream::in);
        if (!cfgFile.is_open())
        {
            throw std::runtime_error(std::string("Failed to open configuration file: " + ConfigFile));
        }

        // Pretty slacker way to do this without resorting to a real parser.
        // Also getline cannot handle non-unix newlines properly on a nix platform...
        do {
            lineNum++;
            std::string param = "";
            std::getline(cfgFile,param);
            if (param.find("=") == std::string::npos) {
                if (param.length() == 0) {
                    continue;
                }
                throw std::runtime_error(std::string("Failed to parse config file at line " + std::to_string(lineNum)));
                return;
            }
            std::string token = param.substr(0,param.find("="));
            std::string val = param.substr(param.find("=")+1, param.length()-1);
            if (token.compare("Debug") == 0) {
                if (val.compare("true") == 0) {
                    Debug = true;
                }
                else if (val.compare("false") == 0) {
                    Debug = false;
                }
                else {
                    throw std::runtime_error(std::string("Failed to parse config file at line " + std::to_string(lineNum)));
                }
            }
            else if (token.compare("Daemon") == 0) {
                if (val.compare("true") == 0) {
                    Daemon = true;
                }
                else if (val.compare("false") == 0) {
                    Daemon = false;
                }
                else {
                    throw std::runtime_error(std::string("Failed to parse config file at line " + std::to_string(lineNum)));
                }
            }
            else if (token.compare("Port") == 0) {
                Port = std::stoi(val);
            }
            else if (token.compare("ListenAddress") == 0) {
                ListenAddress = val;
            }
            else if (token.compare("LogFile") == 0) {
                LogFile = val;
            }
            else {
                throw std::runtime_error(std::string("Failed to parse config file at line " + std::to_string(lineNum)));
            }
        } while (!cfgFile.eof());
        cfgFile.close();
    }
    catch (std::runtime_error e) {
            std::cout << e.what() << std::endl;
    }
}

// Parses command line parameters for saving into config.
// Put it on the todo list for uhhhh later.
void Config::readParameters(std::vector<std::string> parameters) {
    // This is really low priority
}

void Config::reloadConfig() {
    readConfigFile(getConfigFile());
}

bool Config::getDebug() {
    return Debug;
}

bool Config::getDaemon() {
    return Daemon;
}

unsigned int Config::getPort() {
    return Port;
}

std::string Config::getListenAddress() {
    return ListenAddress;
}

std::string Config::getLogFile() {
    return LogFile;
}

std::string Config::getConfigFile() {
    return ConfigFile;
}

void Config::setDebug(bool val) {
    if (!Daemon) {
        Debug = val;
    }
}

void Config::setDaemon(bool val) {
    if (!Debug) {
        Daemon = val;
    }
}

void Config::setPort(unsigned int val) {
    Port = val;
}

void Config::setListenAddress(std::string address) {
    ListenAddress = address;
}

void Config::setLogFile(std::string logFile) {
    LogFile = logFile;
}

void Config::setConfigFile(std::string cfgFile) {
    ConfigFile = cfgFile;
}
