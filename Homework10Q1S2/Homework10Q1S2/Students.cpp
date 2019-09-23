#include "Students.h"


Students::Students() {
	id = 0;
	for (int i = 0; i < MAXNAME; i++) {
		if (i < MAXCOURSES) {
			courses[i] = 0;
		}

		lastName[i] = '0';
		firstName[i] = '0';
	}

}

Students::Students(int ID, char ln[MAXNAME], char fn[MAXNAME], bool c[MAXCOURSES]){
	id = ID;
	for (int i = 0; i < MAXNAME; i++) {
		if (i < MAXCOURSES) {
			courses[i] = c[i];
		}

		lastName[i] = ln[i];
		firstName[i] = fn[i];
	}
}

int Students::getId(){
	return id;
}
char Students::getLastName(){
	return *lastName;
}
char Students::getFirstName(){
	return *firstName;
}

bool Students::getCourses(){
	return *courses;
}

void Students::setId(int ID){
	id = ID;
}
void Students::setLastName(char ln[MAXNAME]){
	for (int i = 0; i < MAXNAME; i++) {
		lastName[i] = ln[i];
	}
}

void Students::setFirstName(char fn[MAXNAME]){
	for (int i = 0; i < MAXNAME; i++) {
		firstName[i] = fn[i];
	}
}

void Students::setCourses(bool c[MAXCOURSES]){
	for (int i = 0; i < MAXCOURSES; i++) {
		courses[i] = c[i];
	}
}

