#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX = 100;
const int MAXNAME = 20;
const int MAXCOURSES = 5;

class Students {
public:
	Students();
	Students(int ID, char ln[MAXNAME], char fn[MAXNAME], bool c[MAXCOURSES]);
	int getId();
	char getLastName();
	char getFirstName();
	bool getCourses();

	void setId(int ID);
	void setLastName(char ln[MAXNAME]);
	void setFirstName(char fn[MAXNAME]);
	void setCourses(bool c[MAXCOURSES]);

private:
	int id;
	char lastName[MAXNAME];
	char firstName[MAXNAME];
	bool courses[MAXCOURSES];
};