# File: Makefile
# Duy Nhan Cao

problem2: problem2.o chart.o
	clang++ -Wall -o problem2 problem2.o chart.o

problem2.o: problem2.cpp chart.h
	clang++ -std=c++11 -g -Wall -c problem2.cpp

chart.o: chart.cpp chart.h
	clang++ -std=c++11 -g -Wall -c chart.cpp
clean:
	rm -f *.o problem2 *~
