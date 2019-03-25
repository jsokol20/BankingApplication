#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include <iostream>
#include <string>
#include "Account.h"

class Checking_Account : public  Account
{
private:
	double interest = 3.5;
public:
	//constructor
	Checking_Account(Customer *cust, int id) : Account(cust, id) {}
	//destructor
	~Checking_Account() {}
	void add_interest()
	{
		Account::add_interest(interest);
	}
	std::string to_string() {
		std::string s = Account::to_string();

		std::stringstream ss;
		ss << "Account type: Checking" << std::endl;
		return s + ss.str();
	}
};

#endif