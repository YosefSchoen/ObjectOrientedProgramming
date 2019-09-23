#pragma once
#include <iostream>
using namespace std;

class Rational {
public:
	Rational(int top, int bottom);
	Rational(const Rational &num); 

	void setNumerator(int top);
	void setDenominator(int bottom);

	int getNumerator() const;
	int getDenominator() const;

	void print();

	void reduce();

	Rational &operator=(const Rational &);
	bool operator==(const Rational &) const;
	bool operator!=(const Rational &) const;
	bool operator<(const Rational &) const;
	bool operator>(const Rational &) const;
	bool operator<=(const Rational &) const;
	bool operator>=(const Rational &) const;

	Rational operator+(Rational);
	Rational operator-(Rational);
	Rational operator*(Rational);
	Rational operator/(Rational);

	void operator+=(Rational);
	void operator-=(Rational);
	void operator*=(Rational);
	void operator/=(Rational);
	

	Rational operator++();
	Rational operator--();
	Rational operator++(int);
	Rational operator--(int);

private:
	int numerator;
	int denominator;
};