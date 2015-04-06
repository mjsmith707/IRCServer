//
//  Client.h
//  IRCServer
//
//  Created by Matt on 4/6/15.
//  Copyright (c) 2015 Matt. All rights reserved.
//

#ifndef __IRCServer__Client__
#define __IRCServer__Client__

#include <thread>
#include <atomic>
#include "Socket.h"
#include "Shared_Queue.h"
#include "Config.h"
#include "Logger.h"
#include "CommandHandler.h"

class Client {
    private:
        Config* config;
        Logger* log;
        std::thread connthread;
        Shared_Queue msgQueue;
        std::atomic<bool> running;
        TCPSocket* socket;
        CommandHandler* cmdhandler;
        size_t clientid;
        void writeSocket();
        void readSocket();
        void threadmain();
    public:
        Client(size_t, Config*&, Logger*&, TCPSocket*&, CommandHandler*&);
        ~Client();
    size_t getClientID();
        void sendMsg();
        void closeConnection();
        void run();
};

#endif /* defined(__IRCServer__Client__) */
