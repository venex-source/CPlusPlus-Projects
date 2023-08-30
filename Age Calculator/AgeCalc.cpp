#include <iostream>
#include <string>
#include <ctime>
#include <stdexcept>
#include <sstream>
#include "AgeCalc.h"

AgeCalculator::AgeCalculator(unsigned int mn, unsigned int dy, unsigned int yr){
	setYear(yr);
	setMonth(mn);
	setDay(dy);
	setAge();
}

void AgeCalculator::setMonth(unsigned int mn){
	if(mn > 0 && mn <= monthsPerYear)
		month = mn;
	else
		throw std::invalid_argument("Invalid Month Value!");
		
	daysPerMonth[2] = (isLeapYear(getYear()) ? LEAP : NO_LEAP);
}

void AgeCalculator::setDay(unsigned int dy){
	if(dy > 0 && dy <= daysPerMonth[getMonth()])
		day =  dy;
	else
		throw std::invalid_argument("Invalid value for day!");
}

void AgeCalculator::setYear(unsigned int yr){
	if(yr > 0)
		year = yr;
	else
		throw std::invalid_argument("Invalid year! Must be greater than 0.");
}

unsigned int AgeCalculator::getDay() const{ return day; }
unsigned int AgeCalculator::getMonth() const{ return month; }
unsigned int AgeCalculator::getYear() const{ return year; }
unsigned int AgeCalculator::getAge() const{ return age; }

void AgeCalculator::setAge() {
	
	if(currYear >= getYear()){
		int confirmAge{currYear - static_cast<int>(getYear())};
		age = currMonth >= getMonth() ? confirmAge : confirmAge - 1;
	}
	else
		throw std::invalid_argument("Invalid value! Birth year is greater than current year");
}

std::string AgeCalculator::printYearAndAge() const{
	std::ostringstream output;
	output << "Born: " << getDay() << '-' << getMonth() << '-' << getYear()
			<< "\nCurrent date:" << currDay << '-' << currMonth << '-' << currYear
			<< "\nAge: " << getAge() << " years old.\n";
	return output.str(); 
}

int AgeCalculator::nextBirthdayInDays(){
	int numOfDays{0};
	
	int dayDup{currDay};
	int monDup{currMonth};
	int yearDup{currYear};
	
	while(true){
		if(dayDup == getDay() and monDup == getMonth())
			return numOfDays;
		else{
			if(dayDup <= daysPerMonth[monDup]){
				++dayDup;
				++numOfDays;
					
			}
			
			else{
				dayDup = 1;
				if(monDup <= monthsPerYear){
					++monDup;
					++numOfDays;
				}
				
				else{
					++numOfDays;
					++yearDup;
					monDup = 1;
					daysPerMonth[2] = (isLeapYear(yearDup) ? LEAP : NO_LEAP);
				}
			}
		}
		
	}
return 0;
}

bool AgeCalculator::isLeapYear(unsigned int yr){
	return yr % 400 == 0 || (yr % 4 == 0 && yr % 100 !=0);
}
