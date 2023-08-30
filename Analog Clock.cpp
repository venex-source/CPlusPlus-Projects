#include <iostream>
#include <ctime>

using namespace std;

int main(){
	while(true){
		system("cls");
		time_t t{ time(0) };
		tm* ltm = localtime(&t);
		int currentHour = ltm->tm_hour;
		int currentMinute = ltm->tm_min;
		int currentSecond = ltm->tm_sec;
		cout << currentHour << " : " << currentMinute << " : "  << currentSecond << endl;
	}
}
