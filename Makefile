CC=g++
CFLAGS=-std=c++11 -Wall -Werror


EuclideanVector: EuclideanVector.o ECTest.cpp
		$(CC) $(CFLAGS) -o EuclideanVector EuclideanVector.o ECTest.cpp

EuclideanVector.o: EuclideanVector.cpp EuclideanVector.h
		$(CC) $(CFLAGS) -c EuclideanVector.cpp
