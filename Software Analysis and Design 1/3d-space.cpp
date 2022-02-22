/*
Author: Shourov Saha
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab9E

Creates a function,
length, which calculates the length
of a vector with three dimentions using
the class Coord3D which represents the
x, y, and z coordinates of the point (x, y, z).

Creates a function, fartherFromOrigin, which takes
two Coord3D points, calculates the length
of both, and returns the point with the
greater length.

Creates a function, move, that alters the coordinate
by a x, y, and z, vector and calculates the change over
the time.

Creates a function that creates a new
Coord3D value that can be used to return
and edit other values used in other functions.

*/

#include <iostream>
#include <cmath>
using namespace std;

class Coord3D 
{
public:
    double x;
    double y;
    double z;
};

double length(Coord3D *p)
{
    double len;
    double xcor = p->x;
    double ycor = p->y;
    double zcor = p->z;
    len = sqrt(xcor*xcor + ycor*ycor + zcor*zcor);
    return len;
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2)
{
    if (length(p1) > length(p2))
    {
        return p1;
    }
    else
    {
        return p2;
    }
}

void move(Coord3D *ppos, Coord3D *pvel, double dt)
{
    double x, y, z, velx, vely, velz;
    x = ppos->x;
    y = ppos->y;
    z = ppos->z;
    velx = pvel->x;
    vely = pvel->y;
    velz = pvel->z;
    x = x + velx * dt;
   
    y = y + vely * dt;
   
    z = z + velz * dt;
    ppos->x = x;
    ppos->y = y;
    ppos->z = z;
}
// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z)
{
    Coord3D *p = new Coord3D;
    p->x = x;
    p->y = y;
    p->z = z; 
    return p;
}

// free memory
void deleteCoord3D(Coord3D *p)
{
    delete p;
}

int main() 
{
    Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};

    move(&pos, &vel, 2.0); // object pos gets changed
    cout << pos.x << " " << pos.y << " " << pos.z << endl;
    // prints: 2 -10 100.4
    return 0;
}