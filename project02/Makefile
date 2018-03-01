# Duy Nhan Cao
datedriver: datedriver.o date.o
	clang++ -Wall -o datedriver datedriver.o date.o

# Compile with -g to retain debugging information
datedriver.o: datedriver.cpp date.h
	clang++ -std=c++11 -g -Wall -c datedriver.cpp

date.o: date.cpp date.h
	clang++ -std=c++11 -g -Wall -c date.cpp

clean:
	rm -f *.o datedriver *~
