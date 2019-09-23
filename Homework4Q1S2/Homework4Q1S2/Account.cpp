#include "Account.h"

Account::Account() {
	accountNumber = 0;
	code = 0;
	balance = 0;
}

Account::Account(int a, int c, int b) {
	accountNumber = a;
	code = c;
	balance = b;
}

void Account::setBalance(int b) {
	balance = b;
}

int Account::getAccountNumber() {
	return accountNumber;
}
int Account::getCode() {
	return code;
}
int Account::getBalance(){
	return balance;
}

int Account::withdraw(int nis) {
	if (nis > 2500) {
		throw MoreThan2500;
	}

	else if (balance - nis < 6000) {
		throw LessThan6000;
	}

	else {
		balance = balance - nis;
		sumWithdraw = sumWithdraw + nis;
	}
}
int Account::deposit(int nis) {
	if (nis > 10000) {
		throw MoreThan10000;
	}

	else {
		balance = balance + nis;
		sumDeposit = sumDeposit + nis;
	}
}

int Account::getSumWithdraw() {
	return sumWithdraw;
}

int Account::getSumDeposit(){ 
	return sumDeposit;
}

istream &operator>>(istream &in, Account &other) {
	in >> other.accountNumber >> other.code;
	return in;
}