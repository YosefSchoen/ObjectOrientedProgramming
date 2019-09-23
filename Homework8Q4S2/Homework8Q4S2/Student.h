#pragma once
#include <iostream>
#include <string>
#include "SearchTree.h"
using namespace std;


class Student {
public:
	Student(int ID, string fn, string ln);
	Student::Student(const Student &other);

	bool operator<(Student &other);
	bool operator>(Student &other);
	bool operator<=(Student &other);
	bool operator>=(Student &other);

	bool operator==(Student &other);
	Student operator=(int other);
	Student operator=(Student &other);
	friend istream &operator >> (istream &in, Student &other);
	friend ostream &operator<<(ostream &out, Student &other);


private:
	int id;
	string firstName;
	string lastName;
};