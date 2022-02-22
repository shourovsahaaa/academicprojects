/*
Author: Shourov Saha
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab6A

Illustrates the
Caesar Cipher Technique
using two functions:
shiftChar , encryptCaesar .
*/

#include <iostream> 
using namespace std; 
 

char shiftChar(char c, int rshift)
{
    if (isalpha(c))
        {
            if (isupper(c)) 
            {
                return char(int(c+rshift-65)%26 +65); 
            }
            else
            {
                return char(int(c+rshift-97)%26 +97); 
            }
        }
    else
    {
        return c;
    }
}

string encryptCaesar(string text, int rshift) 
{ 
    string result = ""; 
  
    
    for (int i=0;i<text.length();i++) 
    { 
        result += shiftChar(text[i], rshift);
    } 
  
    return result; 
} 
  
int main() 
{ 
    string text;
    cout << "Enter plaintext: ";
    getline(cin, text);
    cout << "Enter shift    : ";
    int rshift;
    cin >> rshift;
    cout << "Ciphertext     : " << encryptCaesar(text, rshift); 
    return 0; 
} 
