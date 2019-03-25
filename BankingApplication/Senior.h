#ifndef SENIOR_H
#define SENIOR_H
#include <iostream>
#include <string>
#include "Customer.h"

class Senior : public Customer
{
public:
	Senior(std::string name, std::string address, int age, std::string telephone_number, int customer_id) : Customer(name, address, age, telephone_number, customer_id)
	{
		checking_rate = 0.3;
		saving_rate = 0.7;
	}
	~Senior() {}
};
#endif