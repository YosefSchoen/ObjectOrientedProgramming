#include "Polygon.h"


int main() {
	int N;
	int x;
	int y;

	Point *p;
	cin >> N;

	p = new Point[N];
	
	for (int i = 0; i < N; i++) {
		cin >> x >> y;

		p[i].setXCoordinate(x);
		p[i].setYCoordinate(y);
	}

	Polygon myShape(p, N);
 
	cout << myShape.Perimeter() << endl;
	

	return 0;
}