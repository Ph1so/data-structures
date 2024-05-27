// mylist.h header file
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
    }; // constructors/destructor
    mylist(const mylist &L)
    {
        myHead = L.myHead;
    };
    ~mylist() { makeEmpty(); };
    const mylist &operator=(const mylist &rhs)
    {
        int hold;
        int *pt;
        if (&rhs != this)
        {
            makeEmpty();
            mylist nw;
            node *p = rhs.myHead;
            while (p != nullptr)
            {
                hold = p->info;
                pt = &hold;
                nw.insert(*pt);
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

        // int len = 0;
        // node *p = rhs.myHead;
        // while (p->next != nullptr){
        //   len++;
        //   p=p->next;
        // }
        // len++;
        // for(int i = 0; i < len; i++){
        //   insert(0);
        // }
        // p = rhs.myHead;
        // node *curr = myHead;
        // for(int i = 0; i < len; i++){
        //   curr->info=p->info;
        //   curr = curr->next;
        //   p=p->next;
        // }
        // return *this;
    }; // assignment

    void startIteration() { myCurrent = myHead; }; // iterators
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

    // modifiers
    void insert(int item)
    {
        node *p = new node(item, myHead);
        myHead = p;
    }; // Add Item to the front of the list
    void remove(int item)
    {
        // node *prev = nullptr;
        // node *cur = myHead;

        // while (cur != nullptr) {
        //   if (cur->info == item) {
        //     if (cur == myHead) {
        //       myHead = myHead->next;
        //       cur = myHead;
        //     } else {
        //       prev->next = cur->next;
        //       cur = prev->next;
        //     }
        //   } else {
        //     prev = cur;
        //     cur = cur->next;
        //   }
        // }
        while (myHead->info == item)
        {
            node *p = myHead;
            myHead = myHead->next;
            delete p;
            if (myHead == nullptr)
                return;
        }
        node *p = myHead;
        while (p->next != nullptr)
        {
            while (p->next->info == item)
            {
                node *temp = p->next;
                p->next = p->next->next;
                delete temp;
                if (p->next == nullptr)
                    return;
            }
            p = p->next;
        }
    }; // Removes all elements equal to item
    void makeEmpty()
    {
        while (myHead != nullptr)
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

    node *myHead;    // Keeps track of the head
    node *myCurrent; // used for traversing the list
};

#endif