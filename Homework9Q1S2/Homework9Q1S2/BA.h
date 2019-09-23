#pragma once
#include "Student.h"

class BA : public Student {
public:
	BA(int Id, int NOC, string N, string LN, int *g);
	string getName();
	int getNumOfCourses();

	bool milga();
	void print();
	string studType();
protected:
	int *grades;
};
