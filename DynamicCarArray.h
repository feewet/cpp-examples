// DynamicCarArray.h

#ifndef DYNAMICCARARRAY_H_
#define DYNAMICCARARRAY_H_

class Car;
// Dynamnic array to hold Cars.
class DynamicCarArray {
	private:
		Car* v; // vector
		int size; // size
		int count; // number of elements inserted
	public:
		DynamicCarArray(); // default constructor
		~DynamicCarArray(); // default constructor
		void print(); // print array
		DynamicCarArray sortCarsByYear(); // sort cars by year
		DynamicCarArray sortCarsByMake(std::string make); // sort cars by make
		void add(Car c); // add Car to array
		Car get(int n); // Get car at index n
		void remove(int n); // remove nth element
		int length(); // return count of elements
		void grow(); // grow Array
		void shrink(); // shrink array
		int getCapacity(); // return capacity of array
		void copy(DynamicCarArray c); // copy Dynamic Array (overwrite)
		void copy(Car *c); // copy array (overwrite)
		Car* toArray(); // return array of cars
};

#endif