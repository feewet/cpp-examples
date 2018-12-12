# myclass program Makefile

GCC = g++
CFLAGS = -g -Wall -w -std=c++11
OBJS = main.o Car.o CarLinkedList.o DynamicCarArray.o QuickSortCars.o Question1.o Question2.o 

Car.o: Car.cpp Car.h
	$(GCC) $(CFLAGS) -c Car.cpp

QuickSortCars.o: QuickSortCars.cpp QuickSortCars.h
	$(GCC) $(CFLAGS) -c QuickSortCars.cpp

CarLinkedList.o: CarLinkedList.cpp CarLinkedList.h
	$(GCC) $(CFLAGS) -c CarLinkedList.cpp

DynamicCarArray.o: DynamicCarArray.cpp DynamicCarArray.h
	$(GCC) $(CFLAGS) -c DynamicCarArray.cpp

Question1.o: Question1.cpp
	$(GCC) $(CFLAGS) -c Question1.cpp

Question2.o: Question2.cpp
	$(GCC) $(CFLAGS) -c Question2.cpp

main: $(OBJS)
	$(GCC) $(OBJS) -o main

main.o: main.cpp
	$(GCC) $(CFLAGS) -c main.cpp
	
clean:
	rm $(OBJS) main