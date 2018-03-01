// File: chart.h
// Skeleton class that models rectangular seating charts using 
// dynamic one-dimensional array of booleans.  
//    - seats[i][j] maps to seat_array[i*num_seats+j]
//    - seats[i][j] == false means seat is unassigned
//    - seats[i][j] == true means seat is assigned
//
// Row numbers are 0 ... num_rows-1
// Seat numbers are 0 ... num_seats-1
// ----------------------------------------------------------------------
// Class: CS 215
// Date: November 8 & 9, 2017
// Assignment: Programming Practical Exam 2, Problem 2
// Programmer: Duy Nhan Cao

#ifndef _CHART_H_
#define _CHART_H_

#include <iostream>

class SeatingChart
{
  public:  // No default constructor on purpose
   SeatingChart (int init_rows, int init_seats);
   ~SeatingChart();
   SeatingChart(const SeatingChart &original) noexcept;
   SeatingChart operator= (const SeatingChart &original);
   bool is_assigned(int r, int c);
   void assign (int row, int seat_num);
   void unassign (int row, int seat_num);
   void write (std::ostream & out);

  private:
   int num_rows,     // number of rows
      num_seats;     // number seats in each row
   bool *seat_array;

};

#endif
