#include "Date.h"

Date::Date(int d = 1, int m = 1, int y = 1970) {
	day = d;
	month = m;
	year = y;

	if (d < 1 || d > 30) {
		cout << "ERROR day\n";
		day = 1;
	}

	if (m < 1 || m > 12) {
		cout << "ERROR month\n";
		month = 1;
	}
	if (y < 1970 || y > 2099) {
		cout << "ERROR year\n";
		year = 1970;
	}
}

Date::Date(const Date &first) {
	Date copy(day, month, year);
}

void Date::setDate(int d, int m, int y) {
	if (d >= 1 && d <= 30) {
		if (m >= 1 && m <= 12) {
			if (y >= 1970 || y <= 2099) {
				day = d;
				month = m;
				year = y;
			}
		}
	}
}
int Date::getDay() {
	return day;
}

int Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}

void Date::print() {
	cout << day << "/" << month << "/" << year << endl;
}

void Date::operator++() {
	int tempDay = day;
	int tempMonth = month + ((tempDay + 1) / 30);

	day = ((day + 1) % 30);
	month = (month + ((tempDay + 1) / 30) % 12);
	year = year + (tempMonth / 12);
	print();
}

void Date::operator++(int) {
	print();
	int tempDay = day;
	int tempMonth = month + ((tempDay + 1) / 30);

	day = ((day + 1) % 30);
	month = (month + ((tempDay + 1) / 30) % 12);
	year = year + (tempMonth / 12);
	
}

void Date::operator+=(int d) {
	int tempDay = day;
	int tempMonth = month + ((tempDay + d) / 30);

	day = ((day + d) % 30);
	month = (month + ((tempDay + d) / 30) % 12);
	year = year + (tempMonth / 12);
}

bool Date::operator<(Date dmy) {
	int originalDate = day + (month * 30) + (year * 360);
	int newDate = dmy.getDay() + (dmy.getMonth() * 30) + (dmy.getYear() * 360);

	if (originalDate < newDate) {
		return true;
	}

	else {
		return false;
	}
}

bool Date::operator>(Date dmy) {
	int originalDate = day + (month * 30) + (year * 360);
	int newDate = dmy.getDay() + (dmy.getMonth() * 30) + (dmy.getYear() * 360);

	if (originalDate > newDate) {
		return true;
	}

	else {
		return false;
	}
}

bool Date::operator==(Date dmy) {
	int originalDate = day + (month * 30) + (year * 360);
	int newDate = dmy.getDay() + (dmy.getMonth() * 30) + (dmy.getYear() * 360);

	if (originalDate == newDate) {
		return true;
	}

	else {
		return false;
	}
}

