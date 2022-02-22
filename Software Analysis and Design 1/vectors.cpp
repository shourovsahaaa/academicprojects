/*
Author: Shourov Saha
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab 12A 

Creates a function called 
vector<int> makeVector(int n) 
that returns a vector of n integers 
that range from 0 to n-1.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> makeVector(int n);

int main(){
	vector<int> v = makeVector(10);
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

vector<int> makeVector(int n){
	vector<int> a;
	for(int i = 0; i < n; i++){
		a.push_back(i);
	}
	return a;
}
