#include <string>
#include <cmath>
#include <stdexcept>
#include "Calculator.h"

using namespace std;

double Calc::getFirstNumber() const{ return firstNumber; }

double Calc::getSecondNumber() const{ return secondNumber; }

int Calc::getChoice() const{ return choice; }

void Calc::setFirstNumber(){
	cout << "Please enter your first value > ";
	cin >> firstNumber;
}

void Calc::setSecondNumber(){
	cout << "Please enter your second value > "; 
	cin >> secondNumber;
}

void Calc::setChoice(){
	cout << "\n\nPlease select an operator from the option below: "
		 << "\n1) Addition(+)"
		 << "\n2) Subtraction(-)"
		 << "\n3) Multiplication(*)"
		 << "\n4) Division(/)"
		 << "\n5) Pow(x^y)"
		 << "\n6) Exit\n>";
	cin >> choice;					//prompt user for option
	if(choice < 1 || choice > 6)
		throw invalid_argument("Invalid Option.");		// Throw error if user trys to choose an invalid option
}

void Calc::calculate() const{
	switch(getChoice()){
			case 1:
				cout << "\n\t\tAns: " << getFirstNumber() << '+' << getSecondNumber() << '=' << firstNumber + secondNumber;
				break;
			case 2:
				cout << "\n\t\tAns: " << getFirstNumber() << '-' << getSecondNumber() << '=' << firstNumber - secondNumber;
				break;
			case 3:
				cout << "\n\t\tAns: " << getFirstNumber() << '*' << getSecondNumber() << '=' << firstNumber * secondNumber;
				break;
			case 4:
				cout << "\n\t\tAns: " << getFirstNumber() << '/' << getSecondNumber() << '=' << firstNumber / secondNumber;
				break;
			case 5:
				cout << "\n\t\tAns: " << getFirstNumber() << '^' << getSecondNumber() << '=' << pow(firstNumber, secondNumber);
				break;
	}
}

void Calc::run(){
	setChoice();
	if(getChoice() != 6){
		setFirstNumber();
		setSecondNumber();
		calculate();
	}
	else
		exit(0);
	
}
