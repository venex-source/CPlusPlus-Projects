 #ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer{
		char name[20];
		char address[20];
		unsigned int accountNumber{};
		int64_t balance{};
	public:
		explicit Customer(const std::string& = "", const std::string& = "", unsigned = 0, int64_t = 0.0);
		
		void setName(const std::string&);
		void setAddress(const std::string&);
		void setAccountNumber(unsigned int);
		void setBalance(int64_t);
		
		std::string  getName() const;
		std::string  getAddress() const;
		unsigned int getAccountNumber() const;
		int64_t      getBalance() const;
};

#endif
