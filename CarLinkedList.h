// CarLinkedList.h

#ifndef CARLINKEDLIST_H_
#define CARLINKEDLIST_H_

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
		CarLinkedList getCarsByYear(); // return cars sorted by year
		void add(Car c); // Add Car
		int length(); // return linked list length
		bool isEmpty(); // return true if empty
		Car get(int n); // get Car at n
		Car remove(int n); // Remove Car at n
		Car* toArray();
		void copy(Car* cars);
};

#endif