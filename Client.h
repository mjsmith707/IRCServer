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
#include <cstring>
#include "Socket.h"
#include "Shared_Queue.h"
#include "Config.h"
#include "Logger.h"
#include "IRCMsg.h"

class Client {
    typedef std::tuple<size_t, std::string> chatmsg;
    private:
        Config* config;
        Logger* log;
        std::thread connthread;
        Shared_Queue<chatmsg> msgQueue;
        std::atomic<bool> running;
        TCPSocket* socket;
        void writeSocket();
        void readSocket();
        void threadmain();
    public:
        Client(Config*&, Logger*&, TCPSocket*&);
        ~Client();
        void sendMsg(IRCMsg&);
        void run();
};

#endif /* defined(__IRCServer__Client__) */
