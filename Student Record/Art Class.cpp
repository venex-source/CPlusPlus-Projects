#include <sstream>
#include <stdexcept>
#include <iomanip>

#include "Art Class.h"

using namespace std;

Art::Art(string nam, string branch, short attends,
	 short math_score, short english_score, short literature_score, short visualart_score)
	 	: StudentRecord(nam, branch, attends, math_score, english_score)
	 	{
	 		setLiterature(literature_score);
			setVisualArt(visualart_score);	
		}
	
void Art::setLiterature(short value){
	if(value < 0 && value > 100)
		throw invalid_argument("Invalid value for literature");
	
	literature = value;
}

short Art::getLiterature() const { return literature; }
		
void Art::setVisualArt(short value){
	if(value < 0 && value > 100)
		throw invalid_argument("Invalid value for visual art");
	
	visualArt = value;
}

short Art::getVisualArt() const { return visualArt; }

short Art::TotalMark() const
{
	return StudentRecord::TotalMark() + getLiterature() + getVisualArt();
}

string Art::toString() const
{
	ostringstream output;
	
	output << "Art Class:\n" 
		<< StudentRecord::toString()
		<< setw(9) << getLiterature() << setw(9) 
		<< getVisualArt() << endl;

	return output.str();
}
