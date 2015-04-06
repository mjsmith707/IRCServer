//
//  Client.cpp
//  IRCServer
//
//  Created by Matt on 4/6/15.
//  Copyright (c) 2015 Matt. All rights reserved.
//

#include "Client.h"

Client::Client(Config*& config, Logger*& log, TCPSocket*& socket) : config(config), log(log), running(false), connthread(), socket(socket) {
}

Client::~Client() {
    if (socket != nullptr) {
        log->sendMsg("Closing connection to: " + socket->getForeignAddress());
        socket->send("goodbye", 7);
        delete socket;
    }
    running = false;
    if (connthread.joinable()) {
        connthread.join();
    }
}

void Client::threadmain() {
    running = true;
    try {
        log->sendMsg("New connection from: " + socket->getForeignAddress());
    }
    catch (SocketException e) {
        std::string err = "Client Error: ";
        err += e.what();
        log->sendMsg(err);
        running = false;
    }
    while (running) {
        
    }
}

void Client::writeSocket() {
    
}

void Client::readSocket() {
    
}

void Client::sendMsg(IRCMsg& msg) {
    
}

void Client::run() {
    connthread = std::thread(&Client::threadmain, this);
}