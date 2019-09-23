#include "Point.h"

Point::Point(int xCoordinate, int yCoordinate) {
	x = xCoordinate;
	y = yCoordinate;
}

Point::Point() {
}

int Point::getXCoordinate() {
	return x;
}

int Point::getYCoordinate() {
	return y;
}

void Point::setXCoordinate(int xCoordinate) {
	x = xCoordinate;
}

void Point::setYCoordinate(int yCoordinate) {
	y = yCoordinate;
}

float Point::distance(const Point &other) {
	float d = sqrt(((x - other.x) * (x - other.x)) + ((y - other.y) * (y - other.y)));
	return d;
}