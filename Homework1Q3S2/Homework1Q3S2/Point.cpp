#include "Point.h";

Point::Point(int x, int y) {
	xCoordinate = x;
	yCoordinate = y;
}


void Point::setXCoordinate(int x) {
	xCoordinate = x;
}

void Point::setYCoordinate(int y) {
	yCoordinate = y;
}

int Point::getXCoordinate() {
	return xCoordinate;
}

int Point::getYCoordinate() {
	return yCoordinate;
}