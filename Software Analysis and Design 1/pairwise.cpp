/*
Author: Shourov Saha
Course: CSCI-135/6
Instructor: Melissa Lynch
Assignment: Lab 12D 

A program called pairwise.cpp
that implements the function vector<int> 
sumPairWise(const vector<int> &v1, const vector<int> &v2)
that returns a vector of integers whose
elements are the pairwise sum of the elements
from the two vectors passed as arguments.
If a vector has a smaller size
than the other, consider extra entries
from the shorter vectors as 0.

Extra comment
Extra comment
Extra comment
Extra comment
Extra comment
Extra comment
*/

#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;



vector<int> sumPairWise(vector<int> &v1, vector<int> &v2)

{

    int size;

    vector <int> newv;
    
    if(v2.empty())
    {

    }
    
    if(v1.size() > v2.size()) 
    {
        size = v1.size();
    }
    
    else
    {
        size = v2.size();
    }
    
    for(int i = 0; i < size; i++)
    {

    if(v2.empty())
    {
        newv.push_back(v1[i]); 
    }

    else if(v1.empty())
    {
        newv.push_back(v2[i]); 
    }

    else
    {
        newv.push_back(v1[i] +v2[i]); 
    }
    
    }

    return newv;

}

void print(std::vector <int> const &a) {

   std::cout << "The vector elements are : ";
   for(int i=0; i < a.size(); i++)

   std::cout << a.at(i) << ' ';

}



int main() 
{
 vector<int> vect1{};
 vector<int> vect2{};
 print(sumPairWise(vect1,vect2));   
}