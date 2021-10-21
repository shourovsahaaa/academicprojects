/*
Title          : Triangle.cpp
Author         : Shourov Saha
Description    : Implementation file of abstract child Triangle (class) as a Linked List ADT.
*/
#include "Shape.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

Triangle::Triangle(const int &side) : Shape(side,side) {
  setEdges(3);
  setWidth(side);
  setHeight(side);  
  // Populate 2D array with empty chars
  char **arr = new char*[getHeight()];
  for(int row = 0; row < getHeight(); row++)
  {
    arr[row] = new char[getWidth()];
    for(int col = 0; col < getWidth(); col++)
    {
      arr[row][col] = ' ';
    }
  }
  // Populate the proper positions with *'s
  char ascii_counter = 48;
  for(int row = 0; row < getHeight(); row++)
  {
    for(int col= 0; col < getWidth(); col++)
    {
      if(col == 0 or row == col or row == getHeight()-1)
      {
        arr[row][col] = ascii_counter;
        ascii_counter++;
        
        if(ascii_counter > 126)
        {
          ascii_counter = 48;
        }
      }
    }
  }
  setDisplayChars(arr);
}
//Returns area of triange.
double Triangle::getSurfaceArea()
{
  return static_cast<double>(height_) * static_cast<double>(width_) / 2;
}   
//Returns volume of Triangular prism using parametized depth value.
double Triangle::get3DVolume(const double &depth)
{
  return static_cast<double>(height_) * static_cast<double>(width_) / 2 * depth;
} 
