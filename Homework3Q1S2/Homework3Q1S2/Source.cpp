#include "String.h"

int main() {
	string a;
	string b;
	int n;

	cin >> a >> b >> n;

	String(a, n);
	String(b, n);

	if (a < b) {
		cout << "a<b\n";
	}

	else if (a > b) {
		cout << "a>b\n";
	}

	else if (a == b) {
		cout << "a=b\n";
	}

	if (n > a.length() || n > b.length()) {
		cout << "ERROR\n";
	}

	else {
		cout << b.insert(n, a) << endl;
	}


	return 0;
}