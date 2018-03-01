# File: Makefile
# Class: CS 215			Instructor: Dr. Deborah Hwang
# Assignment: Project 3 	Date assigned: Sep 27
# Programmer: Duy Nhan Cao	Date completed: Oct 10


polycalc: polycalc.o polynomial.o
	clang++ -Wall -o polycalc polycalc.o polynomial.o

# Compile with -g to retain debugging information
polycalc.o: polycalc.cpp polynomial.h
	clang++ -std=c++11 -g -Wall -c polycalc.cpp

polynomial.o: polynomial.cpp polynomial.h
	clang++ -std=c++11 -g -Wall -c polynomial.cpp
clean:
	rm -f *.o polycalc *~
