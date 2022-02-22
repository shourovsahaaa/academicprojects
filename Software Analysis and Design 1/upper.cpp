/*
Author: Shourov Saha
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab4C

Creates a
cross of 
size cin >> n;
*/
#include <iostream>
using namespace std;

int
main ()
{
  int n;
  cout << "Input side length: ";
  cin >> n;
  cout << endl;

  for (int j = n; j >= 1; j--)
    {
        for (int h = j; h <= n- 1 ; h++ )
        {
            cout << ' ';
        }
      for (int i = j; i >= 1; i--)
	    {
	      cout << '*';
	    }
	    cout << endl;
    }
  return 0;
}
