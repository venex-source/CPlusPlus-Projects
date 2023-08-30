#include <stdexcept>
#include <sstream>
#include <string>
#include "UserInfo.h"
#include "AgeCalc.h"

using namespace std;

User::User(string fname, string lname, char s)
{
	setFirstName(fname);
	setLastName(lname);
	setSex(s);
}

void User::setFirstName(string fname)
{
	if(fname.length() > 1)
		firstName = fname;
	else
		throw invalid_argument("First name should be more more than 1 character");
}

void User::setLastName(string lname)
{
	if(lname.length() > 1)
		lastName = lname;
	else
		throw invalid_argument("Last name should be more more than 1 character");
}

void User::setSex(char s)
{
	if(s == 'm' || s == 'f')
		sex = s;
	else
		throw invalid_argument("You can either be a male('m') or a female('f')");
}

const string User::getFirstName() const{ return firstName; }

const string User::getLastName() const{ return lastName; }

const char User::getSex() const{ return sex; }

const string User::userDetails(AgeCalculator& calc) const
{
	ostringstream output;
	output << "First Name: " << getFirstName()
			<< "\nLast Name: " << getLastName()
			<< "\nSex: " << getSex() << endl
			<< calc.printYearAndAge();
	return output.str();
}
