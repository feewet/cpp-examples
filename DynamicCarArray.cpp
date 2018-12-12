// DynamicCarArray.cpp
#ifndef DynamicCarArrayH
#include DynamicCarArrayH

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

// Add one element
void DynamicCarArray::add(Car c) {
	v[count] = c;
	count ++;
	if (count == size) {
		grow();
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

#endif