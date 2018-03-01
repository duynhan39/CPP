#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

//Define a new type of structure for result
typedef struct{
  int dollars;
  int quarters;
  int dimes;
  int pennies;
} change_t;

change_t compute_change(int m);

int main (int argc, char * argv[])
{
    using namespace std;
    
    //Open files
    ifstream inFile("input.dat");
    ofstream outFile("output.dat");

    //Check for successful opens
    if(!inFile)
    {
        cout<<"Error opening input file input.dat" <<endl;
        exit(1);
        
    }
    if(!outFile)
    {
        cout<<"Error opening output file output" <<endl;
        exit(1);
        
    }
    int num;
    change_t results;
    
    //Print out the header
    outFile << setw(10) << "Amount" << setw(10) << "Dollars" << setw(10) << "Quarters" << setw(10) << "Dimes" << setw(10) << "Pennies" << endl;

    //Take one number at a time and print out the result
    while(inFile >> num)
    {
      results = compute_change(num);
      outFile << setw(10) << num << setw(10) << results.dollars << setw(10) << results.quarters << setw(10) << results.dimes << setw(10) << results.pennies << endl;
        
    }

    return 0;

}

change_t compute_change(int m)
{
  change_t results;

  results.dollars = m/100;
  m=m%100;
  results.quarters = m/25;
  m=m%25;
  results.dimes = m/10;
  m=m%10;
  results.pennies = m;

  return results;
}
