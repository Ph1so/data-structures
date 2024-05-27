// circular.h header file
#ifndef _MYLIST_H
#define _MYLIST_H
#include <iostream>
using namespace std;

class mylist
{
public:
    mylist() { myHead = nullptr; }; // constructors/destructor
    mylist(const mylist &L)
    {
        myHead = L.myHead;
        myTail = L.myTail;
    };
    ~mylist() { makeEmpty(); };
    const mylist &operator=(const mylist &rhs)
    {
        if (&rhs != this)
        {
            makeEmpty();
            mylist nw;
            node *p = rhs.myHead;
            while (p != myTail)
            {
                nw.insert(p->info);
                p = p->next;
            }
            p = nw.myHead;
            while (p != myTail)
            {
                insert(p->info);
                p = p->next;
            }
        }

        return *this;
    }; // assignment

    void startIteration() { myCurrent = myHead; }; // iterators
    int nextData()
    {
        int item = myCurrent->info;
        myCurrent = myCurrent->next;
        return item;
    }; // Gives you the item at that loc as the reference, advances the pointer
       // and returns true if that all succeeds

    // modifiers
    void insert(int item)
    {
        node *newNode = new node(item, nullptr);
        if (myHead == nullptr)
        {
            myHead = newNode;
            myTail = newNode;
        }
        else
        {
            newNode->next = myHead;
            myHead = newNode;
            myTail->next = myHead;
        }
    }; // Add Item to the front of the list
    void remove(int item)
    {
        if (myHead == nullptr)
            return;

        while (myHead->info == item)
        {
            if (myHead == myTail)
            {
                delete myHead;
                myHead = nullptr;
                myTail = nullptr;
                return;
            }
            node *p = myHead;
            myHead = myHead->next;
            myTail->next = myHead;
            delete &p;
        }

        node *prev = myHead;
        node *cur = myHead->next;

        while (cur != myHead)
        {
            if (cur->info == item)
            {
                prev->next = cur->next;
                if (cur == myHead)
                    myTail = prev;
                delete cur;
                cur = prev->next;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }

    }; // Removes all elements equal to item
    void makeEmpty()
    {
        while (myHead != myTail)
        {
            node *p = myHead;
            myHead = myHead->next;
            delete &p;
        }
    }; // Removes all elements in the list

private:
    struct node
    {
        int info;
        node *next;
        node(int D, node *N) : info(D), next(N) {}
    };

    node *myHead; // Keeps track of the head
    node *myTail;
    node *myCurrent; // used for traversing the list
};

#endif