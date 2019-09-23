#pragma once
#include"Student.h"

class PHD : public Student{
public:
	PHD(int Id, int NOC, string N, string LN, int RH);

	bool milga();
	void print();

protected:
	int reserchHours;
};