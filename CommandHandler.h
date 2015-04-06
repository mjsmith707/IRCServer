//
//  IRCCommandHandler.h
//  IRCServer
//
//  Created by Matt on 4/6/15.
//  Copyright (c) 2015 Matt. All rights reserved.
//

#ifndef __IRCServer__CommandHandler__
#define __IRCServer__CommandHandler__

#include <unordered_map>
#include "Client.h"
#include "Room.h"

class CommandHandler {
private:
    std::unordered_map<std::string, Room*> roomlist;
    
public:
    CommandHandler();
    void joinRoom(std::string&, Client*&);
    void leaveRoom(std::string&, Client*&);
};

#endif /* defined(__IRCServer__CommandHandler__) */
