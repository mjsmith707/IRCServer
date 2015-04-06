//
//  Room.cpp
//  IRCServer
//
//  Created by Matt on 4/6/15.
//  Copyright (c) 2015 Matt. All rights reserved.
//

#include "Room.h"

Room::Room() {
    
}

void Room::joinRoom(Client*& client) {
    clients.emplace(client);
}

void Room::leaveRoom(Client*& client) {
    clients.erase(client);
}

void Room::sendMsg(IRCMsg& msg) {
    for (auto i : clients) {
        i->sendMsg(msg);
    }
}