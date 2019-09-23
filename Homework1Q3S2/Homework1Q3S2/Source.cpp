#include "Circle.h";
#include <cmath>;

float distanceFormula(Point p, Circle c) {
	int x1 = p.getXCoordinate();
	int y1 = p.getYCoordinate();
	int x2 = c.getCenter().getXCoordinate();
	int y2 = c.getCenter().getYCoordinate();

	float distance = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	
	return distance;
}

int main() {
	int circleOneX;
	int circleOneY;
	int circleOneRadius;

	int circleTwoX;
	int circleTwoY;
	int circleTwoRadius;

	int circleThreeX;
	int circleThreeY;
	int circleThreeRadius;

	cout << "enter the center point and radius of 3 circles\n";

	cin >> circleOneX >> circleOneY >> circleOneRadius;
	cin >> circleTwoX >> circleTwoY >> circleTwoRadius;
	cin >> circleThreeX >> circleThreeY >> circleThreeRadius;

	Point *p1 = new Point(circleOneX, circleOneY);
	Point *p2 = new Point(circleTwoX, circleTwoY);
	Point *p3 = new Point(circleThreeX, circleThreeY);

	Circle one(p1, circleOneRadius);
	Circle two(p2, circleTwoRadius);
	Circle three(p3, circleThreeRadius);

	cout << "area A: " << one.area() << " B: " << two.area() << " C: " << three.area() << endl;
	cout << "hekef A: " << one.hekef() << " B: " << two.hekef() << " C: " << three.hekef() << endl;

	int x;
	int y;
	int numOfPointsOne = 0;
	int numOfPointsTwo = 0;
	int numOfPointsThree = 0;

	cin >> x >> y;
	while (x != 0 || y != 0) {
		Point p(x, y);

		if (one.getRadius() >= distanceFormula(p, one)) {
			numOfPointsOne++;
		}

		if (two.getRadius() >= distanceFormula(p, two)) {
			numOfPointsTwo++;
		}

		if (three.getRadius() >= distanceFormula(p, three)) {
			numOfPointsThree++;
		}

		cin >> x >> y;
	}

	cout << "num of points in circle A: " << numOfPointsOne << " B: " << numOfPointsTwo << " C: " << numOfPointsThree << endl;

	return 0;
}