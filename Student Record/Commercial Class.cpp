#include <sstream>
#include <stdexcept>
#include <iomanip>

#include "Commercial Class.h"

using namespace std;

Commercial::Commercial(string nam, string branch, short attends,
	 short math_score, short english_score, short marketing_score, short commerce_score)
	 	: StudentRecord(nam, branch, attends, math_score, english_score)
	 	{
	 		setMarketing(marketing_score);
			setCommerce(commerce_score);	
		}
	
void Commercial::setMarketing(short value){
	if(value < 0 && value > 100)
		throw invalid_argument("Invalid value for marketing");
	
	marketing = value;
}

short Commercial::getMarketing() const { return marketing; }
		
void Commercial::setCommerce(short value){
	if(value < 0 && value > 100)
		throw invalid_argument("Invalid value for commerce");
	
	commerce = value;
}

short Commercial::getCommerce() const { return commerce; }

short Commercial::TotalMark() const
{
	return StudentRecord::TotalMark() + getMarketing() + getCommerce();
}

string Commercial::toString() const
{
	ostringstream output;
	
	output << "Commerce Class:\n"
		<< StudentRecord::toString()
		<< setw(9) << getMarketing() << setw(9) 
		<< getCommerce() << endl;

	return output.str();
}
