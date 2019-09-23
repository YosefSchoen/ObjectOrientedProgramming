#include "Student.h"

enum OPTIONS {
	ADD = 'a',
	DELETE,
	SEARCH,
	PRINT,
	EXIT
};

SearchTree<Student> studentTree;

void addStudent(Student &student) {
	studentTree.add(student);
}

void deleteStudent(Student &student) {
	studentTree.remove(student);
}

bool searchStudent(Student &student) {
	return studentTree.search(student);
}

void print() {
	studentTree.inOrder();
}

int main() {
	char choice;
	int id;
	string firstName;
	string lastName;

	cout << "enter a-e\n";
	cin >> choice;

	while (choice != 'e') {
		switch (choice) {
		case ADD: {
			cout << "enter a student\n";
			cin >> id >> firstName >> lastName;
			Student student(id, firstName, lastName);
			addStudent(student);
			break;
		}

		case DELETE: {
			cout << "enter a student\n";
			cin >> id >> firstName >> lastName;
			Student student(id, firstName, lastName);
			deleteStudent(student);
			break;
		}
		case SEARCH: {
			cout << "enter a student\n";
			cin >> id >> firstName >> lastName;
			Student student(id, firstName, lastName);
			if (searchStudent(student)) {
				cout << "exists\n";
			}

			else {
				cout << "not exist\n";
			}

			break;
		}

		case PRINT:
			print();
			break;

		case EXIT:
			break;

		default:
			cout << "error\n";
			break;
		}

		cout << "enter a-e\n";
		cin >> choice;
	}

	return 0;
}