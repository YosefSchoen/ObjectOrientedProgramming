#include "String.h"

String::String(string, int) {

}

String& insert(int index, const String& str) {
	return insert(index, str);
}

string String::getString() {
	return a;
}
void String::setString(string b) {
	a = b;
}

bool String::operator<(const String& str) {
	
	for (int i = 0; i < index; i++) {
		if (a[i] >= str.a[i]) {
			return false;
		}
	}

	return true;
}

bool String::operator>(const String& str) {
	for (int i = 0; i < index; i++) {
		if (a[i] <= str.a[i]) {
			return false;
		}
	}

	return true;
}

bool String::operator<=(const String& str) {
	for (int i = 0; i < index; i++) {
		if (a[i] > str.a[i]) {
			return false;
		}
	}

	return true;
}

bool String::operator>=(const String& str) {
	for (int i = 0; i < index; i++) {
		if (a[i] < str.a[i]) {
			return false;
		}
	}

	return true;
}

bool String::operator!=(const String& str) {
	for (int i = 0; i < index; i++) {
		if (a[i] != str.a[i]) {
			return true;
		}
	}

	return false;
}

bool String::operator==(const String& str) {
	for (int i = 0; i < index; i++) {
		if (a[i] != str.a[i]) {
			return false;
		}
	}

	return true;
}