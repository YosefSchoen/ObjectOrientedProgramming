#include "Rectangle.h"


Rectangle::Rectangle(int l, int w) : Polygon(4) {
	sides[0] = l;
	sides[1] = w;
	sides[2] = l;
	sides[3] = w;
}