#include "Students.h"

//enum to name various things user can do
enum Options {
	EXIT,
	ADD, 
	DELETE, 
	UPDATE, 
	CHECK, 
	PRINTSTUDENT, 
	PRINTLIST
};

//a list of instructions to be outputted to the user
void instructions() {
	cout << "press 1 to add a student" << endl;
	cout << "press 2 to delete a student" << endl;
	cout << "press 3 to update a student" << endl;
	cout << "press 4 to check a students registration" << endl;
	cout << "press 5 to print details about a student" << endl;
	cout << "press 6 to print the list of students in a course" << endl;
	cout << "press 0 to exit" << endl;
}

void nullStudents(fstream &studentFile) {
	int nullID = 0;
	char nullString[MAXNAME];
	bool nullCourse[MAXCOURSES];

	for (int i = 0; i < MAXNAME; i++) {
		if (i < MAXCOURSES) {
			nullCourse[i] = false;
		}
		nullString[i] = '0';
	}

	Students nullStudent(nullID, nullString, nullString, nullCourse);

	if (!studentFile.is_open()) {
		cout << "error while opening\n";
	}

	else {
		studentFile.seekp(0);
		for (int i = 0; i < MAX + 1; i++) {
			studentFile.write((char*)&nullStudent, sizeof(Students));
		}
	}
}

void addStudent(fstream &studentFile) {
	int id;
	char lastName[MAXNAME];
	char firstName[MAXNAME];
	bool courses[MAXCOURSES];

	cout << "enter the students id\n";
	cin >> id;

	cout << "enter the student's last name\n";
	cin.getline(lastName, MAXNAME);


	cout << "enter the student's first name\n";
	cin.getline(firstName, MAXNAME);

	cout << "enter 1 if the student is in a course and zero if not\n";
	for (int i = 0; i < MAXCOURSES; i++) {
			cin >> courses[i];
	}

	Students newStudent(id, lastName, firstName, courses);
	Students temp;

	studentFile.seekg((newStudent.getId() - 1) * sizeof(Students));

	studentFile.read((char*)&temp, sizeof(Students));

	if (temp.getId() == 0) {
		studentFile.seekp((newStudent.getId() - 1) * sizeof(Students));
		studentFile.write((char*)&newStudent, sizeof(Students));
	}

	else {
		cout << "Student" << newStudent.getId() << "already exists\n";
	}
}

void deleteStudent(fstream &studentFile, int id) {
	studentFile.seekg((id - 1) * sizeof(Students));
	studentFile.read();
}

void updateStudent(fstream &studentFile, int id) {
	studentFile.open("students.bin");
	bool courses[MAXCOURSES];

	studentFile.close();
}

void CheckRegistration(fstream &studentFile, int id, int courseNum) {
	studentFile.open("students.bin");


	studentFile.close();
}

void printStudentDetails(fstream &studentFile, int id) {
	studentFile.open("students.bin");
	if (id) {
		
	}


	studentFile.close();
}

void printListOfStudents(fstream &studentFile, int courseNum) {
	studentFile.open("students.bin");



	studentFile.close();

}

int main() {
	int id;
	int courseNum;
	int choice;

	fstream studentFile("students.bin");

	nullStudents(studentFile);

	instructions();
	cin >> choice;

	while (choice != 0) {
		switch (choice) {
		case ADD:
			cout << "adding a new student\n";
			addStudent(studentFile);
			break;

		case DELETE:
			cout << "enter the id of the student you wish to delete\n";
			cin >> id;
			deleteStudent(studentFile, id);
			break;

		case UPDATE:
			cout << "enter the id of the student you wish to update\n";
			cin >> id;
			updateStudent(studentFile, id);
			break;

		case CHECK:
			cout << "enter the id of the student you wish to check, and enter the course number\n";
			cin >> id >> courseNum;
			CheckRegistration(studentFile, id, courseNum);
			break;

		case PRINTSTUDENT: 
			break;

		case PRINTLIST: 
			break;

		case EXIT: 
			break;

		default: 
			cout << "ERROR\n";
			break;
		}

		instructions();
		cin >> choice;
	}

	return 0;
}