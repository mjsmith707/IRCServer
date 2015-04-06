//
//  ConnectionHandler.h
//  IRCServer
//
//  Created by Matt on 4/6/15.
//  Copyright (c) 2015 Matt. All rights reserved.
//

#ifndef __IRCServer__ConnectionHandler__
#define __IRCServer__ConnectionHandler__

#include <set>
#include <thread>
#include <atomic>
#include "Config.h"
#include "Logger.h"
#include "Client.h"

class ConnectionHandler {
    private:
        Config* config;
        Logger* log;
        std::set<Client*> clients;
        std::thread listenthread;
        std::atomic<bool> running;
        void threadmain();
        void handleConnection(TCPSocket*);
    public:
        ConnectionHandler(Config*&, Logger*&);
        ~ConnectionHandler();
        void run();
        void closeConnection(Client*&);
};

#endif /* defined(__IRCServer__ConnectionHandler__) */
