// File: problem2.cpp
// A program to test the Point class
// ----------------------------------------------------------------------
// Class: CS 215                      
// Assignment: Programming Practical Exam 1, Problem 2
// Programmer: <FILL IN YOUR NAME!!>
// Date: September 20, 2017

#include <iostream>      // <<, >>, endl;
#include "point.h"       // Point class
#include <cmath>
#include <cstdlib>
#include <sstream>


double distance_between(const Point & p1, const Point & p2);

int main ()  // no command line arguments
{
   using namespace std;
   Point p1;             //  Default constructed: (0,0)
   Point p2(0);
   Point p3(4,3);

   cout << "Default constructed point\n";
   cout << "   x-coordinate: " << p1.x_coord() << endl;
   cout << "   y-coordinate: " << p1.y_coord() << endl;

   cout << "Point with one given argument\n";
   cout << "   x-coordinate: " << p2.x_coord() << endl;
   cout << "   y-coordinate: " << p2.y_coord() << endl;

   cout << "Point with two given arguments\n";
   cout << "   x-coordinate: " << p3.x_coord() << endl;
   cout << "   y-coordinate: " << p3.y_coord() << endl;

   cout << "Distance between point 1 and point 3 is ";
   cout << distance_between(p1, p3) << endl;

   if(p1==p2)
     cout << "Point 1 and 2 are the same\n";

   cout << "Input point 4\n";
   Point p4;
   cin >> p4;
   cout << p4 << endl;
   Point p5=p4+p3;
   cout << "p4 + p3 = ";
   cout << p5 << endl;

   cout << "Sum of two points\n";
   cout << "   x-coordinate: " << p5.x_coord() << endl;
   cout << "   y-coordinate: " << p5.y_coord() << endl;

   return 0;
}  // end main

double distance_between(const Point & p1, const Point & p2)
{
  return sqrt(pow(p1.x_coord()-p2.x_coord(), 2)+pow(p1.y_coord()-p2.y_coord(), 2));
}
