#include "PHD.h"

PHD::PHD(int Id, int NOC, string N, string LN, int RH) : Student(Id, NOC, N, LN) {
	reserchHours = RH;
}

string PHD::getName() {
	return name;
}

int PHD::getResearch() {
	return reserchHours;
}

int PHD::getNumOfCourses() {
	return numOfCourses;
}

bool PHD::milga() {

	if (numOfCourses >= 2 && reserchHours > 25) {
		return true;
	}

	return false;
}

void PHD::print() {
	cout << "ID: " << id << endl
		<< "first name: " << name << endl
		<< "last name: " << lastName << endl
		<< "num courses: " << numOfCourses << endl
		<< "hours: " << reserchHours << endl;
}

string PHD::studType() {
	string PHD = "PHD";
	return PHD;
}