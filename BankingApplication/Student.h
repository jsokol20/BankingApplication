#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "Customer.h"

class Student : public Customer
{
public:
	Student(std::string name, std::string address, int age, std::string telephone_number, int customer_id) : Customer(name, address, age, telephone_number, customer_id)
	{
		checking_rate = 0.4;
		saving_rate = 0.6;
	}
};
#endif 