#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Point {
public:
	Point(int xCoordinate, int yCoordinate);
	Point();

	int getXCoordinate();
	int getYCoordinate();

	void setXCoordinate(int xCoordinate);
	void setYCoordinate(int yCoordinate);

	float distance(const Point &);

private:
	int x;
	int y;
};