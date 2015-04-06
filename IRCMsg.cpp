//
//  IRCMsg.cpp
//  IRCServer
//
//  Created by Matt on 4/6/15.
//  Copyright (c) 2015 Matt. All rights reserved.
//

#include "IRCMsg.h"

IRCMsg::IRCMsg(std::string& username, std::string& room, std::string& message) : username(username), room(room), message(message) {
    
}