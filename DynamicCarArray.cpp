// DynamicCarArray.cpp

#ifndef DYNAMICCARARRAY_H_
#include "Car.h"
#include "DynamicCarArray.h"
#include "QuickSortCars.h"
#include <string>
#include <iostream>

// Default Constructor
DynamicCarArray::DynamicCarArray() {
	size = 2;
	count = 0;
	v = new Car[size];
}

// Destructor
DynamicCarArray::~DynamicCarArray() {
	delete v;
}

// Print array
void DynamicCarArray::print() {
	std::cout << "Printing...\n";
	if (count == 0) {
		std::cout << "Array is Empty";
	}
	for (int i = 0; i < count; i++) {
		std::cout << v[i].getMake() << " " << v[i].getModel() << " "
		<< v[i].getYear() << " " << v[i].getColor();
	}
	std::cout << "\n";
}

// sort cars by year
DynamicCarArray DynamicCarArray::sortCarsByYear() {
	DynamicCarArray c;
	c.copy(QuickSortCars::sort(toArray()));
	return c;
}

// sort cars by make
DynamicCarArray DynamicCarArray::sortCarsByMake(std::string make) {
	DynamicCarArray c;
	Car car;
	Car* cars;
	int n = 0;
	for (int i = 0; i < count; i++) {
		car = get(i);
		if (car.getMake() == make) {
			cars[n] = car;
			n++;
		}
	}
	c.copy(cars);
	return c;
}

// Add one element
void DynamicCarArray::add(Car c) {
	v[count] = c;
	count ++;
	if (count == size) {
		grow();
	}
}

Car DynamicCarArray::get(int n) {
		return car[n];
}

// Remove one element given index
void DynamicCarArray::remove(int n) {
	if (count == 0) {
		std::cout << "No remaining elements\n";
	}
	else {
		// find element
		for (int i = n; i < count; i++) {
			v[i] = v[i+1];
		}
		count --;
		if (count < size / 2) {
			shrink();
		}
	}
}

int DynamicCarArray::length(){
	return count;
}

// Double vector capacity
void DynamicCarArray::grow() {
        Car*  nv = new Car[size * 2];
        for (int i = 0; i < count; i++) {
                nv[i] = v[i];
		}
        delete v;
        v = nv;
        size = size * 2;
}

// Halve vector capacity
void DynamicCarArray::shrink() {
        Car*  nv = new Car[size / 2];
        for (int i = 0; i < count; i++) {
                nv[i] = v[i];
	}
        delete v;
        v = nv;
        size = size / 2;
}

int DynamicCarArray::getCapacity() {
	return size;
}

// copy array from Dynamic Array (overwrite)
void DynamicCarArray::copy(DynamicCarArray cars) {
	size = cars.getCapacity();
	count = cars.length();
	v = new Car[size];
	for (int i; i < cars.length(), i++) {
		v[i] = cars.get(i);
	}
}

// copy array from Car Array (overwrite)
void DynamicCarArray::copy(Car *c) {
	size = 2;
	count = 0;
	v = new Car[size];
	for (int i; i < sizeof(c); i++) {
		add(c[i]);
	}
	delete c;
}

// return array of Car
Car* DynamicCarArray::toArray() {
	Car* cars = new Car[count];
	for (int i = 0; i < count; i++) {
		cars[i] = v[i];
	}
	return cars;
}

#endif