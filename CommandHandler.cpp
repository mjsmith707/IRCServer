//
//  CommandHandler.cpp
//  IRCServer
//
//  Created by Matt on 4/6/15.
//  Copyright (c) 2015 Matt. All rights reserved.
//

#include "CommandHandler.h"

CommandHandler::CommandHandler() {
    
}

void CommandHandler::joinRoom(std::string& roomName, Client*& client) {
    auto it = roomlist.find(roomName);
    if (it == roomlist.end()) {
        Room* room = new Room();
        roomlist.emplace(roomName, room);
        room->joinRoom(client);
    }
    else {
        it->second->joinRoom(client);
    }
}

void CommandHandler::leaveRoom(std::string& roomName, Client*& client) {
    auto it = roomlist.find(roomName);
    if (it == roomlist.end()) {
        // trying to leave nonexistant room
    }
    else {
        it->second->leaveRoom(client);
    }
}