#ifndef ADULT_H
#define ADULT_H
#include <iostream>
#include <string>
#include "Customer.h"

class Adult : public Customer
{
public:
	Adult(std::string name, std::string address, int age, std::string telephone_number, int customer_id) : Customer(name, address, age, telephone_number, customer_id)
	{
		checking_rate = 0.35;
		saving_rate = 0.5;
	}
	~Adult() {}

};
#endif