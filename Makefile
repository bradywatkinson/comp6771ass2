CC=g++
CFLAGS=-std=c++11 -Wall -Werror -O2


ECtest: ECtest.o EuclideanVector.o
	$(CC) ECtest.o EuclideanVector.o -o ECtest

ECtest.o: ECtest.cpp EuclideanVector.h
	$(CC) $(CFLAGS) -c ECtest.cpp
	
EuclideanVector.o: EuclideanVector.cpp EuclideanVector.h
	$(CC) $(CFLAGS) -c EuclideanVector.cpp

clean:
	rm *.o ECtest
