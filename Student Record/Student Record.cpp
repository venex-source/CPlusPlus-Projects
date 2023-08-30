#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <cmath>

#include "Student Record.h"

using namespace std;

StudentRecord::StudentRecord(string nam, string branch, short attends, short math_score, short english_score)
	: name(nam), college(branch)
{
	setAttendance(attends);
	setMath(math_score);
	setEnglish(english_score);
}

void StudentRecord::setName(std::string& nam) { name = nam; }

string StudentRecord::getName() const { return name; }
		
void StudentRecord::setCollege(std::string& branch) { college = branch; }

string StudentRecord::getCollege() const { return college;}
		
void StudentRecord::setAttendance(short value){
	if(value < 0 && value > 100)
		throw invalid_argument("Invalid value for attendance");
	
	attendance = value;
}

short StudentRecord::getAttendance() const { return attendance; }
		
void StudentRecord::setMath(short value){
	if(value < 0 && value > 100)
		throw invalid_argument("Invalid value for Math score");
	
	math = value;
}

short StudentRecord::getMath() const { return math; }
		
void StudentRecord::setEnglish(short value){
	if(value < 0 && value > 100)
		throw invalid_argument("Invalid value for English score");
	
	english = value;
}
short StudentRecord::getEnglish() const { return english; }

short StudentRecord::TotalMark() const { return getMath() + getEnglish(); }

double StudentRecord::TotalMarkToPercentage() const
{
	return (double(TotalMark()) / 400) * 100;
}

char StudentRecord::TotalMarkInGrade() const
{
	switch(int(TotalMarkToPercentage())/10){
		case 10:
		case 9:
			return 'A';
			break;
			
		case 8:
			return 'B';
			break;
			
		case 7:
			return 'C';
			break;	
		
		case 6:
		case 5:
			return 'E';
			break;
			
		default:
			return 'F';
	}
}

string StudentRecord::toString() const{
	ostringstream output;
	output << getName() << setw(9) << getCollege() << setw(9)
		<< getAttendance() << setw(9) << getMath() << setw(9)
		<< getEnglish(); 

	return output.str();
}
