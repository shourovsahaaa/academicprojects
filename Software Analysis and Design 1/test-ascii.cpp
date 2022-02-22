/*
Author: Shourov Saha
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab6A

Lists all the
characters in a
string and its 
ASCII character code.
*/
#include <iostream>
using namespace std;

int main()
{
    cout << "Input: ";
    string s; 
    getline (cin, s);
    int x = s.size();
    for (int i = 0; i < x; i++)
    {
        cout << s[i] << ' ' << int(s[i]) << endl;
    }
    return 0;
}
