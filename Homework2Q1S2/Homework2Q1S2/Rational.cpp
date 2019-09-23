#include "Rational.h";

Rational::Rational(int top = 1, int bottom = 1) : numerator(top), denominator(bottom) {

}

Rational::Rational(const Rational &first) : numerator(first.numerator), denominator(first.denominator) {

}

void Rational::setNumerator(int top) {
	numerator = top;
}

void Rational::setDenominator(int bottom) {
	denominator = bottom;
}

int Rational::getNumerator() const{
	return numerator;
}

int Rational::getDenominator() const{
	return denominator;
}

void Rational::print() {
	if (denominator == 0) {
		cout << "ERROR\n";
		denominator = 1;
	}

	else if (numerator == 0) {
		cout << numerator << endl;
	}

	else {
		if (numerator == denominator) {
			cout << 1 << endl;
		}

		else {
			reduce();
			cout << numerator << "/" << denominator << endl;
		}
	}
}

void Rational::reduce() {
	for (int i = 2; i < denominator; i++) {
		for (int j = 2; j < denominator; j++) {
			if (numerator % j == 0 && denominator % j == 0) {
				numerator = numerator / j;
				denominator = denominator / j;
			}
		}
	}
}

Rational &Rational::operator=(const Rational &first) {
	numerator = first.numerator;
	denominator = first.denominator;
	return *this;

}
bool Rational::operator==(const Rational &first) const{
	if (numerator * first.denominator == denominator * first.numerator) {
		return true;
	}

	else {
		return false;
	}
}
bool Rational::operator!=(const Rational &first) const{
	if (numerator * first.denominator != denominator * first.numerator) {
		return true;
	}

	else {
		return false;
	}
}
bool Rational::operator<(const Rational &first) const{
	return (numerator * first.denominator < denominator * first.numerator);
}

bool Rational::operator>(const Rational &first) const{
	return (numerator * first.denominator > denominator * first.numerator);
}

bool Rational::operator<=(const Rational &first) const{
	return (numerator * first.denominator <= denominator * first.numerator);
	
}

bool Rational::operator>=(const Rational &first) const{
	return (numerator * first.denominator >= denominator * first.numerator);
}

Rational Rational::operator+(Rational first) {
	Rational temp;
	temp.setNumerator(numerator * first.getDenominator() + denominator * first.getNumerator());
	temp.setDenominator(denominator * first.getDenominator());
	return temp;
}

Rational Rational::operator-(Rational first) {
	Rational temp;
	temp.setNumerator(numerator * first.getDenominator() - denominator * first.getNumerator());
	temp.setDenominator(denominator * first.getDenominator());
	return temp;
}

Rational Rational::operator*(Rational first) {
	Rational temp;
	temp.setNumerator(numerator*first.getNumerator());
	temp.setDenominator(denominator*first.getDenominator());
	return temp;
}

Rational Rational::operator/(Rational first) {
	Rational temp;
	temp.setNumerator(numerator*first.getDenominator());
	temp.setDenominator(denominator*first.getNumerator());
	return temp;
}

void Rational::operator+=(Rational first) {
	setNumerator(numerator * first.getDenominator() + denominator * first.getNumerator());
	setDenominator(denominator * first.getDenominator());
}

void Rational::operator-=(Rational first) {
	setNumerator(numerator * first.getDenominator() - denominator * first.getNumerator());
	setDenominator(denominator * first.getDenominator());
}

void Rational::operator*=(Rational first) {
	setNumerator(numerator * first.getNumerator());
	setDenominator(denominator * first.getDenominator());
}

void Rational::operator/=(Rational first) {
	setNumerator(numerator * first.getDenominator());
	setDenominator(denominator * first.getNumerator());
}

Rational Rational::operator++() {
	numerator = numerator + denominator;
	return *this;
}

Rational Rational::operator--() {
	numerator = numerator - denominator;
	return *this;
}

Rational Rational::operator++(int x) {
	Rational temp = *this;
	numerator = numerator + denominator;
	return temp;
}

Rational Rational::operator--(int x) {
	Rational temp = *this;
	numerator = numerator - denominator;
	return temp;
}
