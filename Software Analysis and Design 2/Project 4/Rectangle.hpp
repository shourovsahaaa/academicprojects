/*
Title          : Rectangle.hpp
Author         : Shourov Saha
Description    : Header/Interface file of abstract child Rectangle (class) as a Linked List ADT.
*/
#ifndef RECTANGLE_
#define RECTANGLE_

class Rectangle : public Shape {
  public:
  /* Parameterized constructor; takes in width and height, 
    iterates through the 2D array to populate it with 
    the necessary characters given the parameter dimensions */
  Rectangle(const int& width, const int& height);  
  //Returns area.
  double getSurfaceArea();         
  //Returns volume of Rectangular prism using parametized depth value.               
  double get3DVolume(const double &depth);
};
#endif