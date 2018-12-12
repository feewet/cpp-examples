// DynamicCarArray.cpp

#ifndef DYNAMICCARARRAY_H_
#include "DynamicCarArray.h"

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
	cout << "Printing...\n";
	if (count == 0) {
		cout << "Array is Empty";
	}
	for (int i = 0; i < count; i++) {
		cout << v[i].getMake() << " " << v[i].getModel() << " " 
		<< v[i].getYear() << " " v[i].getColor();
	}
	cout << "\n";
}

// sort cars by year
DynamicCarArray DynamicCarArray::sortCarsByYear() {
	return QuickSortCars.sort(this);
}

// sort cars by make
DynamicCarArray DynamicCarArray::sortCarsByMake(string make) {
	DynamicCarArray cars = new DynamicCarArray();
	for (int i = 0; i < count; i++) {
		car = get(i);
		if (car.getMake() == make) {
			cars.add(get);
		}
	}

	return matchCars;
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
	if (n > 0 && n < count) {
		return car[n];
	}
	else {
		cout << "DynamicCarArray.get - Invalid index: " << n << endl;
		return NULL;
	}
}

// Remove one element given index
void DynamicCarArray::remove(int n) {
	if (count == 0) {
		cout << "No remaining elements\n";
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
        Car*  nv = new Car*[size * 2];
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
	for (int i; i < sizeof(c), i++) {
		add(c[i]);
	}
}

// return array of Car
Car* DynamicCarArray::toArray() {
	return v - (size - count);
}

#endif