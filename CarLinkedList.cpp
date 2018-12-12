// CarLinkedList.cpp

#ifndef CARLINKEDLIST_H_
#include "Car.h"
#include "CarLinkedList.h"
#include "QuickSortCars.h"
#include <iostream>

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
	std::cout << "Printing...\n";
	if (size == 0) {
		std::cout << "print(): Array is Empty";
	}
	else {
		node *c = head;
		while(c != 0) {
			std::cout << c->car.getMake() << " " << c->car.getModel() << " ";
			std::cout << c->car.getYear() << " " << c->car.getColor();
			c = c->next;
		}
		std::cout << "\n";
	}
}

// Get cars by year through QuickSort
CarLinkedList CarLinkedList::getCarsByYear(){
	return QuickSortCars.sort(this);
}

// Get List Size
int CarLinkedList::length() {
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
Car CarLinkedList::get(int k) {
	if (k < 0 || k >= size){
		std::cout << "Invalid Index k=" << k;
	}
	else {
		node *n = head;
		for (int i = 0; i < size; i++) {
			if (i == k) {
				return n->car;
			}
			n = n->next;
		}
	}
}

// Remove Car at n
Car CarLinkedList::remove(int k) {
	if (k < 0 || k >= size){
		std::cout << "Invalid Index n=" << k;
	}
	else {
		node *n = head;
		node *previous = 0;
		for (int i = 0; i < size; i++) {
			if (i == k) {
				previous->next = n->next;
				size--;
				return n->car;
			}
			previous = n;
			n = n->next;
		}
	}
} 

Car* CarLinkedList::getArray() {
	Car* cars;
	node *c = head;
	int i = 0;
		while(c != 0) {
			cars[i] = c->car;
			c = c->next;
			i++;
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