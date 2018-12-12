// QuickSortCars.h

#ifndef QUICKSORTCARS_H_
#define QUICKSORTCARS_H_

static class QuickSortCars {
	private:
		void quickSortCars(Car* arr, int low, int high);
		int partition(Car *arr, int low, int high);
		int swap(Car* a, Car* b);
	public:
		Car* sort(Car* cars);
};

#endif