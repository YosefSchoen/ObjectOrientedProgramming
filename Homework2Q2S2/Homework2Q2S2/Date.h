#pragma once
#include <iostream>
using namespace std;

class Date {
public:
	Date(int d, int m, int y);
	Date(const Date &);

	void setDate(int d, int m, int y);
	int getDay();
	int getMonth();
	int getYear();

	void print();
	
	void operator++();
	void operator++(int);
	void operator+=(int);

	bool operator<(Date);
	bool operator>(Date);
	bool operator==(Date);

private:
	int day;
	int month;
	int year;
};