// Car.h

#ifndef CAR_H_
#define CAR_H_

#include <string>

class Car {
	private:
		std::string make;
		std::string model;
		int year;
		std::string color;
	public:
		Car(std::string _make, std::string _model, int _year, std::string _color);
		std::string getMake();
		std::string getModel();
		int getYear();
		std::string getColor();
};

#endif