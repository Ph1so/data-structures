#include <iostream>
#include "circular.h"

void print(mylist p, int c)
{
    p.startIteration();
    int item;
    for (int i = 0; i < c; i++)
    {
        item = p.nextData();
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
    print(p, 6); // does 6 iterations output 40 30 20 10 40 30

    mylist q(p);
    print(q, 9); // output 40 30 20 10 40 30 20 10 40

    p.remove(40);
    p.remove(20);
    p.remove(10);
    print(p, 3); // output 30 30 30

    p.insert(6);
    print(p, 3);

    p.makeEmpty();
    print(p, 3);

    p.insert(10);
    print(p, 2);

    mylist j(p);
    j = p;
    print(j, 3);

    // p.makeEmpty();
    // print(p); //outputs nothing

    // q = p;
    // print(q); //outputs 10

    // p.insert(100);
    // p.insert(200);
    // p.insert(300);
    // mylist j(p);
    // print(j); //output 300 200 100 10

    return 0;
}