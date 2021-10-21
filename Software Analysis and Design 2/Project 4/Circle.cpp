/*
Title          : Circle.cpp
Author         : Shourov Saha
Description    : Implementation file of abstract child Circle (class) as a Linked List ADT.
*/
#include "Shape.hpp"
#include "Circle.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

Circle::Circle(const int &diameter) : Shape(diameter, diameter)
{
  setEdges(0);

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
  int x_radius = diameter / 2;
  int y_radius = (diameter / 2) - 1;
  float dist = 0;
  char ascii_counter = 48;

  for (int col = 0; col <= getWidth() + 1; col++)
  {
    for (int row = 0; row <= getHeight() + 5; row++)
    {
      dist = sqrt((row - y_radius) * (row - y_radius) + (col - x_radius) * (col - x_radius));

      // dist in range: (radius - 0.5) to (radius + 0.5)
      if (dist > y_radius - 0.5 && dist < y_radius + 0.5)
      {
        arr[row][col] = ascii_counter;

        // fix ascii_counter to wrap around after
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
double Circle::getSurfaceArea()
{
  float x = static_cast<float>(height_) / 2;
  x = 3.141592653589792323 * x * x;
  return static_cast<double>(x);
}
//Returns volume of a Sphere with diameter.
double Circle::get3DVolume(const double& depth)
{
  float x = static_cast<float>(height_) / 2;
  return static_cast<double>(1.33333333333 * 3.141592653589792323 * x * x * x);
}
