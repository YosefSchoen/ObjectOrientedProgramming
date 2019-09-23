#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
	Student(int Id, int NOC, string N, string LN);
	virtual ~Student() {};

	virtual bool milga() = 0;
	virtual void print() = 0;
protected:
	int id;
	int numOfCourses;
	string name;
	string lastName;
};