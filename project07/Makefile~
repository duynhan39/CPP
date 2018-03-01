# File: Makefile
# Class: CS 215			Instructor: Dr. Deborah Hwang
# Assignment: Project 5 	Date assigned: Oct 25
# Programmer: Duy Nhan Cao	Date completed: Nov 8


polycalc2: polycalc2.o polynomial2.o
	clang++ -Wall -o polycalc2 polycalc2.o polynomial2.o

# Compile with -g to retain debugging information
polycalc2.o: polycalc2.cpp polynomial2.h
	clang++ -std=c++11 -g -Wall -c polycalc2.cpp

polynomial2.o: polynomial2.cpp polynomial2.h
	clang++ -std=c++11 -g -Wall -c polynomial2.cpp
clean:
	rm -f *.o polycalc2 *~
