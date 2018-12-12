// QuickSortCars.h

#ifndef QUICKSORTCARS_H_
#define QUICKSORTCARS_H_

class QuickSortCars {
	private:
		static void quickSortCars(Car* arr, int low, int high);
		static int partition(Car *arr, int low, int high);
		static int swap(Car* a, Car* b);
	public:
		static Car* sort(Car* cars);
};

#endif