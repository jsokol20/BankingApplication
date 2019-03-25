#include <iostream>
#include <string>
#include <vector>
#include "Bank.h"
#include "readint.h"

using namespace std;

/**
This is where a new account is added in the bank
If it is a new customer, additional information will be gathered
to add a new customer record in the bank.

Bank object to which we will be adding accounts
*/
void Add_Account(Bank &bank)
{
	string name;
	cout << "Please enter your name: ";
	cin.ignore();
	getline(cin, name);

	int acct_type;
	string	menu_string = "Type of account: \n";
	menu_string += "   0 - Savings\n";
	menu_string += "   1 - Checking\n";
	menu_string += "Enter: ";
	acct_type = read_int(menu_string, 0, 1);

	string acct_type_str;
	if (acct_type == 0)
		acct_type_str = "Savings";
	else
		acct_type_str = "Checking";

	Account *acct = bank.add_account(name, acct_type_str); // attempt to add an account
	if (acct == NULL) { // case for new user
		cout << "You appear to be a new user.  We will need more information.\n";
		// get all the required information for a new user
		cout << "Address: ";
		string address;
		cin.ignore();
		getline(cin, address);
		string telephone;
		cout << "Telephone Number: ";
		getline(cin, telephone);
		cout << "Age: ";
		int age;
		cin >> age;

		int cust_type;
		string	menu_string = "Type of customer: \n";
		menu_string += "   0 - Adult\n";
		menu_string += "   1 - Senior\n";
		menu_string += "   2 - Student\n";
		menu_string += "Enter: ";
		cust_type = read_int(menu_string, 0, 2);

		string cust_type_str;
		if (cust_type == 0)
			cust_type_str = "Adult";
		else if (cust_type == 1)
			cust_type_str = "Senior";
		else
			cust_type_str = "Student";
		acct = bank.add_account(name, address, telephone, age, cust_type_str, acct_type_str);
	}
	if (acct) {
		cout << "Your new account ID is " << acct->get_account() << endl;
	}
	else {
		cout << "Sorry.  We failed to create an account for you\n";
	}
}

/**
The is where we list all the accounts owned by a customer (if he/she exists)

Bank object in which accounts are located
*/
void List_Account(Bank &bank)
{
	cout << "Please enter your name: ";
	string name;
	cin.ignore();
	getline(cin, name);

	vector<int> list = bank.get_account(name);
	cout << endl;
	for (size_t i = 0; i < list.size(); i++) {
		Account *acct = bank.get_account(list[i]);
		if (acct)
			cout << acct->to_string();
		cout << "---------------------------\n";
	}
	cout << "Total " << list.size() << " accounts found\n";
}

/**
This is where a deposit is made in an account, whcih is identified by its account ID

Bank object in which account is located
*/
void Make_Deposit(Bank &bank)
{
	int acct_id;
	cout << "Please enter your account ID: ";
	cin >> acct_id;
	double amt;
	cout << "Amount to deposit: ";
	cin >> amt;
	bank.make_deposit(acct_id, amt);
}

/**
This is where a withdrawal is made in the account, which is identified by its ID

Bank object in which account is located
*/
void Make_Withdrawal(Bank &bank)
{
	int acct_id;
	cout << "Please enter your account ID: ";
	cin >> acct_id;
	double amt;
	cout << "Amount to withdraw: ";
	cin >> amt;
	bank.make_withdrawal(acct_id, amt);
}

int main()
{
	Bank bank; // Bank is created

			   // Displays menu for banking activites
	cout << "Welcome to my Banking Application!\n";
	char choice;
	do {
		cout << endl;
		int select;
		string	menu_string = "Please choose an action below:\n";
		menu_string += "0 - Add Account\n";
		menu_string += "1 - List Accounts\n";
		menu_string += "2 - Make deposit\n";
		menu_string += "3 - Make withdrawal\n";
		menu_string += "4 - Quit\n";
		menu_string += "Enter: ";
		select = read_int(menu_string, 0, 4);

		// Performs the banking activity based on the user selection
		switch (select) {
		case 0:
			Add_Account(bank);
			break;
		case 1:
			List_Account(bank);
			break;
		case 2:
			Make_Deposit(bank);
			break;
		case 3:
			Make_Withdrawal(bank);
			break;
		default:
			cout << "Goodbye!  Thank you for visiting.\n";
			return 0;
		}

		cout << "Do you wish to perform another transaction? (y or n): ";
		cin >> choice;
	} while (choice != 'n');

	cout << "Goodbye!  Thank you for visiting.\n";
}