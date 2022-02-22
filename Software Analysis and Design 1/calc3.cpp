/******************************************************************************
Shourov
Saha
Project 1D
Lynch
Tong Yi
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int numbers;
    int sum = 0;
    char op = '+';
    char post_op;
    int value;
    while (cin>>numbers){
      cin >> post_op;
      if (post_op == '^'){
          value = numbers * numbers; // instead of adding the raw input we put it through the value integer so we can subtract squared numbers instead of always adding.
      }
      else{
          value = numbers;
          cin.putback(post_op);
      }
      if (op == ';'){ 
          cout<<sum<<endl;
          sum = 0;
          op = '+';      //resets previous values of char is ;
      }
      if (op == '+'){
          sum += value;
      }
     else if (op == '-'){
          sum -= value;
    }
    do{
        cin>>op;

    }
    while (op == ' '); // skips spaces

    } 


    cout<<sum<<endl;


}