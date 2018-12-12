# myclass program Makefile

GCC = g++
CFLAGS = -g -Wall -w
OBJS = main.o

main: $(OBJS)
	$(GCC) $(OBJS) -o lab1

main.o: main.cpp main.h
	$(GCC) $(CFLAGS) -c main.cpp

clean:
	rm $(OBJS) lab1
