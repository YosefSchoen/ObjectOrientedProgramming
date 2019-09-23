#pragma once
#include <iostream>
using namespace std;

class Point {
public:
	Point(int x, int y);

	void setXCoordinate(int x);
	void setYCoordinate(int y);

	int getXCoordinate();
	int getYCoordinate();

private:
	int xCoordinate;
	int yCoordinate;
};

