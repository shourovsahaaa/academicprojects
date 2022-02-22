/*
Author: Shourov Saha
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab4F

Creates
an upside-down
trapizoid.
*/
#include <iostream>
using namespace std;

int
main ()
{
  int h; 
  int w;
  cin >> w;
  cin >> h;			//loop that repeats (height) times
  int a;
  a = h - 1;
  if ( (2 * a) >= w)
  {
      cout << "Impossible shape!";
      return 0;
  }
  cout<< "\nShape:\n";
  for (int i = 0; i < h; i++)
    {
      for (int j = 1; j <= w; j++)
	  {
	        if (j <= i)
	        {
	            cout << ' ';
	        }
        	else if (j > (w - i))
	        {
	            cout << ' ';
	        }
	        else
	        {
	            cout << '*';
	        }
	    }
        cout << endl;
        
    }
}
