#pragma once
#include <iostream>
using namespace std;

class Polygon {
public:
	Polygon(int);
	Polygon(const Polygon &);

	int getNumSides();
	int *getSides();

	bool operator==(const Polygon &);

protected:
	int numSides;
	int *sides;
};