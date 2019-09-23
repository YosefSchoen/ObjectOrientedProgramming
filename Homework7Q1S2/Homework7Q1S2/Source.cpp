#include "MA.h"
#include "PHD.h"

void printMilga(Student *students[]) {
	for (int i = 0; i < 7; i++) {
		if (students[i]->milga() == true) {
			students[i]->print();
		}
	}
}

int main() {
	Student *students[7];

	int id[7] = { 123, 234, 345, 456, 567, 678, 789 };
	int numOfCourses[7] = { 3, 10, 7, 7, 1, 2, 2 };

	int *grades[4];
	grades[0] = new int[numOfCourses[0]] {90, 100, 90};
	grades[1] = new int[numOfCourses[1]] { 100, 100, 90, 100, 90, 100, 90, 100, 90, 100 };
	grades[2] = new int[numOfCourses[2]] { 90, 100, 90, 100, 90, 100, 90 };
	grades[3] = new int[numOfCourses[3]] { 90, 100, 90, 100, 90, 100, 90 };

	string name[7]{ "abe", "yitzhak", "yaacov", "sara", "rivka", "rachel", "leah" };
	string lastName[7]{ "avraham", "avrahamson", "jacobson", "emanu", "imanu", "jacobs", "jacobs" };

	bool research[2] = { false, true };
	int researchHours[3] = { 30, 20, 30 };


	for (int i = 0; i < 7; i++) {
		if (i < 2) {
			students[i] = new BA(id[i], numOfCourses[i], name[i], lastName[i], grades[i]);
		}

		else if (i >= 2 && i < 4) {
			students[i] = new MA(id[i], numOfCourses[i], name[i], lastName[i], grades[i], research[i - 2]);
		}

		else if (i >= 4 && i < 7) {
			students[i] = new PHD(id[i], numOfCourses[i], name[i], lastName[i], researchHours[i - 4]);
		}
	}
	
	printMilga(students);

	return 0;
}