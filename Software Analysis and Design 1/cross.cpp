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
  int y;
  cout << "Input size: ";
  cin >> n;
  cout << endl;
  for (int x = 0 ; x < n ; x++)
  {
  for (int i = 1 ; i <= n ; i++)
  {
      if (i == x + 1 )
      {
          cout << '*';
      }
      else if (i == (n - x))
      {
          cout << '*';
      }
      else
      {
          cout << ' ';
      }
  }
  cout << endl;
  }
  return 0;
}