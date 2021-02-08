//
//  Node and Stack.h
//  Final
//
//  Created by Robert Bradford on 5/8/18.
//  Copyright © 2018 Robert Bradford. All rights reserved.
//

#ifndef Node_and_Stack_h
#define Node_and_Stack_h




#include <iostream>

using namespace std;

struct nodeType
{
    int info;
    nodeType *link;
};

class stackType
{
public:
    const stackType& operator = (const stackType& a);
    void initializeStack();
    bool isEmptyStack() const;
    void print();
    int length();
    void destroyList();
    int front() const;
    int back() const;
    
    bool search(const int& searchItem);
    void deleteNode(const int& a);
    
    void insertFirst(const int& newItem);
    void insertLast(const int& newItem);
    
    stackType();
    stackType (const stackType&);
    ~stackType();
private:
    int count;
    nodeType *first;
    nodeType *last;
    void copyList(const stackType & otherStack);
    
};

const stackType& stackType::operator = (const stackType& a)
{
    if (this != &a)
        copyList(a);
    
    return *this;
    
}

void stackType::destroyList()
{
    nodeType *temp;
    while (first != nullptr)
    {
        temp = first;
        first = first->link;
        delete temp;
    }

    last = nullptr;
    count = 0;
}


void stackType::initializeStack()
{
    destroyList();
}


int stackType::length()
{
    return count;
}

int stackType::front() const
{
    assert (first != nullptr);
    return first ->info;
}

int stackType::back() const
{
    assert (last != nullptr);
    
    return last->info;
}

bool stackType::search(const int& searchItem)
{
    bool found = false;
    nodeType *current;
    
    current = first;
    
    while (current != nullptr && !found)
    {
        if (current ->info == searchItem)
            found = true;
        else
            current = current -> link;
    }
    
    return found;
}

void stackType::insertFirst(const int& newItem)
{
    nodeType *thing;
    thing = new nodeType;
    thing -> info = newItem;
    thing -> link = first;
    first = thing;
    count++;
    if (last == nullptr)
        last = thing;
}

void stackType::insertLast(const int& newItem)
{
    nodeType *thing;
    thing = new nodeType;
    thing -> info = newItem;
    thing -> link = first;
    
    if (first == nullptr)
    {
        first = thing;
        last = thing;
        count++;
    }
    else
    {
        last -> link = thing;
        last = thing;
        count++;
    }
}


bool stackType::isEmptyStack() const
{
    return (first == nullptr);
}


void stackType::print()
{
    nodeType *current;
    current = first;
    while (current != nullptr)
    {
        cout << current -> info << " ";
        current = current -> link;
    }
}

stackType::stackType()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

stackType::stackType (const stackType &otherStack)
{
    first = nullptr;
    copyList(otherStack);
}

stackType::~stackType()
{
    destroyList();
}

void stackType::copyList(const stackType & otherStack)
{
    nodeType *newNode;
    nodeType *current;
    
    if (first == nullptr)
        destroyList();
    
    if (otherStack.first == nullptr)
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else
    {
        current = otherStack.first;
        count = otherStack.count;
        
        first = new nodeType;
        first -> info = current -> info;
        first -> link = nullptr;
        last = first;
        current = current -> link;
        
        while (current != nullptr)
        {
            newNode = new nodeType;
            newNode -> info = current -> info;
            newNode -> link = nullptr;
            last -> link = newNode;
            last = newNode;
            current = current -> link;
        }
    }
}

void stackType::deleteNode(const int& a)
{
    new nodeType();
    nodeType *current;
    nodeType *trailCurrent;
    bool found;
    
    if (first == nullptr)
    {
        cout << "Cannot delete from an empty list." << endl;
    }
    else
    {
        if (first -> info == a)
        {
            current = first;
            first = first -> link;
            count--;
            if (first == nullptr)
            {
                last = nullptr;
            }
            
            delete current;
        }
        else
        {
            found = false;
            trailCurrent = first;
            current = first-> link;
            
            while (current != nullptr && !found)
            {
                if (current -> info != a)
                {
                    trailCurrent = current;
                    current = current -> link;
                }
                else
                    found = true;
            }
            
            if(found)
            {
                trailCurrent -> link = current -> link;
                count--;
                
                if (last==current)
                    last = trailCurrent;
                
                delete current;
            }
            else
                cout << "The item to be deleted is not in the list" << endl;
        }
    }
}

#endif /* Node_and_Stack_h */
