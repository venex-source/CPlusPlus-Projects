#ifndef PHONEBOOK_H
#define PHONEBOOK_H

class Record{
	public:
		//constructor with default parameter
		explicit Record(unsigned = 0, const std::string& = "", const std::string& = "", const std::string& = "", const std::string& = "");
		
		
		// Setters
		void setFirstName(const std::string&);
		void setLastName(const std::string&);
		void setCity(const std::string&);
		void setAddress(const std::string&);
		void setPhoneNumber(unsigned);
		
		
		// Getters
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getCity() const;
		std::string getAddress() const;
		unsigned    getPhoneNumber() const;
		
	private:
		
		//data members
		unsigned phoneNumber;
		char firstName[20];
		char lastName[20];
		std::string city;
		std::string address;
		
};

#endif
