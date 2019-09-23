#pragma once
#include <iostream>
using namespace std;

class Vector {
public:
	Vector();
	Vector(int);
	Vector(const Vector &);
	~Vector();

	int getCapacity();
	int getSize();

	void print();

	void operator=(const Vector &);
	bool operator==(const Vector &);
	int &operator[](int);
	int operator*(const Vector &);
	Vector operator+(const Vector &);

	void clear();
	void delLast();
	void insert(int val);

private:
	int *data;
	int capacity;
	int size;
};