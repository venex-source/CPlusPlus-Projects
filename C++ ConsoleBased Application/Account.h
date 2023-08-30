#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "Customer.cpp"

class Account: public Customer{
	public:
		Account(const std::string& = "", const std::string& = "", unsigned = 0, int64_t = 0.0);
		
		void FundOrWithdrawBalance(int64_t);
		int64_t promptAmount(const std::string&);
		bool isAccount(const unsigned&);
		bool isFundSufficient(int64_t&);
		void DisplayAccountBalance() const;
};

#endif
