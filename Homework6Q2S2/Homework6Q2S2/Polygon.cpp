#include "Polygon.h"

Polygon::Polygon(int n) : numSides(n) {
	
	sides = new int[numSides];

	if (numSides > 4) {
		cout << "enter sides for polygon:\n";

		for (int i = 0; i < numSides; i++) {
			cin >> sides[i];
		}

	}

}
Polygon::Polygon(const Polygon &other) {
	numSides = other.numSides;

	for (int i = 0; i < numSides; i++) {
		sides[i] = other.sides[i];
	}
}

int Polygon::getNumSides() {
	return numSides;
}

int *Polygon::getSides() {
	return sides;
}

bool Polygon::operator==(const Polygon &other) {
	int perimeter = 0;
	int otherPerimeter = 0;

	if (numSides != other.numSides) {
		return false;
	}

	for (int i = 0; i < numSides; i++) {
		perimeter += sides[i];
		otherPerimeter += other.sides[i];
	}

	if (perimeter != otherPerimeter) {
		return false;
	}

	return true;
}
