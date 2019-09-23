#pragma once
#include "Point.h"

class Polygon {
public:
	Polygon(Point [], int);
	Polygon(const Polygon &);
	~Polygon();

	int Perimeter();

private:
	int numOfVertices;
	Point *vertices;
};