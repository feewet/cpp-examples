// CarLinkedList.cpp

#ifndef CARLINKEDLIST_H_
#include "Car.h"
#include "CarLinkedList.h"
//#include <string>
#include <iostream>

// Constructor
CarLinkedList::CarLinkedList() {
	length = 0;
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
	if (length == 0) {
		cout << "print(): Array is Empty";
	}
	else {
		node *c = head;
		while(c != 0) {
			cout << c->car.getMake() << " " << c->car.getModel() << " " 
			<< c->car.getYear() << " " c->car.getColor();
			c = c->next;
		}
		cout << "\n";
	}
}

// Get cars by year through QuickSort
CarLinkedList CarLinkedList::getCarsByYear(){
	return 0;
}

// Get List Size
int CarLinkedList::length() {
	return length;
}

// Return true if LinkedList is empty
bool CarLinkedList::isEmpty() {
	if (length == 0) {
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

	length++;
}

// Get car at nth position
Car CarLinkedList::get(int k) {
	if (n < 0 || n >= length){
		cout << "Invalid Index n=" << n;
	}
	else {
		node *n = head;
		for (int i = 0; i < length; i++) {
			if (i == k) {
				return n->car;
			}
			n = n->next;
		}
	}
}

// Remove Car at n
Car CarLinkedList::remove(int n) {
	if (n < 0 || n >= length){
		cout << "Invalid Index n=" << n;
	}
	else {
		node *n = head;
		node *previous = 0;
		int k = 0;
		for (int i = 0; i < length; i++) {
			if (i == k) {
				previous->next = n->next;
				length--;
				return n->car;
			}
			previous = n;
			n = n->next;
			k++;
		}
	}
} 

Car* CarLinkedList::getArray() {
	Car* cars;
	node *c = head;
		while(c != 0) {
			cars[i] = &c;
			c = c->next;
		}
	return cars;
}

// Copy array
void CarLinkedList::copy(Car* cars) {
	for (int i = 0; i < sizeof(cars); i++) {
		add(cars[i]);
	}
}

#endif