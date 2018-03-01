
// A program to copy a textfile one character at a time

#include <iostream>
#include <fstream>
#include <cstdlib>   // exit()

int main (int argc, char * argv[])
{
    using namespace std;
    
    // 1. Check for correct number of arguments
    if(argc!=4)
    {
        cout << "Usage: " <<argv[0]<<"<input file><outfile>" <<endl;
        exit(1);
    }
    // 2. Open files
    
    ifstream inFile(argv[1]);
    ofstream outFile(argv[2]);
    int shift = stoi(argv[3]);
    
    // 3. Check for successful opens
    if(!inFile)
    {
        cout<<"Error opening input file" << argv[1]<<endl;
        exit(1);
        
    }
    if(!outFile)
    {
        cout<<"Error opening output file" << argv[2]<<endl;
        exit(1);
        
    }
    // 4. Copy one character at a time by
    //    Reading a char until stream fails (usually EOF)
    char ch;
    while(inFile.get(ch))
    {
        //    4.1 Write char to output file
        if(isalpha(ch))
        {
            if(isupper(ch))
                ch = (((ch - 'A') + shift) % 26) + 'A';
            else
                ch = (((ch - 'a') + shift) % 26) + 'a';
        }
        outFile << ch;
    }
    // 5. Close files
    inFile.close();
    outFile.close();
    
    return 0; 
} // end main
