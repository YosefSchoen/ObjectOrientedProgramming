#include "Clock.h"

Clock::Clock() {
	hour = 0;
	minute = 0;
	second = 0;
}

Clock::Clock(int h, int m, int s) {
	if (h < 0 || m < 0 || m > 59 || s < 0 || s > 59) {
		h = 0;
		m = 0;
		s = 0;
	}

	hour = h;
	minute = m;
	second = s;
}

Clock::Clock(const Clock &other) {
	hour = other.hour;
	minute = other.minute;
	second = other.second;
}

void Clock::setHour(int h) {
	if (h < 0) {
		throw NegativeHour;
	}

	else {
		hour = h;
	}
}

void Clock::setMinute(int m) {
	if (m < 0) {
		throw NegativeMinute;
	}

	else if (m > 59) {
		throw TooManyMinutes;
	}

	else {
		minute = m;
	}
}

void Clock::setSecond(int s) {
	if (s < 0) {
		throw NegativeSecond;
	}

	else if (s > 59) {
		throw TooManySeconds;
	}

	else {
		second = s;
	}
}


int Clock::getHour() {
	return hour;
}

int Clock::getMinute() {
	return minute;
}

int Clock::getSecond() {
	return second;
}

void Clock::operator+=(int s) {
	second = second + s;
	minute = minute + (second / 60);
	hour = hour + (minute / 60);

	second = second % 60;
	minute = minute % 60;
}

istream &operator>>(istream &in, Clock &other) {
	char colon;

	in >> other.hour >> colon;

	if (colon != ':') {
		throw Clock::Format;
	}

	else {
		in >> other.minute >> colon >> other.second;
	}
	return in;
}

ostream &operator<<(ostream &out, Clock &other) {
	int zero = 0;
	char colon = ':';

	try {
		if (other.hour < 10) {
			out << zero << other.hour << colon;
		}

		else {
			out << other.hour << colon;
		}

		if (other.minute < 10) {
			out << zero << other.minute << colon;
		}

		else {
			out << other.minute << colon;
		}

		if (other.second < 10) {
			out << zero << other.second;
		}

		else {
			out << other.second;
		}
	}

	catch (Clock::ERR err) {
		if (err = Clock::Format) {
			cout << "Wrong time format.\n";
		}

		if (err = Clock::TooManySeconds) {
			cout << "Invalid time – more than 60 seconds\n";
		}

		if (err = Clock::TooManyMinutes) {
			cout << "Invalid time – more than 60 minutes.\n";
		}

		if (err = Clock::NegativeSecond) {
			cout << "Invalid time – negative number of seconds.\n";
		}

		if (err = Clock::NegativeMinute) {
			cout << "Invalid time – negative number of minutes.\n";
		}

		if (err = Clock::NegativeHour) {
			cout << "Invalid time – negative number of hours.\n";
		}

	}

	return out;
}