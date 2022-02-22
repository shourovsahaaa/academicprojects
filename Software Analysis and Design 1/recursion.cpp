/*
Author: Shourov Saha
Course: CSCI-135/6
Instructor: Melissa Lynch
Assignment: Lab 13F

Prints all numbers in range
left ≤   x   ≤ right,
separated by spaces.

A function that computes
the sum of all numbers
in range left ≤   x   ≤ right.

A new function which receives
an array (as a pointer to its first element)
and the size of the array,
and should return the sum
of its elements.

A new function which returns true
if all characters in the string
are letters and digits,
otherwise returns false.

A function which returns true
if the collection is divisible,
and false otherwise. The prices
are provided in the array prices,
and size is the number of items 
in the array.
*/

#include <iostream>
using namespace std;



bool helpParens(string s)
{
	return (s[0] == '(') && (s[s.size() - 1] == ')');
}

bool nestedParens(string s)
{
	if (s.size() == 1)
	{
		return false;
	}
	if (s == "")
	{
		return true;
	}
	return helpParens(s) && nestedParens(s.substr(1, s.size() - 2));
}

bool isAlphanumeric(string s)
{
	if (s == "")
	{
		return true;
	}
	return isalnum(s[0]) && isAlphanumeric(s.substr(1));
}


int sumArray(int *arr, int size)
{
	if (size == 1)
	{
		return arr[0];
	}
	return arr[0] + sumArray(&arr[1], size - 1);

}

int sumRange(int left, int right)
{
	if (left == right)
	{
		return left;
	}
	else if (left > right)
	{
	    return 0;
	}
	return left + sumRange(left + 1, right);
}

void printRange(int left, int right)
{
    if (left <= right)
    {
        cout << left<< " ";
        printRange(left + 1, right);
    }
}

bool helper (int prices[], int size, int sum)
{
    if (sum == 0)
    {
        return true;
    }
    if (size == 0 && sum != 0)
    {
        return false;
    }

    if (prices[size-1] > sum)
    {
    return helper (prices, size-1, sum);
    }

    return helper (prices, size-1, sum) || helper (prices, size-1, sum-prices[size-1]);
}

bool divisible (int *prices, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += prices[i];
    }

    if (sum%2 != 0)
    {
        return false;
    }
    
    return helper (prices, size, sum/2);
}


int main()
{
    int prices[] = {10, 15, 12, 18, 19, 17, 13, 35, 33};
    int n = sizeof(prices)/sizeof(prices[0]);
    
    if (divisible(prices, n) == true)
    {
        cout<<"Can be divided into two subsets.\n";
    }
    else
    {
        cout<<"Cannot be divided into two subsets\n";
    }
    
    return 0;
}