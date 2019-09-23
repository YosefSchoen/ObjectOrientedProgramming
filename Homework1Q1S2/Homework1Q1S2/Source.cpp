#include "Rational.h";
#include <iostream>
using namespace std;

int main() {
	int firstN;
	int firstD;
	int secondN;
	int secondD;
	char div;

	cout << "enter two rational numbers\n";

	cin >> firstN >> div >> firstD;
	cin >> secondN >> div >> secondD;

	Rational first(firstN, firstD);
	Rational second(secondN, secondD);


	first.reduce();
	second.reduce();

	if (firstD == 0 || secondD == 0) {
		cout << "ERROR\n";
	}

	else if (first.equal(second)) {
		cout << "equal\n";
	}

	else {
		cout << "different\n";
		first.print();
		second.print();
	}

	return 0;
}