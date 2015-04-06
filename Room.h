//
//  Room.h
//  IRCServer
//
//  Created by Matt on 4/6/15.
//  Copyright (c) 2015 Matt. All rights reserved.
//

#ifndef __IRCServer__Room__
#define __IRCServer__Room__

#include <unordered_set>
#include "Client.h"
#include "IRCMsg.h"

class Room {
private:
    std::unordered_set<Client*> clients;
public:
    Room();
    void joinRoom(Client*&);
    void leaveRoom(Client*&);
    void sendMsg(IRCMsg&);
};

#endif /* defined(__IRCServer__Room__) */
