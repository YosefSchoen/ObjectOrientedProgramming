#include "MA.h"

MA::MA(int Id, int NOC, string N, string LN, int g[], bool r) : BA(Id, NOC, N, LN, g) {
	research = r;
}

int MA::getNumOfCourses() {
	return numOfCourses;
}

int MA::getResearch() {
	return research;
}

bool MA::milga() {
	float average = 0;

	for (int i = 0; i < numOfCourses; i++) {
		average = average + *(grades + i);
	}

	average = average / numOfCourses;

	if (numOfCourses >= 7 && average > 90 && research == true) {
		return true;
	}

	return false;
}

void MA::print() {
	cout << "ID: " << id << endl
		<< "first name: " << name << endl
		<< "last name: " << lastName << endl
		<< "num courses: " << numOfCourses << endl
		<< "grades: ";

	for (int i = 0; i < numOfCourses; i++) {
		if (i == numOfCourses - 1) {
			cout << *(grades + i);
		}

		else {
			cout << *(grades + i) << " ";
		}
	}

	cout << endl << "research: ";

	if (research == true) {
		cout << "yes" << endl;
	}

	else {
		cout << "no" << endl;
	}
}

string MA::studType() {
	string MA = "MA";
	return MA;
}