// File: coder.cpp
//
// ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
// Class: CS 215		Instructor: Dr. Deborah Hwang
// Assignment: Project 7 	Date assigned: Nov 20
// Programmer: Duy Nhan Cao	Date completed: Dec 4

#include "morse.h"
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
    // Check for correct number of arguments
    if(argc!=2)
    {
        cout << "Usage: " <<argv[0]<<"<input file>" <<endl;
        exit(1);
    }
    // Open files 
    ifstream codeFile(argv[1]);
    // Check for successful opens
    if(!codeFile)
    {
        cout<<"Error opening input file" << argv[1]<<endl;
        exit(1);
    }
    MorseTree tree(codeFile);
    tree.write(cout);
    while(1)
    {
        cout<<"\nPlease choose one of:\n"<<endl;
        cout<<"   E - Encode a message\n";
        cout<<"   D - Decode a message\n";
        cout<<"   Q - Quit the program\n";
        cout<<"\nEnter your choice: ";
        char command;
        string inName, outName;
        cin>>command;
        switch (toupper(command))
        {
            case 'E' :
                try
            {
                cout<<"Enter the name of a plaintext message file: ";
                cin>>inName;
                cout<<"Enter name of output file: ";
                cin>>outName;
                ifstream messFile(inName);
                ofstream encodedFile(outName);
                if(!messFile)
                    throw runtime_error ("Cannot open file.");
                if(!encodedFile)
                    throw runtime_error ("Cannot open file.");
                tree.encode(messFile, encodedFile);
                messFile.close();
                encodedFile.close();
            }
                catch (runtime_error &er)
            {
                cout<<er.what()<<" Try again!\n";
            }
                break;
                
            case 'D' :
                try
            {
                cout<<"Enter the name of an encoded message file: ";
                cin>>inName;
                cout<<"Enter name of output file: ";
                cin>>outName;
                ifstream inFile(inName);
                ofstream decodedFile(outName);
                if(!inFile)
                    throw runtime_error ("Cannot open file.");
                if(!decodedFile)
                    throw runtime_error ("Cannot open file.");
                tree.decode(inFile, decodedFile);
                inFile.close();
                decodedFile.close();
            }
                catch (runtime_error &er)
            {
                cout<<er.what()<<" Try again!\n";
            }
                break;
                
            case 'Q' :
                return 0;
        }
    }
    return 0;
}
