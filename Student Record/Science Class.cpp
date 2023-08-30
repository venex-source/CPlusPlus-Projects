#include <sstream>
#include <stdexcept>
#include <iomanip>

#include "Science Class.h"

using namespace std;

Science::Science(string nam, string branch, short attends, short math_score, short english_score, short physic_score, short chemistry_score)
	 	: StudentRecord(nam, branch, attends, math_score, english_score)
	 	{
	 		setPhysic(physic_score);
			setChemistry(chemistry_score);	
		}
	
void Science::setPhysic(short value){
	if(value < 0 && value > 100)
		throw invalid_argument("Invalid value for physic");
	
	physic = value;
}

short Science::getPhysic() const { return physic; }
		
void Science::setChemistry(short value){
	if(value < 0 && value > 100)
		throw invalid_argument("Invalid value for chemistry");
	
	chemistry = value;
}

short Science::getChemistry() const { return chemistry; }

short Science::TotalMark() const
{
	return StudentRecord::TotalMark() + getPhysic() + getPhysic();
}

string Science::toString() const
{
	ostringstream output;
	
	output << "Science Class: " 
		<< StudentRecord::toString()
		<< setw(9) << getPhysic() << setw(9) 
		<< getChemistry() << endl;

	return output.str();
}
