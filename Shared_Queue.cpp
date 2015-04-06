//
//  Shared_Queue.cpp
//  IRCServer
//
//  Created by Matt on 2/4/15.
//  Copyright (c) 2015 Matt. All rights reserved.
//

#include "Shared_Queue.h"

Shared_Queue::Shared_Queue() {
    
}

std::string Shared_Queue::pop() {
    try {
        std::lock_guard<std::mutex> lock(queueMutex);
        if (!sharedQueue.empty()) {
            std::string result = sharedQueue.front();
            sharedQueue.pop();
            return result;
        }
        else {
            throw std::runtime_error("Shared Queue is Empty");
        }
    }
    catch (std::runtime_error e) {
        throw e;
    }
}

void Shared_Queue::push(std::string input) {
    std::lock_guard<std::mutex> lock(queueMutex);
    sharedQueue.push(input);
}

bool Shared_Queue::isEmpty() {
    std::lock_guard<std::mutex> lock(queueMutex);
    return sharedQueue.empty();
}