// main.cpp

// Harold Hyatt
// Assignment 1
// Embedded Design Enabling Robotics

// See Question1.cpp, Question2.cpp

#include "Question1.cpp"
#include "Question2.cpp"

using namespace std;

int main () {
	Question1 q1;
	Question2 q2;
	cout << "Question1.cpp: DynamicCarArray";
	q1.run();
	cout << "Question2.cpp: CarLinkedList";
	//q2.run();
	return 0;
}