#include "BA.h"

BA::BA(int Id, int NOC, string N, string LN, int g[]) : Student(Id, NOC, N, LN), grades(new int[NOC]) {


	for (int i = 0; i < numOfCourses; i++) {
		*(grades + i) = *(g + i);
	}
}

string BA::getName() {
	return name;
}

int BA::getNumOfCourses() {
	return numOfCourses;
}

bool BA::milga() {
	float average = 0;

	for (int i = 0; i < numOfCourses; i++) {
		average = average + *(grades + i);
	}

	average = average / numOfCourses;

	if (numOfCourses >= 10 && average > 95) {
		return true;
	}

	return false;
}

void BA::print() {
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

}

string BA::studType() {
	string BA = "BA";
	return BA;
}