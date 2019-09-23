#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "MA.h"
#include "PHD.h"
//#define nullptr NULL;
using namespace std;



enum option {
	stop,	//	exit
	addNewStudent,	//	add new student
	milgaList,	//	print info about all students eligible for milga
	mostResearch,	//	print name of PhD student with most research hours
	countMilgaBA,	//	print number of BA students eligible for milga
	noResearchMA,	//	print names of MA students that don’t do research
	overheadStudent,	//	print message if exists student with more than 15 courses
	removePHDFailers,	//	remove all PhD students that don’t take courses
};

void add(vector<Student> students) {

	//User choices
	int choice;
	int RChoice;

	//Iterator counter
	int BAs = 0;
	int MAs = 0;
	int PHDs = 0;

	//student info
	int id;
	string name;
	string lastName;
	int numOfCourses;
	int *grades;
	int research;

	//Counting the number of different types of students
	for (int i = 0; i < students.size(); i++) {
		if (students[i].studType() == "BA") {
			BAs++;
		}

		else if (students[i].studType() == "MA") {
			MAs++;
		}

		else if (students[i].studType() == "PHD") {
			PHDs++;
		}
	}

	//user inputs choice
	cout << "enter 1 to add a BA student\n";
	cout << "enter 2 to add a MA student\n";
	cout << "enter 3 to add a PHD student\n";
	cin >> choice;

	//user inputs student info
	cout << "enter id, first name, last name and number of Courses\n";
	cin >> id >> name >> lastName >> numOfCourses;
	grades = new int[numOfCourses];
	cout << "enter " << numOfCourses << "grades\n";

	for (int i = 0; i < numOfCourses; i++) {
		cin >> grades[i];
	}

	//user inputs RChoice (research choice)
	cout << "enter 1 if the student does research and 0 if not\n";
	cin >> RChoice;

	//user inputs hours of research done
	cout << "enter number of research hours\n";
	cin >> research;

	switch (choice) {
	case 1:
		students.insert(students.begin() + BAs, BA(id, name, lastName, numOfCourses, grades));
		break;
	case 2:
		students.insert(students.begin() + MAs, MA(id, name, lastName, numOfCourses, grades, research));
		break;
	case 3:
		students.insert(students.begin() + PHDs, PHD(id, name, lastName, numOfCourses, research));
		break;
	}
}

void milga(vector<Student> students) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i].milga()) {
			students[i].print();
		}
	}
}

Student* mostResearchHours(vector<Student> students) {
	int PHDs = 0;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].studType() == "PHD") {
			PHDs++;
		}
	}

	if (PHDs = 0) {
		return nullptr;
	}

	Student *research = &students[0];
	for (int i = 1; i < students.size(); i++) {
		if (students[i].getResearch() > students[i - 1].getResearch()) {
			research = &students[i];
		}
	}

	return research;
}

int main()
{
	vector<Student> students;
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != stop)
	{
		switch (op)
		{
		case addNewStudent:add(students);//add new student					break;
		case milgaList:milga(students);	//print details of milga students 
			break;
		case mostResearch: {
			//print name of student with most research hours
			Student* s = mostResearchHours(students);
			cout << "PHD studnet with most research hours: ";
			cout << s->getName() << ' ' << s->getName() << endl;
		}
						   break;
		case countMilgaBA:  cout << "#BA studnets for milga: ";
			for (int i = 0; i < students.size(); i++) {
				if (students[i].studType() == "BA" && students[i].milga()) {
					students[i].print();
				}
			}
			cout << endl;
			break;
		case noResearchMA:cout << "list of no research MA students : ";
			for (int i = 0; i < students.size(); i++) {
				if (students[i].studType() == "MA" && students[i].getResearch() == 0()) {
					students[i].print();
				}
			}
			cout << endl;
			break;
		case overheadStudent:
			for (int i = 0; i < students.size(); i++) {
				if (students[i].getNumOfCourses() > 15) {
					cout << "there is a student that takes more than 15 courses\n";
				}
				else cout << "no student takes more than 15 courses\n";
			}
			break;

		case removePHDFailers:
			for (int i = 0; i < students.size(); i++) {
				if (students[i].studType() == "PHD" && students[i].getNumOfCourses() == 0) {
					students.erase(students.begin() + i);
				}
			}

			for (int i = 0; i < students.size(); i++) {
				students[i].print();
			}
			break;
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}
