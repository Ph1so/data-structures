// double.h header file
#ifndef _MYLIST_H
#define _MYLIST_H
#include <iostream>
using namespace std;

class mylist
{
public:
    mylist()
    {
        myHead = nullptr;
        myCurrent = nullptr;
        myTail = nullptr;
    }; // constructors/destructor
    mylist(const mylist &L)
    {
        myHead = L.myHead;
        myCurrent = L.myCurrent;
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
            while (p != nullptr)
            {
                nw.insert(p->info);
                p = p->next;
            }
            p = nw.myHead;
            while (p != nullptr)
            {
                insert(p->info);
                p = p->next;
            }
            myCurrent = myHead;
        }

        return *this;
        // makeEmpty();
        // node *p = rhs.myHead;
        // while(p->next != nullptr)p=p->next;
        // while(p != nullptr){
        //   insert(p->info);
        //   p=p->prev;
        // }
        // return *this;
    }; // assignment

    void startIterationFromBeginning() { myCurrent = myHead; }; // iterators
    void startIterationFromEnd() { myCurrent = myTail; };
    bool nextData(int &item)
    {
        if (myCurrent != nullptr)
        {
            item = myCurrent->info;
            myCurrent = myCurrent->next;
            return true;
        }
        return false;
    }; // Gives you the item at that loc as the reference, advances the pointer
       // and returns true if that all succeeds

    bool prevData(int &item)
    {
        if (myCurrent != nullptr)
        {
            item = myCurrent->info;
            myCurrent = myCurrent->prev;
            return true;
        }
        return false;
    }

    // modifiers
    void insert(int item)
    {
        node *p = new node(item, myHead, nullptr);
        if (myHead == nullptr)
        {
            myTail = p;
        }
        else
        {
            myHead->prev = p;
        }
        myHead = p;

    }; // Add Item to the front of the list
    void remove(int item)
    {
        node *cur = myHead;

        while (cur != nullptr)
        {
            if (cur->info == item)
            {
                if (cur == myHead)
                {
                    myHead = myHead->next;
                    if (myHead != nullptr)
                    {
                        myHead->prev = nullptr;
                    }
                    else
                    {
                        myTail = nullptr;
                    }
                    delete cur;
                    cur = myHead;
                }
                else
                {
                    cur->prev->next = cur->next;
                    if (cur->next != nullptr)
                    {
                        cur->next->prev = cur->prev;
                    }
                    else
                    {
                        myTail = cur->prev;
                    }
                    node *temp = cur;
                    cur = cur->next;
                    delete temp;
                }
            }
            else
            {
                cur = cur->next;
            }
        }
        // if(myHead ==nullptr){
        //   cout << "empty list\n";
        //   return;
        // }
        // while(myHead->info == item){
        //   node *p = myHead;
        //   myHead->next->prev = myHead->prev;
        //   myHead = myHead->next;
        //   delete p;
        //   if(myHead == nullptr){
        //     return;
        //   }
        // }

        // node *q = myHead;
        // while(q->next != nullptr){
        //   while(q->next->info == item){
        //     node *temp = q->next;;
        //     q->next = q->next->next;
        //     delete temp;
        //     if(q->next == nullptr) return;
        //     q->next->prev = q;
        //   }
        //   q = q->next;
        // }
    }; // Removes all elements equal to item
    void makeEmpty()
    {
        while (myHead != nullptr)
        {
            node *p = myHead;
            myHead = myHead->next;
            delete &p;
        }
        myCurrent = nullptr;
        myTail = nullptr;
    }; // Removes all elements in the list

private:
    struct node
    {
        int info;
        node *next;
        node *prev;
        node(int D, node *N, node *P) : info(D), next(N), prev(P) {}
    };

    node *myHead;    // Keeps track of the head
    node *myTail;    // Keeps track of the tail
    node *myCurrent; // used for traversing the list
};

#endif