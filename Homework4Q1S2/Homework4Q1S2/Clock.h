#pragma once
#include <iostream>
using namespace std;

class Clock {
	enum ERR {Format, TooManyMinutes, TooManySeconds, NegativeHour, NegativeMinute, NegativeSecond};
	Clock();
	Clock(int h, int m, int s);
	Clock(const Clock &);

	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);

	int getHour();
	int getMinute();
	int getSecond();

	void operator+=(int s);

	friend istream &operator>>(istream &, Clock &);
	friend ostream &operator<<(ostream &, Clock &);

private:
	int hour;
	int minute;
	int second;
};

