CC=g++
CFLAGS=-std=c++11 -Wall -Werror -O2

ECtest2: ECtest2.o EuclideanVector.o
	$(CC) $(CFLAGS) ECtest2.o EuclideanVector.o -o ECtest2

ECtest2.o: ECtest2.cpp EuclideanVector.h
	$(CC) $(CFLAGS) -c ECtest2.cpp
	
EuclideanVector.o: EuclideanVector.cpp EuclideanVector.h
	$(CC) $(CFLAGS) -c EuclideanVector.cpp

clean:
	rm *.o ECtest
