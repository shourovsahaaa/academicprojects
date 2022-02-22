/*
Author: Shourov Saha
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab6C

Illustrates the
Vigenere encryption technique
using two functions:
shiftChar , encryptVigenere.
comment
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

string encryptVigenere(string plaintext, string keyword)
{
    string result = "";
    int x = 0;
    for (int i = 0; i <= 10 ; i++)
    {
        keyword += keyword;
    }
    for (int i = 0; i < plaintext.size(); i++)
    {
        if (isalpha(plaintext[i]))
        {
        int cshift = int(char(keyword[x])) - 97;
        result += shiftChar(plaintext[i], cshift);
        x += 1;
        }
        else
        {
        result += plaintext[i];
        }
        
    }
    return result;
}

int main() 
{ 
    string text;
    cout << "Enter plaintext: ";
    getline(cin, text);
    cout << "Enter keyword  : ";
    string word;
    cin >> word;
    cout << "Ciphertext     : " << encryptVigenere(text, word); 
    return 0; 
} 