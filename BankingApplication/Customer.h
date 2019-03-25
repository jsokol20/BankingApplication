#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>

/**
The Bank has Customers.  Each Customer (object) has a name, address, age, and telephone number.
Additionally, there are specialized types of Customers: Adult, Senior, and Student.
Each type of Customer has its own checking and savings interest rates, as well as its own checking and overdraft fees.
*/
class Customer
{
private:
	std::string name;
	std::string address;
	int age;
	std::string telephone_number;
	int customer_id;
protected:
	double checking_rate;
	double saving_rate;
	int checking_fee;
	int overdraft_fee;
public:
	//constructor
	Customer(std::string new_name, std::string new_address, int new_age, std::string new_tel_number, int new_cust_id)
	{
		this->name = new_name;
		this->address = new_address;
		this->age = new_age;
		this->telephone_number = new_tel_number;
		this->customer_id = new_cust_id;
	}
	//Accessor Functions
	std::string get_name()
	{
		return name;
	}
	std::string get_address()
	{
		return address;
	}
	int get_age()
	{
		return age;
	}
	std::string get_telephone_number()
	{
		return telephone_number;
	}

	int get_customer_id()
	{
		return customer_id;
	}
	double get_checking_int_rate()
	{
		return checking_rate;
	}
	double get_saving_int_rate()
	{
		return saving_rate;
	}
	int get_checking_fee()
	{
		return checking_fee;
	}
	int get_overdraft_fee()
	{
		return overdraft_fee;
	}
	//Mutator Function
	void set_name(std::string n)
	{
		name = n;
	}
	void set_address(std::string add)
	{
		address = add;
	}
	void set_age(int a)
	{
		age = a;
	}
	void set_telephone_number(std::string tel_num)
	{
		telephone_number = tel_num;
	}
	void set_customer_id(int id)
	{
		customer_id = id;
	}
};
#endif