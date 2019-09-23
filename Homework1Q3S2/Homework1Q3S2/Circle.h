#pragma once
#include "Point.h";
#include <iostream>
using namespace std;

const float Pi = 3.14;

class Circle {
public:
	Circle(Point *c, int r);

	void setRadius(int r);

	void setCenter(int x, int y);

	int getRadius();

	Point getCenter();

	float area();

	float hekef();

private:
	Point *center;
	int radius;
};