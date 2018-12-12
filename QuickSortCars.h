// QuickSortCars.h

#ifndef QUICKSORTCARS_H_
#define QUICKSORTCARS_H_

class QuickSortCars {
	public:
		DynamicCarArray sort(Car cars);
	priavte:
		void QuickSortCars(Car* arr, int low, int high);
		int partition(Car *arr, int low, int high);
		int swap(Car* a, Car* b);
};

#endif