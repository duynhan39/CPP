// Duy Nhan Cao
// CS215
// File: date.h

#ifndef DATE_H_
#define DATE_H_
#include <iostream>

class Date
{
 public:
      Date(int m=1, int d=1, int y=2017);          // Explicit value constructor: mm/dd/yyyy
   
      int month() const;         // return month
      int day() const;           // return day
      int year() const;          // return year
      std::string string_name() const;      // return date in string form
      std::string day_of_week() const;      // rerurn the day of week
      
      friend bool operator== (const Date & lhs, const Date & rhs);
      friend bool operator< (const Date & lhs, const Date & rhs);
      friend bool operator<= (const Date & lhs, const Date & rhs);
      friend bool operator> (const Date & lhs, const Date & rhs);
      friend bool operator>= (const Date & lhs, const Date & rhs);
      friend bool operator!= (const Date & lhs, const Date & rhs);
      
      // I/O operators
      // ostream is the type of cout, it is the lhs parameter
      // The actual ostream, object is returned, so the return type is ostream &, a reference to the returned object
      friend std::istream & operator>> (std::istream & instream, Date & aDate);
      friend std::ostream & operator<< (std::ostream & outstream, const Date & aDate);
 private:
      int mm, dd, yyyy;      // dd, mm, yyyy
      void reduce();
};

#endif
