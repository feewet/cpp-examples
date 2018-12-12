// Question 1

class Question1 {
	private:
		DynamicCarArray populateArray(); // Populate Array from Cars.txt
		void printCarsArray(DynamicCarArray cars);
		void sortCarsByYear(int year, DynamicCarArray cars);
		void sortCarsByMake(string make, DynamicCarArray cars);
		Car getCarInput();
		int menu();
	public:
		Question1();
		void run();
};

Question1::Question1() {}

// Populate Array from Cars.txt
void Question1::populateArray(DynamicCarArray &cars) {
	ofstream file("Cars.txt");
	if (file.is_open()) {
		string line;
		Car car;
		string make, model, yearStr, color;
		int year;

		while (getline(myfile, line))
	    {
	    	// read 4 lines
	    	getline(ss, make, ',');
	    	getline(ss, model, ',');
	    	getline(ss, yearStr, ',');
	    	getline(ss, color, ',');
	    	sscanf(yearStr, "%d", &year);
	    	// create new car
	    	car = new Car(make, model, year, color);
	    	cars.add(car);
	    }
	    myfile.close();
	}
	else {
		cout << "Unable to open Cars.txt";
	}
}

void Question1::printCarsArray(DynamicCarArray cars) {
	cars.print();
}

void Question1::sortCarsByYear(int year, DynamicCarArray cars) {
	cars.sortCarsByYear(year).print()
}

void Question1::sortCarsByMake(string make, DynamicCarArray cars) {
	cars.sortCarsByMake(make).print();
}

// Read new Car
Car Question1::getCarInput() {
	string make, model, yearStr, color;
	int year;
	Car car;
	cout << "Enter Make: ";
	cin >> make;
	cout << "Enter Model: ";
	cin >> model;
	while (true) {
		cout << "Enter Year: ";
		cin >> yearStr;
		if (regex_match(yearStr, regex("%d{4}"))) {
			sscanf(yearStr, "%d", &year);
			break;
		}
		else {
			cout << "Please enter valid year (XXXX).\n";
		}
	}
	cout << "Enter Color: ";
	cin >> color;

	return new Car(make, model, year, color);
}

void Question1::run() {
	DynamicCarArray cars = new DynamicCarArray();
	populateArray(cars);
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
	delete cars;
	cout << "\nDone.";
	return 0;
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