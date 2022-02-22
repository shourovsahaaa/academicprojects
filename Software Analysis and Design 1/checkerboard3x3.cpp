/*
Author: Shourov Saha
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab4G

Creates
a 3x3
checkerboard.
alternates ***'s.
*/
#include <iostream>
using namespace std;

int
main ()
{
    int h;
    int w;
    cin >> w;
    cin >> h;
    for (int i = 0 ; i < h ; i++)
    {
        if ((i / 3) % 2 == 0)
        {
        for (int j = 0; j < w; j++)
        {
            if ( ((i / 3) % 2 == 0) && ((j / 3) % 2 == 0) )
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        }
        if ((i / 3) % 2 == 1)
        {
        for (int j = 0; j < w; j++)
        {
            if ( ((i / 3) % 2 == 1) && ((j / 3) % 2 == 1) )
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        }
        cout << endl;
    }
    return 0;
}