#include "Polygon.h"

Polygon::Polygon(Point coordinates[], int N) {
	numOfVertices = N;
	vertices = new Point[numOfVertices];

	for (int i = 0; i < numOfVertices; i++) {
		vertices[i] = coordinates[i];
	}
}

Polygon::Polygon(const Polygon &) {

}

Polygon::~Polygon() {

}


int Polygon::Perimeter() {
	int sum = vertices[numOfVertices - 1].distance(vertices[0]);

	for (int i = 0; i < numOfVertices - 1; i++) {
		sum = sum + vertices[i].distance(vertices[i + 1]);
	}

	return sum;
}