#include"Student.h"

Student::Student(int ID, string fn, string ln) {
	id = ID;
	firstName = fn;
	lastName = ln;
}

Student::Student(const Student &other) {
	id = other.id;
	firstName = other.firstName;
	lastName = other.lastName;
}

bool Student::operator<(Student &other) {
	if (id >= other.id || firstName >= other.firstName || lastName >= other.lastName) {
		return false;
	}

	return true;
}

bool Student::operator>(Student &other) {
	if (id <= other.id || firstName <= other.firstName || lastName <= other.lastName) {
		return false;
	}

	return true;
}

bool Student::operator<=(Student &other) {
	if (id > other.id || firstName > other.firstName || lastName > other.lastName) {
		return false;
	}

	return true;
}

bool Student::operator>=(Student &other) {
	if (id < other.id || firstName < other.firstName || lastName < other.lastName) {
		return false;
	}

	return true;
}

bool Student::operator==(Student &other) {
	if (id != other.id || firstName != other.firstName || lastName != other.lastName) {
		return false;
	}

	return true;
}

Student Student::operator=(int other) {
	id = other;
	return *this;
}

Student Student::operator=(Student &other) {
	id = other.id;
	firstName = other.firstName;
	lastName = other.lastName;

	return *this;
}

istream& operator >> (istream &in, Student &other) {
	in >> other.id >> other.firstName >> other.lastName;

	return in;
}

ostream& operator<<(ostream &out, Student &other) {
	out << other.id << ' ' << other.firstName << ' ' << other.lastName << endl;

	return out;
}