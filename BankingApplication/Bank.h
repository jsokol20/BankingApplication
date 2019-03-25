#ifndef BANK_H_
#define BANK_H_
#include <vector>
#include <stdexcept>
#include <string>
#include "Account.h"
#include "Customer.h"
#include "Saving_Account.h"
#include "Checking_Account.h"
#include "Adult.h"
#include "Senior.h"
#include "Student.h"


class Bank
{
private:
	std::vector<Account *> accounts; // Bank utilezes some accounts
	std::vector<Customer *> customers;  // Bank utilizes some customers


public:
	int account_id;
	int customer_id;

private:
	/**
	Return a vector of accounts owned by the specified name of the customer.

	A vector of account IDs' will be returned. Also, each customer can have more than one account...
	*/
	std::vector<int> find_accounts_by_name(std::string name)
	{
		std::vector<int> user_accounts;
		for (size_t i = 0; i < accounts.size(); i++)
			if (accounts[i]->get_customer()->get_name() == name)
				user_accounts.push_back(accounts[i]->get_account());
		return user_accounts;
	}

	/**
	Searches and tries to find a customer based on a certain name

	Returns a customer object if found, NULL otherwise
	*/

	Customer *find_customer(std::string name)
	{

		for (size_t i = 0; i < customers.size(); i++)
			if (customers[i]->get_name() == name)
				return customers[i];
		return NULL;
	}

	/**
	Adds a new account to a customer object (irrespective of its specific type: adult, senior, or student)

	The newly created object will be returned
	*/

	Account * add_account(Customer *cust, std::string account_type)
	{
		Account *acct = NULL;
		if (account_type == "Savings")
		{
			acct = new Saving_Account(cust, account_id);
		}
		else if (account_type == "Checking")
		{
			acct = new Checking_Account(cust, account_id);
		}
		if (acct == NULL) {
			return NULL;
		}
		account_id++;
		accounts.push_back(acct);
		return acct;
		return acct;
	}

public:
	//Constructor
	Bank() : account_id(1000), customer_id(1000) {}

	/**
	Adds account for an existing user

	Returns the newly created account object if the customer exist, or NULL otherwise
	*/

	Account* add_account(std::string name, std::string account_type)
	{
		Customer *cust = find_customer(name);
		if (cust == NULL)
			return NULL;
		return add_account(cust, account_type);
	}

	/**
	Adds account for new user.  This creates a new customer and adds an account to him/her.

	Returns the newly created account object
	*/
	Account* add_account(std::string name, std::string address, std::string telephone, int age,
		std::string cust_type, std::string account_type)
	{
		Customer *cust;

		if (cust_type == "Adult")
		{
			cust = new Adult(name, address, age, telephone, customer_id);
		}
		else if (cust_type == "Senior")
		{
			cust = new Senior(name, address, age, telephone, customer_id);
		}
		else if (cust_type == "Student")
		{
			cust = new Student(name, address, age, telephone, customer_id);
		}
		customers.push_back(cust);
		return add_account(cust, account_type);
	}

	// Makes a deposit in an account identified by the account id

	void make_deposit(int acct_number, double amt)
	{
		Account *acct = get_account(acct_number);
		if (acct) {
			acct->set_balance(acct->get_balance() + amt);

		}
	}

	// Makes a withdrawal in an account identified by the account id

	void make_withdrawal(int acct_number, double amt)
	{
		Account *acct = get_account(acct_number);
		if (acct) {
			acct->set_balance(acct->get_balance() - amt);
		}
	}

	/**
	Gets the list of account numbers associated with a user, identified by his/her name

	Returns vector of account ids
	*/
	std::vector<int> get_account(std::string name)
	{
		return find_accounts_by_name(name);
	}

	/**
	Gets the account object for an account identified by an account id

	Returns the account object if it exists, NULL otherwise
	*/
	Account *get_account(int acct_number)
	{
		for (size_t i = 0; i < accounts.size(); i++) {
			if (accounts[i]->get_account() == acct_number)
				return accounts[i];
		}
		return NULL;
	}
};

#endif