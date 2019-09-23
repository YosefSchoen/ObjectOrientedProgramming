#include "Employee.h";

Employee::Employee(int SSID, char * user, float wage, int hours, int otWork) {
	socialSecurity = SSID;
	strcpy_s(name, user);
	hourlyWage = wage;
	hoursWorked = hours;
	overtimeHoursWorked = otWork;
}

int Employee::getSocialSecurity() {
	return socialSecurity;
}

char* Employee::getName() {
	return name;
}

float Employee::getHourlyWage() {
	return hourlyWage;
}

int Employee::getHoursWorked() {
	return hoursWorked;
}

int Employee::getOvertimeHoursWorked() {
	return overtimeHoursWorked;
}

void Employee::setSocialSecurity(int SSID) {
	socialSecurity = SSID;
}
void Employee::setName(char user[MAX]) {
	strcpy_s(name, user);
}

void Employee::setHourlyWage(float wage) {
	hourlyWage = wage;
}

void Employee::setHoursWorked(int hours) {
	hoursWorked = hours;
}

void Employee::setOvertimeHoursWorked(int otWork) {
	overtimeHoursWorked = otWork;
}

double Employee::salary() {
	return (hourlyWage * (hoursWorked + overtimeHoursWorked * 1.5));
}