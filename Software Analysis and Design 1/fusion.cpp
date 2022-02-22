/*
Author: Shourov Saha
Course: CSCI-135/6
Instructor: Melissa Lynch
Assignment: Lab 12C 

A program called fusion.cpp
that implements the function 
void gogeta(vector<int> &goku, vector<int> &vegeta) 
that appends elements of the
second vector into the first and 
empties the second vector.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> makeVector(int n);
vector<int> goodVibes(const vector<int> v);
void gogeta(vector<int> &goku, vector<int> &vegeta);

int main(){

	vector<int> v1{1,2,3};
	vector<int> v2{4,5};
	gogeta(v1,v2);
	for( int i = 0; i < v1.size(); i++){
		cout << v1[i] << " ";
	}
	cout << endl;

}



void gogeta(vector<int> &goku, vector<int> &vegeta){
	for(int i = 0; i < vegeta.size(); i++){
		goku.push_back(vegeta[i]);
	}
	vegeta.clear();
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
