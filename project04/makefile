# File: Makefile
# Class: CS 215			Instructor: Dr. Deborah Hwang
# Assignment: Project 4 	Date assigned: Oct 13 2017
# Programmer: Duy Nhan Cao      Date completed: Oct 23 2017


image_manipulator: image_manipulator.o image.o
	clang++ -Wall -o image_manipulator image_manipulator.o image.o

# Compile with -g to retain debugging information
image_manipulator.o: image_manipulator.cpp image.h
	clang++ -std=c++11 -g -Wall -c image_manipulator.cpp

image.o: image.cpp image.h
	clang++ -std=c++11 -g -Wall -c image.cpp
clean:
	rm -f *.o image_manipulator *~
