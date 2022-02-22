/*
Author: Shourov Saha
Course: CSCI-136
Instructor: Lynch
Assignment: Lab2C

Creates and
edits
an array.
*/

#include <iostream>
using namespace std;

int main() 
{
  int gay [] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int index = 0;
  int value;
  while (index >= 0 && index <= 9)
  {
    cout << "Input index: ";
    cin >> index;
    cout << "Input value: ";
    cin >> value;
    gay [index] = value;
    for (int i = 0; i < 10 ; i++)
    {
      cout << gay[i] << " ";
    }
    cout << endl;
  }
  cout << "Index out of range. Exit.";
  return 0;
}