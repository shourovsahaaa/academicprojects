/*
Title          : Triangle.hpp
Author         : Shourov Saha
Description    : Header/Interface file of abstract child Triangle (class) as a Linked List ADT.
*/
#ifndef TRIANGLE_
#define TRIANGLE_

class Triangle : public Shape {
  public:
    /* Parameterized constructor; takes in side length as a parameter, iterates 
    through the 2D array to draw the right triangle using ASCII chars */
    Triangle(const int &side);       

    //Returns area of triange.
    double getSurfaceArea();   
    
    //Returns volume of Triangular prism using parametized depth value.                    
    double get3DVolume(const double &depth); 
};
#endif
