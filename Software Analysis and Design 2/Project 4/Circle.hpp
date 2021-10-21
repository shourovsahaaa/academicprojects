/*
Title          : Circle.hpp
Author         : Shourov Saha
Description    : Header/Interface file of abstract child Circle (class) as a Linked List ADT.
*/
#ifndef CIRCLE_
#define CIRCLE_

class Circle : public Shape {
  public:
    //Parameterized contructor: takes diameter as width or height. 
    Circle(const int& diameter);

    //Returns area.
    double getSurfaceArea();      
    //Returns volume of a Sphere with diameter.                  
    double get3DVolume(const double& depth);     
};
#endif