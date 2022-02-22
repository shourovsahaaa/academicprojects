/*
Author: Shourov Saha
Course: CSCI-135/6
Instructor: Melissa Lynch
Assignment: Lab 12B 

Implements the function 
vector<int> goodVibes(const & vector<int> v);
that, given a vector of integers,
returns a vector with only the
positive integers in the same order.

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> makeVector(int n);
vector<int> goodVibes(const vector<int> v);

int main(){
	vector<int> v{1,2,-1,3,4,-1,6}; 
	vector<int> v1 = goodVibes(v);

	for(int i = 0; i < v1.size(); i++){
		cout << v1[i] << " ";
	}
	cout << endl;
}

vector<int> goodVibes(const vector<int> v){
	vector<int> a;
	for(int i = 0; i < v.size(); i++){
		if(v[i] > 0){
			a.push_back(v[i]);
		}
	}
	return a;
}

vector<int> makeVector(int n){
	vector<int> a;
	for(int i = 0; i < n; i++){
		a.push_back(i);
	}
	return a;
}

