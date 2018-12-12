// CarLinkedList.h

#ifndef CARLINKEDLIST_H_
#define CARLINKEDLIST_H_
#include "Car.h"

// Struct to store Cars
struct node {
	Car car;
	node *next;
};

// Stores Car LinkedList and functions
class CarLinkedList{
	private:
		node *head;
		node *tail;
		int size;
	public:
		CarLinkedList(); // Default Constructor
		~CarLinkedList(); // Destructor
		void print(); // Print list
		CarLinkedList getCarByYear();
		void add(Car c); // Add Car
		Car get(int n); // get Car at n
		Car remove(int n); // Remove Car at n
		Car* getArray();
		void copy(Car* cars);
};

#endif