#pragma once
#include "Student.h"

class BA : public Student {
public:
	BA(int Id, int NOC, string N, string LN, int g[]);

	bool milga();
	void print();

protected:
	int *grades;
};