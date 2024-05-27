#include <iostream>
#include "mystack.h"
using namespace std;

int main()
{

    bool dec = true;
    while (dec == true)
    {
        string word;
        cout << "Enter a word:  ";
        cin >> word;

        mystack w;
        for (int i = 0; i < word.length(); i++)
        {
            w.push(word[i]);
        }
        string check;
        char index;
        for (int i = 0; i < word.length(); i++)
        {
            w.pop(index);
            check += index;
        }

        if (check == word)
        {
            cout << "This is a palindrome!" << endl;
        }
        else
        {
            cout << "This is not a palindrome!" << endl;
        }
        cout << "Would you like to enter another word? (1 or 0) ";
        int c;
        cin >> c;
        if (c == 1)
            dec = true;
        else
            dec = false;
    }
}