#include "Circle.h";


Circle::Circle(Point *c, int r) {
	center = c;
	radius = r;
}

void Circle::setRadius(int r) {
	radius = r;
}

void Circle::setCenter(int x, int y) {
	center->setXCoordinate(x);
	center->setYCoordinate(y);
}

int Circle::getRadius() {
	return radius;
}

Point Circle::getCenter() {
	return *center;
}

float Circle::area() {
	return (Pi * radius * radius);
}

float Circle::hekef() {
	return (2 * Pi * radius);
}