#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H

#include <iostream>
#include <string>
#include "Account.h"

class Saving_Account : public Account
{
private:
	double interest = 4.5;
public:
	//constructor
	Saving_Account(Customer* cust, int account_id) : Account(cust, account_id) {}

	//destructor
	~Saving_Account() {}
	void add_interest()
	{
		Account::add_interest(interest);
	}
	std::string to_string() {
		std::string s = Account::to_string();

		std::stringstream ss;
		ss << "Account type: Saving" << std::endl;
		return s + ss.str();
	}
};
#endif