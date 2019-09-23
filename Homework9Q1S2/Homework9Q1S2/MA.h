#pragma once
#include "BA.h"

class MA : public BA {
public:
	MA(int Id, int NOC, string N, string LN, int g[], bool r);
	int getNumOfCourses();
	int getResearch();
	bool milga();
	void print();
	string studType();

protected:
	bool research;
};