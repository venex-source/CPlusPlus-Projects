#include "PhoneBook.h"

using namespace std;

Record::Record(unsigned number, const string& fname, const string& lname, const string& place, const string& add){
	setPhoneNumber(number);
	setFirstName(fname);
	setLastName(fname);
	setCity(place);
	setAddress(add);
}

void Record::setFirstName(const std::string& name)
{
	size_t length{ name.size() < 20 ? name.size() : 19 };
	name.copy(firstName, length);
	firstName[length] = '\0';
}

void Record::setLastName(const std::string& name)
{
	size_t length{ name.size() < 20 ? name.size() : 19 };
	name.copy(lastName, length);
	lastName[length] = '\0';
}

void Record::setCity(const std::string& place)
{
	city = place;
}

void Record::setAddress(const std::string& add)
{
	address = add;
}

void Record::setPhoneNumber(unsigned key)
{
	phoneNumber = key < 0 ? 0 : key;
}
		
		
string Record::getFirstName() const { return firstName; }

string Record::getLastName() const { return lastName; }

string Record::getCity() const { return city; }

string Record::getAddress() const { return address; }

unsigned Record::getPhoneNumber() const{ return phoneNumber; }
