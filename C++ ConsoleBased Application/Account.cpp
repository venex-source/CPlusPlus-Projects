#include <stdexcept>
#include "Account.h"

using namespace std;

Account::Account(const string& name, const string& city, unsigned accNum, int64_t balance)
	: Customer(name, city, accNum, balance) {	}

void Account::FundOrWithdrawBalance(int64_t amount)
{
	Customer::setBalance(amount);
}

int64_t Account::promptAmount(const std::string& prompt)
{
	int64_t amount;
	cout << prompt;
	cin >> amount;
	return amount;
}

bool Account::isAccount(const unsigned& userInputAccNum)
{
	return userInputAccNum == this->getAccountNumber();
}

bool Account::isFundSufficient(int64_t& amount)
{
	return (this->getBalance() > 10) && (amount >= this->getBalance());
}

void Account::DisplayAccountBalance() const
{
	cout << "\nYour current balance is $" << Customer::getBalance() << endl;
}
