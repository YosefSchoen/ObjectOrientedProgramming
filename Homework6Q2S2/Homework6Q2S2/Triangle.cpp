#include "Triangle.h"


Triangle::Triangle(int s1, int s2, int s3) : Polygon(3) {
	sides[0] = s1;
	sides[1] = s2;
	sides[2] = s3;
}