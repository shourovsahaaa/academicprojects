/*
Author: Shourov Saha
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab5D

****************************
Checks
if integer n is divisible
by integer d using the function
isDivisibleBy(n, d);
****************************
Checks
if integer n is prime
using the function 
isPrime(n);
****************************
Find the next prime number
after a, using the function
nextPrime(a);
****************************
Counts the number
of prime numbers between
a and b using the function
countPrimes(int a, int b);
****************************
Checks if a prime number, a,
is a twin prime suing the fuction
isTwinPrime(a);
*/
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

bool isDivisibleBy(int n, int d)
{
    if (d == 0)
    {
        return false;
    }
    if (n % d == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int nextPrime(int n)
{
    for (int i = n + 1; i > n ;i++)
    {
        if (isPrime(i) == true)
        {
            return i;
        }
    }
}

int countPrimes(int a, int b)
{
    int x = 0;
    for (int i = a ; i <= b ; i++)
    {
        if (isPrime(i) == true)
        {
            x = x + 1;
        }
    }
    return x;
}

bool isTwinPrime(int n)
{
    if (isPrime(n) == false)
    {
        return false;
    }
    else if (isPrime(n + 2) == true)
    {
        return true;
    }
    else if (isPrime(n - 2) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int nextTwinPrime(int n)
{
    for (int i = n + 1 ; i > n ; i++)
    {
        if (isTwinPrime(i) == true)
        {
            return i;
        }
    }
}

int largestTwinPrime(int a, int b)
{
    for (int i = b ; i >= a ; i --)
    {
        if (isTwinPrime(i)== true)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    cout << "a = ";
    int a;
    cin >> a;
    cout << nextPrime(a);

    return 0;
}