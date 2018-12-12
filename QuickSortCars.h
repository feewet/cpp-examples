// QuickSortCars.h

#ifndef QUICKSORTCARS_H_
#define QUICKSORTCARS_H_

class DynamicCarArray;
class CarLinkedList;

class QuickSortCars {
	private:
		void quickSortCars(Car* arr, int low, int high);
		int partition(Car *arr, int low, int high);
		int swap(Car* a, Car* b);
	public:
		static DynamicCarArray sort(DynamicCarArray cars);
		static CarLinkedList sort(CarLinkedList cars);
};

#endif