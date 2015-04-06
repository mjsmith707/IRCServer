//
//  Shared_Queue.h
//  IRCServer
//
//  Created by Matt on 2/4/15.
//  Copyright (c) 2015 Matt. All rights reserved.
//

#ifndef __IRCServer__Shared_Queue__
#define __IRCServer__Shared_Queue__

#include <string>
#include <queue>
#include <mutex>

class Shared_Queue {
private:
    std::queue<std::string> sharedQueue;
    std::mutex queueMutex;
    
public:
    Shared_Queue();
    std::string pop();
    void push(std::string);
    bool isEmpty();
};

#endif /* defined(__IRCServer__Shared_Queue__) */
