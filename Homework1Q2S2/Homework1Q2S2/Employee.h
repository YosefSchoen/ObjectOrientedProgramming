#pragma once
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 20;
class Employee {
public:
	Employee::Employee(int SSID, char * user, float wage, int hours, int otWork);

	int Employee::getSocialSecurity();
	 
	char* Employee::getName();

	float Employee::getHourlyWage();

	int Employee::getHoursWorked();

	int Employee::getOvertimeHoursWorked();

	void Employee::setSocialSecurity(int socialSecurity);

	void Employee::setName(char name[MAX]);

	void Employee::setHourlyWage(float hourlyWage);

	void Employee::setHoursWorked(int hoursWorked);

	void Employee::setOvertimeHoursWorked(int overtimeHoursWorked);

	double Employee::salary();

private:
	int socialSecurity;
	char name[MAX];
	float hourlyWage;
	int hoursWorked;
	int overtimeHoursWorked;
 };