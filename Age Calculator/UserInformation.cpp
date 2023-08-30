#include <iostream>
#include <string>
#include "UserInfo.cpp"
#include "AgeCalc.cpp"

using namespace std;

int main()
{
	User jk("Jefferson", "Kadiri", 'm');
	User gk("Godsent", "Kadiri", 'm');
	
	AgeCalculator age1(4, 28, 2004);
	AgeCalculator age2(11, 10, 2005);
	
	cout << jk.userDetails(age1);
	cout << "\n\n\n";
	cout << gk.userDetails(age2);
}
