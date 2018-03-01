// File: chart.cpp
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

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "chart.h"

using namespace std;

// Explict-value constructor
// Creates dynamic 2D "array" of seats
SeatingChart::SeatingChart (int init_rows, int init_seats)
{
   num_rows = init_rows;
   num_seats = init_seats;
   seat_array = new bool[init_rows*init_seats];
   for(int i=0; i<init_rows*init_seats; i++)
     seat_array[i]=false;

}  // end explicit-value constructor

SeatingChart::~SeatingChart()
{ delete [] seat_array; }

SeatingChart::SeatingChart(const SeatingChart &original) noexcept
{
  num_rows=original.num_rows;
  num_seats=original.num_seats;
  seat_array=new bool[num_rows*num_seats];
  for(int i=0; i<num_rows*num_seats; i++)
    seat_array[i]=original.seat_array[i];
}

SeatingChart SeatingChart::operator= (const SeatingChart &original)
{
  SeatingChart copy(original);
  num_rows=copy.num_rows;
  num_seats=copy.num_seats;
  swap(seat_array, copy.seat_array);
  return *this;
}

bool SeatingChart::is_assigned(int row, int seatNum)
{
  if(row>=num_rows || seatNum>= num_seats)
    throw invalid_argument ("Index out of range.");
  return seat_array[row*num_seats+seatNum];
}

// Function: assign
// assigns seat numbered seatNum in row numbered row
void SeatingChart::assign (int row, int seatNum)
{
  if(row>=num_rows || seatNum>= num_seats)
    throw invalid_argument ("Index out of range.");
  seat_array[row*num_seats+seatNum] = true;
}  // end assign


// Function: unassign
// unassigns seat numbered seat_num in row numbered row
void SeatingChart::unassign (int row, int seatNum)
{
  if(row>=num_rows || seatNum>= num_seats)
    throw invalid_argument ("Index out of range.");
  seat_array[row*num_seats+seatNum] = false;
}  // end unassign

// Function: write
// Prints out X if the seat is assigned, 0 if seat is not assigned
void SeatingChart::write (std::ostream & out)
{
   for (int i = 0; i < num_rows; i++)
   {
      for (int j = 0; j < num_seats; j++)
         if (seat_array[i*num_seats+j])
            out << " X";
         else
            out << " O";
      out << std::endl;
   }  // end for each row
}  // end write
