#include "Employee.h";

int main() {
	int socialSecurity;
	char name[MAX];
	float hourlyWage;
	int hoursWorked;
	int overtimeHoursWorked;

	Employee highestSalary(0, "", 0, 0, 0);
	Employee hardestWorker(0, "", 0, 0, 0);

	cout << "enter details, to end enter 0\n";

	cin >> socialSecurity;

	while (socialSecurity != 0) {
		cin >> name;
		cin >> hourlyWage >> hoursWorked >> overtimeHoursWorked;
		Employee worker(socialSecurity, name, hourlyWage, hoursWorked, overtimeHoursWorked);

		if (highestSalary.salary() < worker.salary()) {
			highestSalary = worker;
			/*(highestSalary.getSocialSecurity = worker.getSocialSecurity;
			highestSalary.getName = worker.getName;
			highestSalary.getHourlyWage = worker.getHourlyWage;
			highestSalary.getHoursWorked = worker.getHoursWorked;
			highestSalary.getOvertimeHoursWorked = worker.getOvertimeHoursWorked;
			highestSalary.salary = worker.salary;
			*/
		}

		if ((hardestWorker.getHoursWorked() + hardestWorker.getOvertimeHoursWorked()) < (worker.getHoursWorked() + worker.getOvertimeHoursWorked())) {
			hardestWorker = worker;
			/*
			hardestWorker.getSocialSecurity = worker.getSocialSecurity;
			hardestWorker.getName = worker.getName;
			hardestWorker.getHourlyWage = worker.getHourlyWage;
			hardestWorker.getHoursWorked = worker.getHoursWorked;
			hardestWorker.getOvertimeHoursWorked = worker.getOvertimeHoursWorked;
			hardestWorker.salary = worker.salary;
			*/
		}
		cin >> socialSecurity;
	}

	cout << "highest salary: " << highestSalary.getSocialSecurity() << " " << highestSalary.getName() << endl;
	cout << "hardest worker: " << hardestWorker.getSocialSecurity() << " " << hardestWorker.getName() << endl;

}