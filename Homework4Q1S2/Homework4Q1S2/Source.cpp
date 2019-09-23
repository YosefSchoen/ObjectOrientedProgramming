#include "Clock.h"
#include "Account.h"
using namespace std;
enum action
{
	stop,
	balance,
	withdraw,
	deposit,
	sumDeposit,
	sumWithdraw
};
action menu()
{
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (action)x;
}
int findAccount(Account* bank, int size)
{
	int number, code;
	cout << "please enter account number: ";
	cin >> number;
	int i = 0;
	while (i<size && bank[i].getAccountNumber() != number)
		i++;
	cout << "please enter the code: ";
	cin >> code;
	if (bank[i].getCode() == code)
		return i;
}
void printTransaction(Account a, action ac)
{
	Clock c();
	cout << c << "\t";
	;
	switch (ac)
	{
	case balance: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case deposit:
	case withdraw: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size)
{
	int i = findAccount(bank, size);
	printTransaction(bank[i], balance);
}
void checkDeposit(Account* bank, int size)
{
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of the check: ";
	cin >> amount;
	bank[i].deposit(amount);
	printTransaction(bank[i], deposit);
}
void cashWithdraw(Account* bank, int size)
{
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of money to withdraw: ";
	cin >> amount;
	bank[i].withdraw(amount);
	printTransaction(bank[i], withdraw);
}
int main()
{
	Account bank[10];
	cout << "enter account number and code for 10 accounts:\n";
	for (int i = 0; i<10; i++)
		cin >> bank[i];
	action ac = menu();
	while (ac)
	{
		switch (ac)
		{
		case balance: getBalance(bank, 10);
			break;
		case withdraw:cashWithdraw(bank, 10);
			break;
		case deposit:checkDeposit(bank, 10);
			break;
		case sumDeposit:printTransaction(bank[0], sumDeposit);
			break;
		case sumWithdraw:printTransaction(bank[0], sumWithdraw);

		}
		ac = menu();
	}
	return 0;
}
