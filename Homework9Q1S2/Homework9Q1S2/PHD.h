#pragma once
#include"Student.h"

class PHD : public Student {
public:
	PHD(int Id, int NOC, string N, string LN, int RH);
	string getName();
	int getResearch();
	int getNumOfCourses();

	bool milga();
	void print();
	string studType();

protected:
	int reserchHours;
};