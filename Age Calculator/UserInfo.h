#ifndef USERINFO_H
#define USERINFO_H
#include "AgeCalc.h"

class User{
	public:
		explicit User(std::string, std::string, char);

		// Setters function
		void setFirstName(std::string);
		void setLastName(std::string);
		void setSex(char);
		
		// Getters Function
		const std::string getFirstName() const;
		const std::string getLastName() const;
		const char getSex() const;
		
		// Print User Information
		const std::string userDetails(AgeCalculator&) const;
	private:
		std::string firstName;
		std::string lastName;
		char sex;
};

#endif
