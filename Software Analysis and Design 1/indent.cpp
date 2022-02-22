/*
Author: Shourov Saha
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab7B

Removes 
leading 
spaces
in code. 
Makes 
the 
code
have 
no 
spaces
and
indents
the code
appropriately.
*/
#include<iostream>
#include<cctype>

using namespace std;

string removeLeadingSpaces (string line);

int countChar(string line, char c);

void indent (string text);
int main()
{
    string line;
    /*
    while (getline(cin, line)){
            cout << removeLeadingSpaces(line) << endl;
    }
    */
    indent(line);
}


void indent (string line)
{
    string indented_line;
    int open_blocks =0;
    int opening_braces =0;
    int closing_braces =0;
    int indentation_level =0;

    while (getline (cin, line))
    {
        indented_line= removeLeadingSpaces(line);
        indentation_level = open_blocks;
        if (indented_line[0] == '}')
        {
            indentation_level = open_blocks - 1;
        }
        for (int i = 0; i < indentation_level; i++)
        {
            cout << "\t";
        }
        opening_braces = countChar(indented_line,'{');
        closing_braces = countChar(indented_line,'}');
        open_blocks += (opening_braces - closing_braces);
        cout << indented_line << endl;
    }
}


int countChar(string line, char c)
{
    int counter = 0;

    for (int i = 0; i < line.length(); i++)
    {
        if (line [i] == c)
        {
            counter++;
        }
    }
    return counter;
}


string removeLeadingSpaces(string line)
{
    bool leading_spaces_found = true;
    string unindented_line;
    for (int i = 0; i < line.length(); i++)
    {
        if(!isspace(line[i]))
        {
            leading_spaces_found = false;
        }
        if (!leading_spaces_found)
        {
            unindented_line += line[i];
        }
    }
    return unindented_line;
}