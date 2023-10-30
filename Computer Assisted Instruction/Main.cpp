#include <iostream>
#include <ctime>
#include <random>
#include <cmath>

using namespace std;

inline void promptQuestion(int num1, int num2, string op)
{
	cout << "How much is " << num1 << op << num2 << "? ";
}

int getRandomDigit(int scaleFactor) { return rand() % scaleFactor; }

string correct_response()
{
	switch(getRandomDigit(4) + 1){
		case 1: return "Very good!"; break;
		case 2: return "Excellent!"; break;
		case 3: return "Nice work!"; break;
		case 4: return "Keep up the good work!"; break;
	}
}

string incorrect_response()
{
	switch(getRandomDigit(4) + 1){
		case 1: return "No. Please try again."; break;
		case 2: return "Wrong. Try once more."; break;
		case 3: return "Don't give up!"; break;
		case 4: return "No. Keep trying."; break;
	}
}

int main()
{
	const size_t SIZE{4};
	cout << "=======================\n\tWELCOME\n=======================\nEnter -1 to end the program\n" << endl;
	srand(static_cast<unsigned int>(time(0)));
	
	int difficulty = 0;
	int userChoice = 0;
	
	int range = 10;

	while(true) {
		int correctAnswer{0};
		int incorrectAnswer{0};
		int arithType = 0;
		
		for (; difficulty <= 0 || difficulty > 4;){
			cout << "Enter Difficulty level(1 - 4): ";
			cin >> difficulty;
		}
		
		range = pow(10, difficulty);
		
		for (; arithType <= 0 || arithType > 5;) {
			cout << "Types of arithmetic problem:\n1 - addition \n2 - subtraction \n3 - multiplication \n4 - division (integer) \n5 - random mixture\nType: ";
			cin >> arithType;
			if (arithType == 5) arithType = 1 + getRandomDigit(5);
		}
		
		int answer = 0;
		
		do{
			int number1{getRandomDigit(range)};
			int number2{getRandomDigit(range)};
			
			do{	
				switch(arithType) {
					case 1: promptQuestion(number1, number2, " + "); break;
					case 2: promptQuestion(number1, number2, " - "); break;
					case 3: promptQuestion(number1, number2, " * "); break;
					case 4: promptQuestion(number1, number2, " / "); break;
				}
				cin >> userChoice;
				
				switch(arithType) {
					case 1: answer = number1 + number2; break;
					case 2: answer = number1 - number2; break;
					case 3: answer = number1 * number2; break;
					case 4: answer = number1 / number2; break;
				}
				
				if (answer == userChoice){
					cout << correct_response() << endl;
					++correctAnswer;
				}
				else{
					cout << incorrect_response() << endl;
					++incorrectAnswer;
				}
				
			} while(answer != userChoice && (correctAnswer + incorrectAnswer) != 10);
		
		} while((correctAnswer + incorrectAnswer) != 10);
		
		cout << (((static_cast<double>(correctAnswer) / 10) * 100) > 75 ? "Congratulations, you are ready to go to the next level!" : "Please ask your teacher for extra help") << endl;
		
		char playAgain;
		cout << "Continue (y/n): ";
		cin >> playAgain;
		if (playAgain == 'n') break;
	}
	
	return 0;	
}


