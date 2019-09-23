#include <iostream>
#include <string>
using namespace std;

int main(){
	string myString;
	
	getline(cin, myString);

	for (int i = 0; i < myString.length(); i++) {
		if (myString[i] == ' ') {
			myString.replace(i, 1, "*");
		}
	}

	cout << myString << endl;

	for (int i = myString.rfind('*') + 1; i < myString.length(); i++) {
		myString.erase(i);
	}

	myString.append("#!!@1234");

	cout << myString << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < myString.length(); j++) {
			if (myString[j] == '*') {
				myString.erase(0, j + 1);
				break;
			}
		}

		cout << myString << endl;
	}
	return 0;
}
