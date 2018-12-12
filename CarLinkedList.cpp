// CarLinkedList.cpp

#ifndef CARLINKEDLIST_H_
#include "CarLinkedList.h"

// Constructor
CarLinkedList::CarLinkedList() {
	size = 0;
	head = 0;
	tail = 0;
	head->next = tail;
}

// Destructor
CarLinkedList::~CarLinkedList() {
	node *c = head;
	node *previous = 0;
	while(c != 0) {
		previous = c;
		c = c->next;
		delete previous;
	}
	head = 0;
	tail = 0;
}

// Print list
void CarLinkedList::print() {
	cout << "Printing...\n";
	if (size == 0) {
		cout << "print(): Array is Empty";
	}
	else {
		node *c = head;
		while(c != 0) {
			cout << c->car.getMake() << " " << c->car.getModel() << " " 
			<< c->car.getYear() << " " c->car.getColor();
		}
		cout << "\n";
	}
}

CarLinkedList CarLinkedList::getCarsByYear(int y){
	if (size == 0) {
		cout << "getCarsByYear(): Array is Empty";
	}
	else {

		node *c = head;
		while(c != 0) {
			if 
		}
		cout << "\n";
	}
}

// Get List Size
int CarLinkedList::size() {
	return size;
}

// Return true if LinkedList is empty
bool CarLinkedList::isEmpty() {
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

// Add Car
void CarLinkedList::add(Car c) {
	node *n = new node;
	n->car = c;
	n->next = 0;

	if (head == 0) {
		head = n;
		tail = n;
		n = 0;
	}
	else {
		tail->next = n;
		tail = n;
	}

	size++;
}

// Get car at nth position
Car CarLinkedList::get(int n) {
	if (n < 0 || n >= size){
		cout << "Invalid Index n=" << n;
	}
	else {
		node *n = head;
		for (int i = 0; i < size; i++) {
			if (i == n) {
				return n->car;
			}
			n = n->next;
		}
	}
}

// Remove Car at n
Car CarLinkedList::remove(int n) {
	if (n < 0 || n >= size){
		cout << "Invalid Index n=" << n;
	}
	else {
		node *n = head;
		node *previous = 0;
		for (int i = 0; i < size; i++) {
			if (i == n) {
				previous->next = n->next;
				size--;
				return n->car;
			}
			previous = n;
			n = n->next;
		}
	}
} 

#endif