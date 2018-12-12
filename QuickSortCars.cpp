// QuickSort.cpp

#ifndef QUICKSORTCARS_H_
#include "QuickSortCars.h"

// Sort cars dynamic array (copy)
DynamicCarArray QuickSortCars::sort(DynamicCarArray cars) {
	arr = cars.toArray();
	quickSortCars(&arr, 0, (cars.count() - 1));
	return cars.copy(arr);
}

// Sort LinkedCardList (copy)
LinkedCarList QuickSortCars::sort(LinkedCarList cars) {
	arr = cars.toArray();
	quickSortCars(&arr, 0, (cars.count() - 1));
	return cars.copy(arr);
}

// swap two elements
void QuickSortCars::swap(Car* a, Car* b) 
{ 
    Car t = *a;
    *a = *b;
    *b = t;
} 

// places all elements smaller than pivot left of pivot
// places all elements larger than pivot to right of pivot
int QuickSortCars::partition(Car *arr, int low, int high)
{
    int pivot = arr[high].getYear(); // pivot
    int i = (low - 1); // smaller element
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // element <= pivot
        if (arr[j].getYear() <= pivot)
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        }
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1);
} 
  
// arr[] : array
// low : starting index
// high : Ending index
void QuickSortCars::quickSortCars(Car *arr, int low, int high) 
{
    if (low < high)
    { 
        // pi is partitioning index
        int pi = partition(arr, low, high); 

        // Separately sort elements before and after partition
        quickSortCars(arr, low, pi - 1); 
        quickSortCars(arr, pi + 1, high); 
    } 
}

#endif