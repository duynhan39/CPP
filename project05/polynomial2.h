// File: polynomial.h
//
// ----------------------------------------------------------
// Class: CS 215               Instructor: Dr. Deborah Hwang
// Assignment: Project 5       Date assigned:
// Programmer: Duy Nhan Cao    Date completed:

#ifndef POL2
#define POL2
#include <iostream>
#include <vector>

using namespace std;

class Polynomial
{
private:
#include "term.h"
public:
    
    Polynomial(); // Default constructor
    Polynomial(vector<int> initial_coefficients, vector<int> initial_exponents); // Explicit-value constructor
    Polynomial(const Polynomial &original) noexcept; // Copy constructor
    ~Polynomial(); // Destructor
    Polynomial operator= (const Polynomial & source);  // Overloaded operator=
    int degree() const;  // Returning the degree of the polynomial
    int evaluate(const int x) const;  // evaluate the polynomial at a particular point, return result
    friend Polynomial operator+ (const Polynomial & left_poly, const Polynomial & right_poly); // Friend operator+
    friend Polynomial operator* (const Polynomial & left_poly, const Polynomial & right_poly); // Friend operator*
    friend std::ostream & operator<< (std::ostream & out_stream, const Polynomial & a_poly);   // Friend operator<<
    friend std::istream & operator>> (std::istream & in_stream, Polynomial & a_poly);          // Friend operator>>
private:
    friend void removeZero(Polynomial::Term *&first);       // Putting new element in a polynomial in the correct order
    friend void insert_in_order(Polynomial::Term *&first, Polynomial::Term *curr); // Putting new element in a polynomial in the correct order
    Term *head;
};

#endif
