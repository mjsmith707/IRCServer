//
//  Shared_Queue.h
//  IRCServer
//
//  Created by Matt on 2/4/15.
//  Copyright (c) 2015 Matt. All rights reserved.
//

#ifndef __IRCServer__Shared_Queue__
#define __IRCServer__Shared_Queue__

#include <queue>
#include <mutex>

template <class T> class Shared_Queue {
private:
    std::queue<T> sharedQueue;
    std::mutex queueMutex;
    
public:
    Shared_Queue() {
    }
    
    T pop() {
        try {
            std::lock_guard<std::mutex> lock(queueMutex);
            if (!sharedQueue.empty()) {
                T result = sharedQueue.front();
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
    
    void push(T input) {
        std::lock_guard<std::mutex> lock(queueMutex);
        sharedQueue.push(input);
    }
    
    bool isEmpty() {
        std::lock_guard<std::mutex> lock(queueMutex);
        return sharedQueue.empty();
    }
};

#endif /* defined(__IRCServer__Shared_Queue__) */
