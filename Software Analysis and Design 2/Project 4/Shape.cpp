/*
Title          : Shape.cpp
Author         : Shourov Saha
Description    : Implementation file of abstract parent Shape (class) as a Linked List ADT.
*/
#include "Shape.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// Parameterized Constructor; there is no default constructor
Shape::Shape(const int &width, const int &height)
{
  height_ = height;
  width_ = width;
  display_ = new char *[height_];
  for (int row = 0; row < getHeight(); row++)
  {
    display_[row] = new char[width_];
    for (int col = 0; col < getWidth(); col++)
    {
      display_[row][col] = ' ';
    }
  }  
}

// Getters
int Shape::getEdges()
{
  return edges_;
}

int Shape::getWidth()
{
  return width_;
}
int Shape::getHeight()
{
  return height_;
}

char **Shape::getDisplayChars()
{
  return display_;
}

// Setters
void Shape::setEdges(const int& edges)
{
  edges_ = edges;
}

void Shape::setWidth(const int& new_width)
{
  width_ = new_width; 
}

void Shape::setHeight(const int &new_height)
{
  height_ = new_height;
}

void Shape::setDisplayChars(char **display)
{
  delete display_; //Prevents memory leaks
  display_ = display;
}

// Mutators
void Shape::rotateRight()         //rotate by 90 degrees
{
  char **arr = new char *[getWidth()];
  for (int row = 0; row < getWidth(); row++)
  {
    arr[row] = new char[getHeight()];
    for (int col = 0; col < getHeight(); col++)
    {
      arr[row][col] = display_[getHeight()- 1 - col][row];
    }
  }
  int x = height_;
  int y = width_;
  height_ = y;
  width_= x;
  setDisplayChars(arr);
}

void Shape::rotateLeft()          //rotate by 90 degrees
{
  char **arr = new char *[getWidth()];
  for (int row = 0; row < getWidth(); row++)
  {
    arr[row] = new char[getHeight()];
    for (int col = 0; col < getHeight(); col++)
    {
      arr[row][col] = display_[col][getWidth() - 1 - row];
    }
  }
  int x = height_;
  int y = width_;
  height_ = y;
  width_= x;
  setDisplayChars(arr);
}

void Shape::reflect(char axis)    //reflect over x or y axis
{
  char **arr = new char *[getHeight()];
  for (int row = 0; row < getHeight(); row++)
  {
    arr[row] = new char[getWidth()];
    for (int col = 0; col < getWidth(); col++)
    {
      arr[row][col] = ' ';
    }
  }
  
  if (axis == 'x') //x axis reflection
  {
    int temp = 0;
    for (int row = height_- 1; row >= 0; row--)
    {
      for (int col = 0; col < width_; col++)
      {
        arr[temp][col] = display_[row][col];
        
      }
      temp++;
    }
  }
  if (axis == 'y') // y axis reflection
  {
    int temp = 0;
    for (int row = 0; row < height_; row++)
    {
      for (int col = width_ - 1; col >= 0; col--)
      {
        arr[row][temp] = display_[row][col];
        temp++;
      }
      temp = 0;
    }
  }
  setDisplayChars(arr);
}

// Display - //iterate through 2D array and print chars
void Shape::display()
{
  for (int i = 0; i < height_; i++)
  {
    for (int j = 0; j < width_; j++)
    {
      cout << display_[i][j];
      if (j != width_ - 1)
      {
        cout << " ";
      }
    }
    cout << endl;
  }
}                                     