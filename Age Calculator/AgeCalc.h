#include <string>
#include <ctime>

#ifndef AGECALCULATOR_H
#define AGECALCULATOR_H

class AgeCalculator{
	public:
		explicit AgeCalculator(unsigned int = 1, unsigned int = 1, unsigned int = 2000);		//constructor with default values 			
		
		void setMonth(unsigned int);			//Set month
		void setDay(unsigned int);				//Set day
		void setYear(unsigned int);				//Set year
			
		unsigned int getMonth() const;			//return month 
		unsigned int getDay() const;			//return day
		unsigned int getYear() const;			//return year
		unsigned int getAge() const;			//return age
		
		
		void setAge();
		int nextBirthdayInDays();			//return number of days to birthday
		
		std::string printYearAndAge() const;
	private:
		bool isLeapYear(unsigned int); 
		
		time_t now = time(0);
		tm *ltm = localtime(&now);
		
		int currYear{1900 + ltm->tm_year};
		int currMonth{1 + ltm->tm_mon};
		int currDay{ltm->tm_mday};
		
		static const size_t monthsPerYear{12};
		static const int NO_LEAP{28};
		static const int LEAP{29};
		
		unsigned int daysPerMonth[monthsPerYear + 1] = {0,  31, NO_LEAP, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
		int age{1};
		unsigned int month{1};
		unsigned int day{1};
		unsigned int year{2000};
};

#endif
