#pragma once

class Rational {
public:
	
	Rational(int x, int y);
	
	void setNumerator(int x);
	void setDenominator(int y);

	int getNumerator();
	int getDenominator();

	void print();

	bool equal(Rational second);
	int reduce();

private:
	int numerator;
	int denominator;
	
};