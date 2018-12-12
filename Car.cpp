// Car.cpp

#include <string>

#ifndef CAR_H_
#include "Car.h"

Car::Car(string _make, string _model, int _year, string _color) {
	make = _make;
	model = _model;
	year = _year;
	color = _color
}

string Car::getMake() {
	return make;
}

string Car::getModel() {
	return model;
}

int Car::getYear() {
	return year;
}

String Car::getColor() {
	return color;
}

#endif