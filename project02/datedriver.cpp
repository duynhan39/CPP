// File: datedriver.cpp
// Duy Nhan Cao
// CS215

#include <iostream>
#include <string>
#include <stdexcept>
#include "date.h"

int main ()  // no command-line arguments
{
   using namespace std;

   Date date1;
   Date date2(10);
   Date date3(9,19);
   Date date4(9,19,2017);
   cout << "The dates: " << endl;
   cout << "Date 4 is " << date4 << endl;
   // Check function day_of_week and string_name
   cout << date4.day_of_week() << ", " << date4.string_name() << endl;
   cout << date1 << endl;
   // Check operator == < <= >= >
   if(date1==date3)
     cout << "Date 1 and Date 3 are the same!" << endl;
   cout << "Input date: ";
   cin >> date1;
   cout << endl;
   cout << date1.day_of_week() << ", " << date1.string_name() << endl;
   if(date1 < date4)
     cout << "Date 1 is ealier than date 4\n";
   else if(date1 <= date4)
     cout << "Date 1 is ealier than or the same as date 4\n";
   if(date1 > date4)
     cout << "Date 1 is later than date 4\n";
   else if(date1 >= date4)
     cout << "Date 1 is later than or equal date 4\n";
   if(date1 != date4)
     cout << "Date 1 is different from date 4\n";
   return 0;
}
