#pragma once
#include <iostream>
#include <string>
//#include <cstring>
using namespace std;

class String {
public:
	String(string, int);
	String& insert(int index, const String& str);

	string getString();
	void setString(string);

	bool operator<(const String& str);
	bool operator>(const String& str);
	bool operator<=(const String& str);
	bool operator>=(const String& str);
	bool operator!=(const String& str);
	bool operator==(const String& str);

private:
	int index;
	string a;
};