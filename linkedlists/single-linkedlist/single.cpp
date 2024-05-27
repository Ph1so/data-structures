#include <iostream>
#include "single.h"

void print(mylist p)
{
    p.startIteration();
    int item;
    while (p.nextData(item))
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
int main()
{
    mylist p;
    p.insert(10);
    p.insert(20);
    p.insert(30);
    p.insert(40);
    print(p); // output 40 30 20 10

    mylist q(p);
    print(q); // output 40 30 20 10

    p.remove(40);
    p.remove(20);
    p.remove(10);
    print(p); // output 30

    p.makeEmpty();
    print(p); // outputs nothing

    q = p;
    print(q); // outputs 10

    p.insert(100);
    p.insert(200);
    p.insert(300);
    mylist j(p);
    print(j); // output 300 200 100 10

    return 0;
}