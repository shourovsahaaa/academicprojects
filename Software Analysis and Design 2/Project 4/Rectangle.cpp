/*
Title          : Rectangle.cpp
Author         : Shourov Saha
Description    : Implementation file of abstract child Rectangle (class) as a Linked List ADT.
*/
#include "Shape.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

Rectangle::Rectangle(const int& width, const int& height) : Shape(width, height) {
  setEdges(4);
  setWidth(width);
  setHeight(height);
  // Populate 2D array with empty chars
  char **arr = new char *[getHeight()];
  for (int row = 0; row < getHeight(); row++)
  {
    arr[row] = new char[getWidth()];
    for (int col = 0; col < getWidth(); col++)
    {
      arr[row][col] = ' ';
    }
  }
  // Populate the proper positions with *'s
  char ascii_counter = 48;
  for (int i = 0; i < getHeight(); i++)
  {
    for (int j = 0; j < getWidth(); j++)
    {
      if (i == 0 or i == getHeight() - 1 or j == 0 or j == getWidth()- 1)
      {
        arr[i][j] = ascii_counter;
        ascii_counter++;
        if (ascii_counter > 126)
        {
          ascii_counter = 48;
        }
      }
    }
  }
  setDisplayChars(arr);  
}
//Returns area.
double Rectangle::getSurfaceArea()
{
  return getHeight() * getWidth();
}

//Returns volume of Rectangular prism using parametized depth value.
double Rectangle::get3DVolume(const double &depth)
{
  return getHeight() * getWidth() * depth;
}