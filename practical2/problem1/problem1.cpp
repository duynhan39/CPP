// File: problem1.cpp
// A program that tests exchange_sort
//
// Class: CS 215                     Instructor: Dr. Deborah Hwang
// Date: November 8 & 9, 2017
// Assignment: Practical Exam 2, Problem 1
// Programmer: Duy Nhan Cao

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

void read_vector (std::vector<int> & v, std::istream & in);
void write_vector (std::vector<int> & v, std::ostream & out);
void exchange_sort (std::vector<int> & v);

int main (int argc, char * argv[])
{
   using namespace std;

   if(argc!=3) {
     cout<<"Usage: "<<argv[0]<<"<input file><output file>"<<endl;
     exit(1);
   }
   ifstream infile(argv[1]);
   ofstream outfile(argv[2]);
   if(!infile) {
     cout<<"Error opening input file "<<argv[1]<<endl;
     exit(1);
   }
   if(!outfile) {
     cout<<"Error opening output file "<<argv[2]<<endl;
     exit(1);
   }
   // Read in data from file
   vector<int> the_vector;
   read_vector (the_vector, infile);

   cout << "The elements of vector v are: " << endl;
// *** WRITE CALL TO DISPLAY the_vector ON SCREEN HERE ***
   write_vector (the_vector, cout);

   // Sort the data
// *** WRITE CALL TO SORT the_vector HERE ***
   exchange_sort (the_vector);

   outfile << "\nAfter sorting, the elements of vector v are: " << endl;
// *** WRITE CALL TO WRITE the_vector TO OUTPUT FILE HERE ***
   write_vector (the_vector, outfile);
 
   return 0;
}

void read_vector (std::vector<int> & v, std::istream & in)
{
   int value;
   v.clear();
   while (in >> value)
      v.push_back(value);
}

void write_vector (std::vector<int> & v, std::ostream & out)
{
  for(int i=0; i<v.size(); i++)
    out<<v[i]<<std::endl;
}

void exchange_sort (std::vector<int> & v)
{
  for(int i=0; i<v.size()-1; i++)
    for(int j=i+1; j<v.size(); j++)
      if(v[i]>v[j])
	std::swap(v[i], v[j]);
}
