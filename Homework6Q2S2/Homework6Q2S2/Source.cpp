#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"

int main() {
	int numSides;
	
	int side1;
	int side2;
	int side3;

	int length;
	int width;

	cout << "enter number of sides for polygon 1:\n";

	cin >> numSides;

	if (numSides == 3) {
		cout << "enter sides for polygon:\n";
		cin >> side1 >> side2 >> side3;

		Triangle first(side1, side2, side3);

		cout << "enter number of sides for polygon 2:\n";
		cin >> numSides;

		if (numSides == 3) {
			cout << "enter sides for polygon:\n";
			cin >> side1 >> side2 >> side3;

			Triangle second(side1, side2, side3);

			if (first == second) {
				cout << "equal\n";
			}

			else {
				cout << "not equal\n";
			}
		}

		else if (numSides == 4) {
			cout << "enter sides for polygon:\n";
			cin >> length >> width;

			Rectangle second(length, width);

			cout << "not equal\n";
		}

		else {
			Polygon second(numSides);
			cout << "not equal\n";
		}
	}

	else if (numSides == 4) {
		cout << "enter sides for polygon:\n";
		cin >> length >> width;

		Rectangle first(length, width);

		cout << "enter number of sides for polygon 2:\n";
		cin >> numSides;

		if (numSides == 3) {
			cout << "enter sides for polygon:\n";
			cin >> side1 >> side2 >> side3;

			Triangle second(side1, side2, side3);

			cout << "not equal\n";
		}

		else if (numSides == 4) {
			cout << "enter sides for polygon:\n";
			cin >> length >> width;

			Rectangle second(length, width);
			if (first == second) {
				cout << "equal\n";
			}
			else {
				cout << "not equal\n";
			}
		}

		else {
			Polygon second(numSides);
			cout << "not equal\n";
		}
	}

	else {
		Polygon first(numSides);

		cout << "enter number of sides for polygon 2:\n";
		cin >> numSides;

		if (numSides == 3) {
			cout << "enter sides for polygon:\n";
			cin >> side1 >> side2 >> side3;

			Triangle second(side1, side2, side3);

			cout << "not equal\n";
		}

		else if (numSides == 4) {
			cout << "enter sides for polygon:\n";
			cin >> length >> width;

			Rectangle second(length, width);

			cout << "not equal\n";
		}

		else {
			Polygon second(numSides);

			if (first == second) {
				cout << "equal\n";
			}

			else {
				cout << "not equal\n";
			}
		}
	}
	return 0;
}