#include <iostream> 
#include <string> 
#include "AgeCalc.cpp"

using namespace std;

int main() {
	AgeCalculator gen(4, 28, 2004);
	cout << gen.printYearAndAge();
	cout << "Reminder that your next birthdays is in " << gen.nextBirthdayInDays() << " days." << endl;
	return 0;
}
