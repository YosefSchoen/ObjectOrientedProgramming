#include "Rational.h"

int main() {
	int firstN;
	int firstD;
	int secondN;
	int secondD;
	char slash;

	cout << "Enter two rational numbers\n";

	cin >> firstN >> slash >> firstD >> secondN >> slash >> secondD;

	Rational a(firstN, firstD);
	Rational b(secondN, secondD);

	cout << "a:\n";
	cout << "b:\n";

	if (a.getDenominator() == 0) {
		a.print();
	}

	if (b.getDenominator() == 0) {
		b.print();
	}

	cout << "b-a: ";
	(b - a).print();

	cout << "a!=b: ";
	if (a != b) {
		cout << "true\n";
	}

	else {
		cout << "false\n";
	}

	cout << "a<b: ";
	if (a < b) {
		cout << "true\n";
	}

	else {
		cout << "false\n";
	}

	cout << "a>b: ";
	if (a > b) {
		cout << "true\n";
	}

	else {
		cout << "false\n";
	}

	cout << "a>=b: ";
	if (a >= b) {
		cout << "true\n";
	}

	else {
		cout << "false\n";
	}

	cout << "a++: ";
	(a++).print();
	cout << "--a: ";
	(--a).print();
	cout << "a--: ";
	(a--).print();

	b = a;
	cout << "b-a: ";
	(b - a).print();
	cout << "b/a: ";
	(b / a).print();

	cout << "a!=b: ";
	if (a != b) {
		cout << "true\n";
	}

	else {
		cout << "false\n";
	}

	cout << "a<b: ";
	if (a < b) {
		cout << "true\n";
	}

	else {
		cout << "false\n";
	}

	cout << "a>=b: ";
	if (a >= b) {
		cout << "true\n";
	}



	return 0;
}