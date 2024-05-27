//  mystack.h	 mystack class INTERFACE using pointers
#ifndef _MYSTACK_H
#define _MYSTACK_H
#include <iostream>
using namespace std;
class mystack
{
public:
    mystack()
    {
        mytop = nullptr;
    }; // constructs empty stack
    mystack(const mystack &S)
    {
        mytop = S.mytop;
    }; // copy constructor
    ~mystack()
    {
        makeEmpty();
    }; // destructor to deallocate memory
    char top() const
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
        }
        return mytop->info;
    }; // returns top, no pop
    bool isEmpty() const
    {
        return (mytop == nullptr);
    }; // test for no nodes
    int length() const
    {
        int i = 0;
        nodetype *p = mytop;
        while (p != nullptr)
        {
            p = p->next;
            i++;
        }

        return i;
    }; // return number of elements
    void push(char item)
    {
        nodetype *p = new nodetype;
        p->info = item;
        p->next = mytop;
        mytop = p;
    }; // push char onto top
    void pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        nodetype *p = mytop;
        mytop = mytop->next;
        delete &p;
    }; // remove top and deallocate node
    void pop(char &item)
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
        }
        else
        {
            item = mytop->info;
            pop();
        }
    }; // retrieve top char and deallocate node
    void makeEmpty()
    {
        while (mytop != nullptr)
        {
            pop();
        }
        delete mytop;
    }; // empty stack & deallocate memory

    mystack operator=(const mystack &S)
    {
        makeEmpty();
        mystack nw;
        nodetype *p = S.mytop;
        while (p != nullptr)
        {
            nw.push(p->info);
            p = p->next;
        }
        p = nw.mytop;
        while (p != nullptr)
        {
            push(p->info);
            p = p->next;
        }

        return *this;
    }; // assignment operator

private:
    struct nodetype
    {
        char info;
        nodetype *next;
    };
    nodetype *mytop; // pointer to top of stack
};
#endif
