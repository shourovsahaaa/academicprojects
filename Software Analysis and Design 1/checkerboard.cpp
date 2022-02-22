/*
Author: Shourov Saha
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab4A

Creates a 
checkerboard
style
shape using *'s.
*/
#include <iostream>
using namespace std;

int
main ()
{
  int w;
  int h;
  cout << "Input width: ";
  cin >> w;
  cout << "Input height: ";
  cin >> h;
  cout << endl;
  cout << "Shape:" << endl;
  for (int j = 1; j <= h; j++)
    {
      if (j % 2 == 1)
	{
	  for (int i = 1; i <= w; i++)
	    {
	      if (i % 2 == 1)
		{
		  cout << '*';
		}
	      if (i % 2 == 0)
		{
		  cout << ' ';
		}

	    }
	}
      else
	{
	  for (int i = 1; i <= w; i++)	//check here for error in spacing
	    {
	      if (i % 2 == 0)
		{
		  cout << '*';
		}
	      if (i % 2 == 1)
		{
		  cout << ' ';
		}

	    }
	}

      cout << endl;
    }



  return 0;

}
