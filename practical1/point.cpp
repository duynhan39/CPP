// File: point.cpp
// Implementation of the Point class operations
// ----------------------------------------------------------------------
// Class: CS 215                      
// Assignment: Programming Practical Exam 1, Problem 2
// Programmer: Duy Nhan Cao
// Date: Septebmer 20, 2017

#include "point.h"
#include <iostream>
#include <cstdlib>
#include <sstream>

// Constructors
Point::Point(double x_coor, double y_coor) : x(x_coor), y(y_coor)
{

}

// Accessors
double Point::x_coord () const
{
   return x;
}  // end get_x

double Point::y_coord () const
{
   return y;
}  // end get_y

bool operator== (const Point & p1, const Point & p2)
{
  if(p1.x_coord()==p2.x_coord() && p1.y_coord()==p2.y_coord())
    return true;
  else
    return false;
}

Point operator+ (const Point & p1, const Point & p2)
{
  return Point(p1.x_coord()+p2.x_coord(), p1.y_coord()+p2.y_coord());
}

std::istream & operator>> (std::istream & inStream, Point & aPoint)
{
  double x_c=0, y_c=0;
  if(inStream.peek()=='(')
    {
      inStream.ignore();
      inStream>>x_c;
      if(inStream.fail())
	return inStream;
    }
   if(inStream.peek()==',')
    {
      inStream.ignore();
      inStream>>y_c;
      if(inStream.fail())
	return inStream;
    }
   if(inStream.peek()==')')
     inStream.ignore();
   
   aPoint.x=x_c;
   aPoint.y=y_c;
   return inStream;
}

std::ostream & operator<< (std::ostream & outStream, const Point & aPoint)
{
  outStream << '(' << aPoint.x << ',' << aPoint.y << ')';
  return outStream;
}
