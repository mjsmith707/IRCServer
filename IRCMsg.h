//
//  IRCMsg.h
//  IRCServer
//
//  Created by Matt on 4/6/15.
//  Copyright (c) 2015 Matt. All rights reserved.
//

#ifndef __IRCServer__IRCMsg__
#define __IRCServer__IRCMsg__

#include <string>

class IRCMsg {
    public:
        std::string username;
        std::string room;
        std::string message;
        IRCMsg(std::string&, std::string&, std::string&);
};

#endif /* defined(__IRCServer__IRCMsg__) */
