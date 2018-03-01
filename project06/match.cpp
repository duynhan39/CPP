// File: match.cpp
//
// ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
// Class: CS 215		Instructor: Dr. Deborah Hwang
// Assignment: Project 6 	Date assigned: Nov 9
// Programmer: Duy Nhan Cao	Date completed: Nov 20

#include<iostream>
#include<stack>
#include<string>
#include<fstream>
using namespace std;

const string DELI = "({[]})";

// Function: convert, converting delimiters into its index in DELI string
void convert(int *num, char *ch, bool ltr);

int main(int argc, char *argv[])
{
    // 1. Check for correct number of arguments
    if(argc!=2)
    {
        cout << "Usage: " <<argv[0]<<"<input file>" <<endl;
        exit(1);
    }
    // 2. Open files
    
    ifstream inFile(argv[1]);
    
    // 3. Check for successful opens
    if(!inFile)
    {
        cout<<"Error opening input file" << argv[1]<<endl;
        exit(1);
    }
    stack<int> delim;
    int num;
    char del;
    char in;
    while(inFile>>in)
    {
        if(DELI.find(in)!=string::npos)
        {
            convert(&num, &in, false);
            delim.push(num);
        }
    }
    stack<int> delim2;
    while(1)
    {
        if(delim.empty() && delim2.empty())
        {
            cout<<"All delimiters match."<<endl;
            return 0;
        }
	if(delim.empty() && !delim2.empty())
        {
            convert(&delim2.top(), &del, true);
            cout<<"Extra delimiter "<<del<<" found."<<endl;
            return 0;
        }
	if(delim.top()>2)
        {
            delim2.push(delim.top());
            delim.pop();
        }
        else if(!delim.empty() && delim2.empty())
        {
            convert(&delim.top(), &del, true);
            cout<<"Extra delimiter "<<del<<" found."<<endl;;
            return 0;
        }
        else if(delim.top()+delim2.top()==5)
        {
            delim.pop();
            delim2.pop();
        }
        else
        {
            char del2;
            delim.top()=5-delim.top();
            convert(&delim2.top(), &del2, true);
            convert(&delim.top(), &del, true);
            cout<<"Mismatched delimiter "<<del2<<" found. Expecting delimiter "<<del<<"."<<endl;
            return 0;
        }   
    }
    inFile.close();
    return 0;
}

// Function: convert, converting delimiters into its index in DELI string
void convert(int *num, char *ch, bool ltr)
{
    if(ltr)
    {
        *ch=DELI[*num];
    }
    else
        for(int i=0; i<6; i++)
            if(DELI[i]==*ch)
            {
                *num=i;
                break;
            }
}
