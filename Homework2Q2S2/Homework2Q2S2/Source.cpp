#include "Date.h"

int main() {
	enum OPTIONS{SetDate = 1, PrintPost, PrintPre, EnterNumOfDays, GreaterThan, LessThan, IsEqual, Exit = -1};
	int options;
	int day;
	int month;
	int year;
	char slash;
	

	cout << "Enter a date\n";

	cin >> day >> slash >> month >> slash >> year;

	Date mydate(day, month, year);
	Date newDate(1, 1, 1970);

	cout << "what do you want to do\n";
	cin >> options;
	while (options != -1) {
		switch (options) {

		case SetDate:
			cout << "Enter a date\n";
			cin >> day >> slash >> month >> slash >> year;
			mydate.setDate(day, month, year);
			mydate.print();
			break;

		case PrintPost:
			mydate++;
			break;

		case PrintPre:
			++mydate;
			break;

		case EnterNumOfDays:
			cout << "Enter #Days\n";
			cin >> day;
			mydate += day;
			mydate.print();
			break;

		case GreaterThan:
			cout << "Enter a date\n";

			cin >> day >> slash >> month >> slash >> year;

			newDate.setDate(day, month, year);

			cout << ">:";

			if (mydate > newDate) {
				cout << "true\n";
			}

			else {
				cout << "false\n";
			}
			break;

		case LessThan:
			cout << "Enter a date\n";

			cin >> day >> slash >> month >> slash >> year;

			newDate.setDate(day, month, year);

			cout << "<:";

			if (mydate < newDate) {
				cout << "true\n";
			}

			else {
				cout << "false\n";
			}
			break;

		case IsEqual:
			cout << "Enter a date\n";

			cin >> day >> slash >> month >> slash >> year;

			newDate.setDate(day, month, year);

			cout << "==:";

			if (mydate == newDate) {
				cout << "true\n";
			}

			else {
				cout << "false\n";
			}
			break;

		case Exit:
			break;
		}

		cout << "what do you want to do\n";
		cin >> options;

	}
	return 0;
}