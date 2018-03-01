// File: point.h
// Definition of the Point class
// ----------------------------------------------------------------------
// Class: CS 215                      
// Assignment: Programming Practical Exam 1, Problem 2
// Programmer: Duy Nhan Cao
// Date: September 20, 2017

#ifndef POINT_H_
#define POINT_H_
#include <iostream>

class Point
{
   public:  // Operations

      // Constructors
      Point (double x_coor=0, double y_coor=0);

      // Accessors
      double x_coord () const;
      double y_coord () const;

      friend bool operator== (const Point & p1, const Point & p2);
      friend Point operator+ (const Point & p1, const Point & p2);
      
      friend std::istream & operator>> (std::istream & instream, Point & aPoint);
      friend std::ostream & operator<< (std::ostream & outstream, const Point & aPoint);
      
   private:  // Attributes

      double x, y;  // Coordinates for point (x,y)

};  // end Point class

#endif // POINT_H_
