#include "Rational.h";
#include <iostream>
using namespace std;

Rational::Rational(int top, int bottom) {
	numerator = top;
	denominator = bottom;
}

void Rational::setNumerator(int top) {
	numerator = top;
}

void Rational::setDenominator(int bottom) {
	denominator = bottom;
}


int Rational::getNumerator() {
	return numerator;
}

int Rational::getDenominator() {
	return denominator;
}

void Rational::print() {
	cout << numerator << "/" << denominator << endl;
}

bool Rational::equal(Rational second) {
	if (numerator * second.getDenominator() == denominator * second.getNumerator()) {
		return true;
	}
	else {
		return false;
	}

}
int Rational::reduce() {
	if (numerator == denominator) {
		return 1;
	}
	else {
		for (int i = 2; i <= numerator; i++) {
			if ((numerator % i == 0) && (denominator % i == 0)) {
				numerator = numerator / i;
				denominator = denominator / i;
			}
		}
	}
	return 0;
}