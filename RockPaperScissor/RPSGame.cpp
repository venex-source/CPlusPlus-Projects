#include <string>
#include <ctime>
#include <random>
#include <iomanip>
#include "RPSGame.h"

const std::array<char, RPSPlay::SIZE> RPSPlay::rpsChoices{'r', 'p', 's'};

std::default_random_engine engine(static_cast<unsigned int>(time(0)));

RPSPlay::RPSPlay() { WelcomePage(); }

void RPSPlay::setUserChoice(){
	std::cout << "[r]ock, [p]aper, [s]cissor shoot!!!(enter 0 to exit)   > ";
	std::cin >> userChoice;
}

const char RPSPlay::getUserChoice() const{ return userChoice; }

void RPSPlay::getWinner(const char uc, const char cc) {
	if(uc == 'r'){
		if(cc == 'r') std::cout << "IT'S A DRAW !!!!!!" << std::endl;
		if(cc == 'p') std::cout << "YOU LOSE !!!!!!" << std::endl;
		if(cc == 's') std::cout << "YOU WIN !!!!!!" << std::endl;
	}
	if(uc == 'p'){
		if(cc == 'r') std::cout << "YOU WIN !!!!!!" << std::endl;
		if(cc == 'p') std::cout << "IT'S A DRAW !!!!!!" << std::endl;
		if(cc == 's') std::cout << "YOU LOSE !!!!!!" << std::endl;
	}
	if(uc == 's'){
		if(cc == 'r') std::cout << "YOU LOSE !!!!!!" << std::endl;
		if(cc == 'p') std::cout << "YOU WIN !!!!!!" << std::endl;
		if(cc == 's') std::cout << "IT'S A DRAW !!!!!!" << std::endl;
	}
}

void RPSPlay::play() {
	while(gameStatus == PLAY){
		setUserChoice();
		if(getUserChoice() == '0') gameStatus = EXIT;
		getWinner(getUserChoice(), computerChoice());
	}
}

void RPSPlay::WelcomePage() const{
	std::cout << std::setw(40) << "Rock, Paper, Scissor Game\n"
			<< "\nWelcome to Rock, Paper, Scissor Game!!!!!\n"
			<< "Let's Play." << std::endl;
}

short RPSPlay::getRandomNumber() {
	return std::uniform_int_distribution<short> {1, SIZE}(engine);
}

char RPSPlay::computerChoice() { return rpsChoices[getRandomNumber()]; }
