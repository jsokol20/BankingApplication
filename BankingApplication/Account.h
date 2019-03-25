#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>
#include <vector>
#include <sstream>
#include "Customer.h"
#include "Transaction.h"

class Account {
protected:
	Customer *customer;		// The customer who owns this account
	double balance;			// The available balance in this account
	int account_number;	// A unique number identifying this account
	std::vector<Transaction *> transactions;  // The record of transactions that have occured with this account


											  // This string shows checking and overdraft fees

	std::string get_fees()
	{
		int overdraft, charge;

		// This code below utilizes polymorphism. It basically calls the correct virtual methods from the specific customer type

		overdraft = customer->get_overdraft_fee();
		charge = customer->get_checking_fee();
		std::stringstream ss;
		ss << "Check Charge: " << charge << " Overdraft Fee: " << overdraft;
		return ss.str();
	}

protected:

	// Adds interest based on the specified interest rate to the account

	void add_interest(double interest) {
		double amt = balance*interest;
		balance = balance + amt;
		std::string fees = get_fees();
		Transaction *tran = NULL;
		std::string customer_number = (*customer).get_telephone_number();
		std::string type = "add interest";
		tran = new Transaction(customer_number, type, amt, fees);
		transactions.push_back(tran);
	}

public:
	// This Constructor requires a customer to create an account
	// Also, balance always starts with 0 when account is created.

	Account(Customer *cust, int id) : customer(cust), account_number(id), balance(0) {}

	// Generic accesser and setter methods for properties customer, balance, and account_number

	Customer *get_customer() {
		return customer;
	}

	void set_customer(Customer *cust) {
		customer = cust;
	}

	int get_account() {
		return account_number;
	}

	void set_balance(double new_balance) {
		balance = new_balance;
	}

	void set_account(int account_number) {
		this->account_number = account_number;
	}

	double get_balance() {
		return balance;
	}

	// This method describes the account information.

	virtual std::string to_string() {
		std::stringstream ss; // for composing the string that describes this account

		ss << "  Customer's Name: " << customer->get_name() << std::endl;
		ss << "  Customer's Age: " << customer->get_age() << std::endl;
		ss << "  Customer's Address: " << customer->get_address() << std::endl;
		ss << "  Customer's Telephone: " << customer->get_telephone_number() << std::endl;

		ss << "  Balance: " << balance << std::endl;
		ss << "  Account ID: " << account_number << std::endl;
		return ss.str();
	}

	// Deposits amount into account

	virtual void deposit(double amt) {
		balance += amt;
		std::string fees = get_fees();
		Transaction *tran = NULL;
		std::string customer_number = (*customer).get_telephone_number();
		std::string type = "deposit";
		tran = new Transaction(customer_number, type, amt, fees);
		transactions.push_back(tran);
	}

	// Withdraws amount from account
	virtual void withdraw(double amt) {
		balance -= amt;
		std::string fees = get_fees();
		Transaction *tran = NULL;
		std::string customer_number = (*customer).get_telephone_number();
		std::string type = "withdrawal";
		tran = new Transaction(customer_number, type, amt, fees);
		transactions.push_back(tran);
	}

	// Savings_Account and Checking_Account will implement this.
	virtual void add_interest() = 0;

};


#endif