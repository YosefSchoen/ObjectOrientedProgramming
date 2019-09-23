#include "Vector.h"

Vector::Vector() {
	capacity = 10;
	data = new int[capacity];
}

Vector::Vector(int amount){
	capacity = amount;
	data = new int[capacity];
}

Vector::Vector(const Vector &other){
	capacity = other.capacity;
	size = other.size;
	data = new int[capacity];

	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

Vector::~Vector(){
	delete[] data;
}

int Vector::getCapacity(){
	return capacity;
}

int Vector::getSize(){
	return size;
}

void Vector::print(){
	cout << "capacity: " << capacity << " size: " << size << " val: " << endl;
	for (int i = 0; i < size; i++) {
		if (i < size - 1) {
			cout << data[i] << " ";
		}

		else {
			cout << data[i];
		}
	}

	cout << endl;
}

void Vector::operator=(const Vector &other){
	size = other.size;

	for (int i = 0; i < size; i++) {
		*(data + i) = *(other.data + i);
	}
}

bool Vector::operator==(const Vector &other){
	if (size != other.size) {
		return false;
	}

	for (int i = 0; i < size; i++) {
		if (*(data + i) != *(other.data + i)) {
			return false;
		}
	}

	return true;
}

int &Vector::operator[](int index){
	int match;

	if (index < size) {
		match = data[index];
		return match;
	}

	else {
		cout << "ERROR\n";
	}
}
int Vector::operator*(const Vector &other){
	int dotProduct = 0;

	if (size != other.size) {
		cout << "ERROR\n";
	}

	else {
		for (int i = 0; i < size; i++) {
			dotProduct = dotProduct + *(data + i) * *(other.data + i);
		}
	}

	return dotProduct;
}
Vector Vector::operator+(const Vector &other) {
	int newSize = size + other.size;

	Vector newVector(capacity);

	for (int i = 0; i < size; i++) {
		*(newVector.data + i) = *(data + i);
	}

	for (int i = size; i < newSize; i++) {
		*(newVector.data + i) = *(other.data + i);
	}

	return newVector;
}

void Vector::clear(){
	int size = 0;
}

void Vector::delLast(){
	
	if (size == 0) {
		cout << "ERROR\n";
	}

	else {
		size--;
	}
}

void Vector::insert(int val){

	if (size == capacity) {
		cout << "ERROR\n";
	}

	else {
		*(data + size) = val;
		size++;
	}
}