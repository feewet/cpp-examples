// Question 1

class Question1 {
	private:
		DynamicCarArray populateArray(); // Populate Array from Cars.txt
		void printCarsArray(DynamicCarArray cars);
		void sortCarsByYear(DynamicCarArray cars);
		void sortCarsByMake(DynamicCarArray cars);
		Car getCarInput();
		int menu();
	public:
		void run();
};

// Populate Array from Cars.txt
DynamicCarArray Question1::populateArray() {
	DynamicCarArray cars;
	ifstream file("Cars.txt");
	if (file.is_open()) {
		string line;
		string make, model, yearStr, color;
		int year;

		while (getline(file, line)) {
			stringstream ss(line);
	    	// read 4 lines
	    	getline(ss, make, ',');
	    	getline(ss, model, ',');
	    	getline(ss, yearStr, ',');
	    	getline(ss, color, ',');
		    // declaring character array 
		    char char_array[yearStr.length() + 1];  
		    // copying the contents of the  
		    // string to char array 
		    strcpy(char_array, yearStr.c_str());  
		    // parsing input using regex
	    	sscanf(char_array, "%d", &year);

	    	// create new Car
	    	cars.add(Car(make, model, year, color));
	    }
	    file.close();
	}
	else {
		cout << "Unable to open Cars.txt";
	}
	return cars;
}

void Question1::printCarsArray(DynamicCarArray cars) {
	cars.print();
}

void Question1::sortCarsByYear(DynamicCarArray cars) {
	cars.sortCarsByYear().print();
}

void Question1::sortCarsByMake(DynamicCarArray cars) {
	string make;
	cout << "Enter Make: ";
	cin >> make;
	DynamicCarArray sorted = cars.sortCarsByMake(make, cars);
	if (sorted.length() != 0) {
		sorted.print();
	}
	else {
		cout << "No cars with make: " << make << endl;
	}
}

// Read new Car
Car Question1::getCarInput() {
	string make, model, yearStr, color;
	int year;
	cout << "Enter Make: ";
	cin >> make;
	cout << "Enter Model: ";
	cin >> model;
	while (true) {
		cout << "Enter Year: ";
		cin >> yearStr;
		// declaring character array 
	    char char_array[yearStr.length() + 1];  
	    // copying the contents of the  
	    // string to char array 
	    strcpy(char_array, yearStr.c_str());  
	    // parsing input using regex
    	sscanf(char_array, "%d", &year);

		if (regex_match(char_array, regex("%d{4}"))) {
			sscanf(char_array, "%d", &year);
			break;
		}
		else {
			cout << "Please enter valid year (XXXX).\n";
		}
	}
	cout << "Enter Color: ";
	cin >> color;

	return Car(make, model, year, color);
}

void Question1::run() {
	DynamicCarArray cars = populateArray();
	int choice = 0;

	while (true) {
		choice = menu();
		cout << "\n";
		if (choice == 1) {
			cars.print(); // Print cars array
		}
		if (choice == 2) {
			cars.add(getCarInput());// Insert car records into array
		}
		if (choice == 3) {
			sortCarsByYear(cars); // sort cars by year
		}
		if (choice == 4) {
			sortCarsByMake(cars); // sort cars by make
		}
		if (choice == 5) {   
			cout << "Exiting...\n";
		}
		if (choice == 0)	{
			cout << "Invalid Option!\n";
		}
		cout << "\n";
	}
	cout << "\nDone.";
}

int Question1::menu() {
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