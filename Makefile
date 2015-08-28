CC=g++
CFLAGS=-std=c++11 -Wall -Werror -O2

All: ECtest2 ECtest3 ECtest4

ECtest4: ECtest4.o EuclideanVector.o
	$(CC) $(CFLAGS) ECtest4.o EuclideanVector.o -o ECtest4

ECtest4.o: ECtest4.cpp EuclideanVector.h
	$(CC) $(CFLAGS) -c ECtest4.cpp

ECtest3: ECtest3.o EuclideanVector.o
	$(CC) $(CFLAGS) ECtest3.o EuclideanVector.o -o ECtest3

ECtest3.o: ECtest3.cpp EuclideanVector.h
	$(CC) $(CFLAGS) -c ECtest3.cpp

ECtest2: ECtest2.o EuclideanVector.o
	$(CC) $(CFLAGS) ECtest2.o EuclideanVector.o -o ECtest2

ECtest2.o: ECtest2.cpp EuclideanVector.h
	$(CC) $(CFLAGS) -c ECtest2.cpp
	
EuclideanVector.o: EuclideanVector.cpp EuclideanVector.h
	$(CC) $(CFLAGS) -c EuclideanVector.cpp

clean:
	rm *.o
