// Car.cpp

#ifndef CAR_H_
#include "Car.h"

#include <string>

Car::Car(std::string _make, std::string _model, int _year, std::string _color) {
	make = _make;
	model = _model;
	year = _year;
	color = _color;
}

std::string Car::getMake() {
	return make;
}

std::string Car::getModel() {
	return model;
}

int Car::getYear() {
	return year;
}

std::string Car::getColor() {
	return color;
}

#endif