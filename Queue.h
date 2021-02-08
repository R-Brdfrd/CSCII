//
//  Queue.h
//  Final
//
//  Created by Robert Bradford on 5/8/18.
//  Copyright © 2018 Robert Bradford. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include "Node and Stack.h"

class Qobj:public stackType
{
public:
    bool isEmpty() const;
    void initialize();
    int front() const;
    int back() const;
    void enQueue(int);
    void deQueue();
    int length();
    Qobj();
    Qobj(const Qobj& otherObj);
    ~Qobj();
private:
    stackType list;
};

int Qobj::length()
{
    return list.length();
}

bool Qobj::isEmpty() const
{
    return list.isEmptyStack();
}

void Qobj::initialize()
{
    list.initializeStack();
}

int Qobj::front() const
{
    return list.front();
}

int Qobj::back() const
{
    return list.back();
}

void Qobj::enQueue(int newItem)
{
    list.insertLast(newItem);
}

void Qobj::deQueue()
{
    list.deleteNode(list.front());
}

Qobj::Qobj()
{
    
}

Qobj::Qobj(const Qobj& otherObj)
{
    
}

Qobj::~Qobj()
{
    list.destroyList();
}



#endif /* Queue_h */
