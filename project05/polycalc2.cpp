// File: polycalc2.cpp
//  menu­driven, interactive polynomial calculator
//
// ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
// Class: CS 215		Instructor: Dr. Deborah Hwang
// Assignment: Project 5 	Date assigned: Oct 25
// Programmer: Duy Nhan Cao	Date completed: Nov 8


#include "polynomial2.h"  // Polynomial Class
#include <iostream>      // operator >> and <<
using namespace std;
void comList();
int main()
{
    Polynomial P, P2;
    while(1)
    {
        bool quit=false;
        comList();
        char command;
        cin>>command;
        switch (toupper(command))
        {
            case 'I':
                cout<<"Enter a new current polynomial: ";
                cin>>P;
                break;
            case 'P':
                cout<<"The current polynomial is: "<<P<<endl;
                break;
            case 'D':
                cout<<"The degree of the current polynomial is: "<<P.degree()<<endl;
                break;
            case 'E':
                cout<<"Enter a number: ";
                double n;
                cin>>n;
                cout<<"The current polynomial evaluated at "<<n<<" is: "<<P.evaluate(n)<<endl;
                break;
            case 'A':
                cout<<"Enter a second polynomial: ";
                cin>>P2;
                cout<<"The resulting polynomial is: "<<P+P2<<endl;
                break;
            case 'M':
                cout<<"Enter a second polynomial: ";
                cin>>P2;
                cout<<"The resulting polynomial is: "<<P*P2<<endl;
                break;
            case 'Q':
                quit=true;
                cout<<"Bye!!\n";
                break;
        } // end handling input
        if(quit==true)
            break;
        cout<<endl;
    }
    
}

void comList()
{
    cout<<"Choose from the following commands:\n"
    <<"   I ­ Enter a new current polynomial\n"
    <<"   P ­ Display (i.e., print) the current polynomial to the screen\n"
    <<"   D ­ Display the degree of the current polynomial\n"
    <<"   E ­ Enter a real number, then evaluate the current polynomial at that number and display the result\n"
    <<"   A ­ Enter a second polynomial, then display the sum of this polynomial and the current polynomial\n"
    <<"   M ­ Enter a second polynomial, then display the product of this polynomial and the current polynomial\n"
    <<"   Q ­ Quit the calculator\n\n"
    <<"Enter your command: ";
}
