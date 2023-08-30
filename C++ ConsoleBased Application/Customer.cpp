#include "Customer.h"

using namespace std;

Customer::Customer(const string& value, const string& add, unsigned acc, int64_t bal)
{
	setName(value);
	setAddress(add);
	setAccountNumber(acc);
	setBalance(bal);
}
		
void Customer::setName(const string& value)
{
	size_t length{ value.size() < 20 ? value.size() : 19 };
	value.copy(name, length);
	name[length] = '\0';
}
void Customer::setAddress(const string& value)
{
	size_t length{ value.size() < 20 ? value.size() : 19 };
	value.copy(address, length);
	address[length] = '\0';	
}
void Customer::setAccountNumber(unsigned int acc)
{
	accountNumber = acc;
}

void Customer::setBalance(int64_t bal)
{
	balance += bal;
}
			
string       Customer::getName() const { return name; }
string       Customer::getAddress() const { return address; }
unsigned int Customer::getAccountNumber() const { return accountNumber; }
int64_t      Customer::getBalance() const { return balance; }
