#pragma once
#include <iostream>
using namespace std;

class Account {
public:
	enum ERR{WrongCode, MoreThan10000, MoreThan2500, LessThan6000};
	Account();
	Account(int a, int c, int b);

	void setBalance(int b);
	
	int getAccountNumber();
	int getCode();
	int getBalance();

	int withdraw(int nis);
	int deposit(int nis);

	static int getSumWithdraw();
	static int getSumDeposit();

	friend istream &operator >> (istream &, Account &);



private:
	int accountNumber;
	int code;
	int balance;

	static int sumWithdraw;
	static int sumDeposit;
};