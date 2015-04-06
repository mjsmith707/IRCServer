//
//  ConnectionHandler.cpp
//  IRCServer
//
//  Created by Matt on 4/6/15.
//  Copyright (c) 2015 Matt. All rights reserved.
//

#include "ConnectionHandler.h"
ConnectionHandler::ConnectionHandler(Config*& config, Logger*& log) : config(config), log(log), running(false), listenthread() {
}

ConnectionHandler::~ConnectionHandler() {
    running = false;
    for (auto i : clients) {
        delete i;
    }
    if (listenthread.joinable()) {
        listenthread.join();
    }
}

void ConnectionHandler::threadmain() {
    running = true;
    TCPServerSocket server(config->getPort());
    while (running) {
        handleConnection(server.accept());
    }
}

void ConnectionHandler::handleConnection(TCPSocket* socket) {
    Client* client = new Client(config, log, socket);
    client->run();
    clients.emplace(client);
}

void ConnectionHandler::run() {
    listenthread = std::thread(&ConnectionHandler::threadmain, this);
}

void ConnectionHandler::closeConnection(Client*& client) {
    auto it = clients.find(client);
    
}
