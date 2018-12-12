// QuickSortCars.h

#ifndef QUICKSORTCARS_H_
#define QUICKSORTCARS_H_

class QuickSortCars {
	private:
		void quickSortCars(Car* arr, int low, int high);
		int partition(Car *arr, int low, int high);
		int swap(Car* a, Car* b);
	public:
		DynamicCarArray sort(Car cars);
};

#endif