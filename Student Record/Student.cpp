#include <iostream>
//#include <vector>

#include "Science Class.cpp"
//#include "Art Class.cpp"
//#include "Commercial Class.cpp"

using namespace std;

int main(){
	cout << "INVOKING DERIVED CLASSES TOSTRING FUNCTION:\n";
	
	cout << "\nDERIVED CLASS SCIENCE TOSTRING MEMBER FUNCTION\n";
	Science science{"Jefferson", "Wales", 98, 89, 78, 100, 92};
	cout << science.toString();
}
