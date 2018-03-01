// File: polycalc.cpp
//  menu­driven, interactive polynomial calculator
//
// ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
// Class: CS 215		Instructor: Dr. Deborah Hwang
// Assignment: Project 3 	Date assigned: Sep 27
// Programmer: Duy Nhan Cao	Date completed: Oct 10

#ifndef POL_H_
#define POL_H_
#include <iostream>    // operator >> and <<
#include <vector>      // vector

class Polynomial
{
public:
  // Constructors
  Polynomial(std::vector<int> initial_coefficients={0}, std::vector<int> initial_exponents={0}); // Create a polynomial with value of 0
  // Accessors
  int degree() const; // Return polynomial's degree
  double evaluate(double x) const; // Return evaluation of the polynomial
  // Friend operators
  friend Polynomial operator+ (const Polynomial lhs_poly, const Polynomial rhs_poly); // Add up polynomials
  friend Polynomial operator* (const Polynomial lhs_poly, const Polynomial rhs_poly); // Multiple polynomials
  // Free overload I/O operators
  friend std::istream & operator>> (std::istream & in_stream, Polynomial & a_poly);
  friend std::ostream & operator<< (std::ostream & out_stream, const Polynomial & a_poly);
private:
  std::vector<int> coefficients;  // Polynomial's coefficients
};

#endif
