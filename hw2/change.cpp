//Duy Nhan Cao

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

//Define a new type of structure for result

void compute_change(int m, int& dollars, int& quarters, int& dimes, int& pennies);

int main (int argc, char * argv[])
{
    using namespace std;
    //Check for correct number of arguments
    if(argc!=3)
    {
        cout << "Usage: " <<argv[0]<<"<input file><outfile>" <<endl;
        exit(1);
    }
    //Open files
    ifstream inFile(argv[1]);
    ofstream outFile(argv[2]);
    //Check for successful opens
    if(!inFile)
    {
      cout<<"Error opening input file " << argv[1] <<endl;
      exit(1);
    }
    if(!outFile)
    {
      cout<<"Error opening output file " << argv[2] <<endl;
      exit(1);
    }
    int num;
    int dollars;
    int quarters;
    int dimes;
    int pennies;
    //Print out the header
    outFile << setw(10) << "Amount" << setw(10) << "Dollars" << setw(10) << "Quarters" << setw(10) << "Dimes" << setw(10) << "Pennies" << endl;
    outFile << endl;
    //Take one number at a time and print out the result
    while(inFile >> num)
    {
      compute_change(num, dollars, quarters, dimes, pennies);
      outFile << setw(10) << num << setw(10) << dollars << setw(10) << quarters << setw(10) << dimes << setw(10) << pennies << endl;  
    }
    return 0;
}

void compute_change(int m, int& dollars, int& quarters, int& dimes, int& pennies)
{
  dollars = m/100;
  m=m%100;
  quarters = m/25;
  m=m%25;
  dimes = m/10;
  m=m%10;
  pennies = m;
}
