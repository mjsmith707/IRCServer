//
//  IRCCommandHandler.h
//  IRCServer
//
//  Created by Matt on 4/6/15.
//  Copyright (c) 2015 Matt. All rights reserved.
//

#ifndef __IRCServer__CommandHandler__
#define __IRCServer__CommandHandler__

#include "Config.h"
#include "Logger.h"
#include "Client.h"

class CommandHandler {
private:
    Config* config;
    Logger* log;
public:
    CommandHandler(Config*&, Logger*&);
};

#endif /* defined(__IRCServer__CommandHandler__) */
