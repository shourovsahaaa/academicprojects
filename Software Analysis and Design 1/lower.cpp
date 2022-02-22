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

  for (int j = 1; j <= n; j++)
    {
      for (int i = 1; i <= j; i++)
	    {
	      cout << '*';
	    }
	    cout << endl;
    }
  return 0;
}
