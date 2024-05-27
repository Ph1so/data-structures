#include <iostream>
#include "double.h"

using namespace std;

void printFromBeginning(mylist p)
{
    p.startIterationFromBeginning();
    int item;
    while (p.nextData(item))
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

void printFromEnd(mylist p)
{
    p.startIterationFromEnd();
    int item;
    while (p.prevData(item))
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main()
{
    mylist p;
    p.remove(10); // nothing should happen

    p.insert(10);
    p.insert(20);
    p.insert(10);
    p.insert(20);
    p.insert(10);
    printFromBeginning(p); // output 40 30 20 10

    mylist q(p);
    printFromEnd(q); // output 10 20 30 40

    p.remove(20);
    cout << "remove 20" << endl;
    printFromBeginning(p);
    cout << "remove 10" << endl;
    p.remove(10);
    printFromBeginning(p); // output 30

    p.makeEmpty();
    printFromEnd(p); // output

    q = p;
    printFromBeginning(q); // output

    p.insert(100);
    p.insert(200);
    p.insert(300);
    mylist j(p);
    printFromBeginning(j); // output 300 200 100
    printFromEnd(j);       // output 100 200 300

    return 0;
}
