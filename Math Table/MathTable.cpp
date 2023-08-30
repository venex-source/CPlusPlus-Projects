#include <string>
#include <iomanip>
#include <stdexcept>
#include "MathTable.h"

void Table::setValue()
{
	std::cout << "Enter a value from (1-20): ";
	std::cin >> value;
	if(value < 1 || value > 20)
		throw std::invalid_argument("Invalid Value. Should be from [1-20]");
}

void Table::setChoice()
{
	std::cin >> choice;
	if(choice < 1 || choice > 5)
		throw std::invalid_argument("Invalid option");
	if(choice == 5) exit(0);
}

const int Table::getValue() const { return value; }

const int Table::getChoice() const { return choice; }

void Table::tableChoices() const
{
	std::cout << "Please enter from the choices below:\n"
	     << "1] Addition\n"
		 << "2] Subtraction\n"
	   	 << "3] Multiplication\n"
		 << "4] Division\n"
		 << "5] Exit\n"
		 << ">";
}

void Table::printTable() const
{
	for(size_t i{0}; i <= getValue(); ++i) std::cout << std::setw(5) << i;
	std::cout << std::endl;
	
	for(int i{1}; i <= getValue(); ++i){
		std::cout << std::setw(5) << i;
		for(int j{1}; j <= getValue(); ++j){
			switch(getChoice()){
				case 1:
					std::cout << std::setw(5) << i + j;
					break;
					
				case 2:
					std::cout << std::setw(5) << i - j;
					break;
					
				case 3:
					std::cout << std::setw(5) << i * j;
					break;
					
				case 4:
					std::cout << std::setw(5) << i / j; 	
			}
		}
		std::cout << std::endl;
	}
}

void Table::run()
{
	tableChoices();
	setChoice();
	setValue();
	printTable();
}
