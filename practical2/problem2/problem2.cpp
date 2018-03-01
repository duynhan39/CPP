// File: problem1.cpp
// Program to test SeatingChart class
//
// ----------------------------------------------------------------------
// Class: CS 215
// Date: November 8 & 9, 2017
// Assignment: Programming Practical Exam 2, Problem 2
// Programmer: Sample Solution

#include <iostream>
#include "chart.h"

int main ()
{
   using namespace std;

   SeatingChart chart1(10,4);

   // Charts to test copy constructor and operator=
   SeatingChart chart2 (chart1);
   SeatingChart chart3 (2, 2);  // construct 2x2
   chart3 = chart1;             // change to 10x4
   int row, seat;
   char command;

   cout << "Chart 1: (10x4)" << endl;
   chart1.write(cout);
   cout << "Chart 2: (10x4) should look the same as Chart 1" << endl;
   chart2.write(cout);
   cout << "Chart 3: (10x4) should look the same as Chart 1" << endl;
   chart3.write(cout);
   
   cout << "Do you want to check assignment (c), assign (a), unassigned (u),"
	<< " or quit (q): ";
   cin >> command;
   command = tolower(command);
   
   while (command != 'q')
   {
      cout << "Enter a row number and a seat number: ";
      cin >> row >> seat;

      if (command == 'a') {
	 cout << "Assigning this seat" << endl;
	 try {
	   chart1.assign(row, seat);
	 }
	 catch (const invalid_argument & er) {
	   cout<<er.what()<<"Try again!\n";
	 }
      } else if (command == 'u') {
	 cout << "Unassigning this seat" << endl;
	 try {
	   chart1.unassign(row, seat);
	 }
	 catch (const invalid_argument & er) {
	   cout<<er.what()<<"Try again!\n";
	 }
      } else if (command == 'c') {
	try {
	  cout << "This seat is ";
	  bool occup=chart1.is_assigned(row, seat);
	  if(occup)
	    cout<<"assigned"<<endl;
	  else
	    cout<<"unassigned"<<endl;
	}
	catch (const invalid_argument & er) {
	   cout<<er.what()<<"Try again!\n";
	}

      } else {
	 cout << "Unknown command.  Try again." << endl;
      }

      cout << "Chart 1: (10x4)" << endl;
      chart1.write(cout);
      cout << "Charts 2 and 3 should not change" << endl;
      cout << "Chart 2: (10x4)" << endl;
      chart2.write(cout);
      cout << "Chart 3: (10x4)" << endl;
      chart3.write(cout);
   
      cout << "Do you want to check assignment (c), assign (a), unassigned (u),"
	<< " or quit (q): ";
      cin >> command;
      command = tolower(command);
   }
   return 0;
}  // end main
