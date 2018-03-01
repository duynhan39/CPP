# File: Makefile
# Class: CS 215			Instructor: Dr. Deborah Hwang
# Assignment: Project 7 	Date assigned: 
# Programmer: Duy Nhan Cao	Date completed: 


coder: coder.o morse.o
	clang++ -Wall -o coder coder.o morse.o

# Compile with -g to retain debugging information
coder.o: coder.cpp morse.h
	clang++ -std=c++11 -g -Wall -c coder.cpp

morse.o: morse.cpp morse.h
	clang++ -std=c++11 -g -Wall -c morse.cpp
clean:
	rm -f *.o coder *~
