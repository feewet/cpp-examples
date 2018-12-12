// lab0 Harold Hyatt

#include <iostream>
using namespace std;

double* v; // vector
int size; // size
int count; // number of elements inserted

void initialize() {
	size = 2;
	count = 0;
	v = new double[size];
	return;
}

void finalize() {
	delete v;
	return;
}

void printVector() {
	cout << "Printing vector...\n";
	if (count == 0) {
		cout << "Vector is Empty";
	}
	for (int i = 0; i < count; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

// double vector size
void grow() {
	cout << "\nVector grown\nPrevious capacity: ";
        cout << size << " elements\nNew capacity: ";
        cout << size * 2 << " elements\n";
        double*  nv = new double[size * 2];
        for (int i = 0; i < count; i++) {
                nv[i] = v[i];
	}
        delete v;
        v = nv;
        size = size * 2;
        return;
}

// halve vector capacity
void shrink() {
	cout << "Vector shrinking\nPrevious capacity: ";
        cout << size << " elements\nNew capacity: ";
        cout << size / 2 << " elements\n";
        double*  nv = new double[size / 2];
        for (int i = 0; i < count; i++) {
                nv[i] = v[i];
	}
        delete v;
        v = nv;
        size = size / 2;
        return;
}

// remove one element
void removeElement() {
	if (count == 0) {
		cout << "No remaining elements\n";
	}
	else {
		count --;
		if (count < size / 2) {
			shrink();
		}
	}
	return;
}
// add one element
void addElement() {
	double x; // new element
	cout << "Enter the new element: ";
	cin >> x;
	v[count] = x;
	count ++;
	if (count == size) {
		grow();
	}
	return;
}

int  menu() {
	string choice = "0";
	cout << "Main menu:\n\n1. Print the cars array\n2. Insert car record\n";
	cout << "3. Sort cars by year\n4. Search cars by make\n5. Exit\n\nSelect an option: ";
	cin >> choice;

	if (choice == "1") {
                return 1;
	}
	else if (choice == "2") {
                return 2;
        }
	else if (choice == "3") {
		return 3;
        }
	else if (choice == "4") {
		return 4;
        }
	else if (choice == "5") {
		return 5;
	}

	return 0;
}

int main () {
	initialize();
	string message = "";
	int choice = 0;
	while (true) {
        	choice = menu();
		cout << "\n";
		if (choice == 1) {
			printVector();
		}
		if (choice == 2) {
                        addElement();
                }
		if (choice == 3) {
                        removeElement();
                }
		if (choice == 4) {
                        cout << "Exiting\n";
			break;                
		}
		if (choice == 0)	{
                        cout << "Invalid Option!\n";
                }
		cout << "\n";
	}
	finalize();
        return 0;
}
