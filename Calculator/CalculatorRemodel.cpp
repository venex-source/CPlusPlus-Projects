#include <iostream>
#include "Calculator.cpp"

using namespace std;

int main(){
	cout << "\t\t\t\tWelcome To My Calculator App\n";
	
	Calc go;
	
	while(true)
		go.run();
	return 0;
}
