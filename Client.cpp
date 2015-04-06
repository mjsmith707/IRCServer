//
//  Client.cpp
//  IRCServer
//
//  Created by Matt on 4/6/15.
//  Copyright (c) 2015 Matt. All rights reserved.
//

#include "Client.h"

Client::Client(size_t clientid, Config*& config, Logger*& log, TCPSocket*& socket, CommandHandler*& cmdhandler) : config(config), log(log), running(false), connthread(), socket(socket), cmdhandler(cmdhandler) {
}

Client::~Client() {
    running = false;
    if (connthread.joinable()) {
        connthread.join();
    }
}

void Client::threadmain() {
    running = true;
    try {
        log->sendMsg("New Connection From: " + socket->getForeignAddress());
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

size_t Client::getClientID() {
    return clientid;
}

void Client::writeSocket() {
    
}

void Client::readSocket() {
    
}

void Client::sendMsg() {
    
}

void Client::closeConnection() {
    
}

void Client::run() {
    connthread = std::thread(&Client::threadmain, this);
}