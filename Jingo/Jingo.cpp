#include <string>
#include <random>
#include <ctime>
#include <iomanip>
#include "Jingo.h"

using namespace std;

default_random_engine engine(static_cast<unsigned>(time(0)));

Jingo::Jingo()
{
	initializeJingoCard();
	welcomeScreen();
}

short Jingo::getLives() const{ return lives; }				// Get live

void Jingo::printLivesLeft() const
{
	cout << "You have " << getLives() << " left" << endl;			// Display player live left
}

void Jingo::initializeJingoCard()
{
	int number;
	for(size_t i{}; i < SIZE; ++i){					// Loop through the card and set a random number for each one
		for(size_t j{}; j < SIZE; ++j){		
			do{
				number = getRandomNumber();
			} while(GuessedNumberOnCard(number, i, j));
			card[i][j] = number;
		}
	}
}

void Jingo::printJingoCard() const
{
	cout << left << "+-----------------------------+\n"
				 << "|JINGO|JINGO|JINGO|JINGO|JINGO|\n"				// Display the board for the game
				 << "+-----------------------------+\n";
	for(auto& element1: card){
		for(auto& element2: element1){
			cout << setw(3) << '|' << setw(3);  (!userGuessOnCard(element2) ? cout << element2 : cout << 'X');			// loop through the card array and check if 
		}																												// the current number have be guessed in tje guesses vector
		cout << setw(2) << '|' << endl;	
	}
	cout << "+-----------------------------+\n";
}

void Jingo::checkIfUserJingo()
{
	if(!getLives())	gameStatus = LOSE;				// Set game to lost if player live reaches 0
	if(checkForWin())	gameStatus = WIN;			// Set Game to Won if play win
	displayWinOrLose();								// Display the result for either game won or lost
}

void Jingo::displayWinOrLose() const
{
	if(gameStatus == WIN) cout << "JINGO!!!!!\nCongratulation, You won the game.";				// Display Player won the game
	if(gameStatus == LOSE) cout << "NOOOOOOO!!!!!\nSorry, You Lost the game.";					// Dislplay player lost the game
}

int Jingo::displayOptions()
{
	short choice;
	cout << "\n1). Enter next guess"
		<< "\n2). List of Guesses"							// Prompt user for an option an validate if option is in the range from [1-3] then return result
		<< "\n3). Exit" 
		<< "\n> ";
	cin >> choice;
	if(choice > 0 and choice < 4)
		return choice;
}

void Jingo::UserGuess()
{
	int guess;
	while(true){
		cout << "Please enter your guess: ";
		cin >> guess;												//Prompt user to guess a number and verify if number is in the range of [1-50]
		if(guess > 0 && guess <= LENGTH){
			guesses.push_back(guess);								// Push user guess to a the guess vector
			if(!GuessedNumberOnCard(guess))							// Minus a live if user guess a wrong number
				--lives;
			break;
		}
	}
}

void Jingo::showListOfGuesses() const
{
	if(guesses.empty())									// Check if the guess result is empty
		cout << "\nYou haven't guessed yet." << endl;
	else{
			for(auto& element1: guesses)				// If not loop through the guess vector and display the numbers
				cout << element1 << ' ';
			cout << endl;
	}
}

void Jingo::run()
{
	while(gameStatus == PLAY){					// Run game while still if game is still playing
		printJingoCard();		// Print card
		printLivesLeft();		// Display Live
		switch(displayOptions()){		// Get user option choice and direct to the path
			case 1:
				UserGuess();			// Get user guess
				break;
			case 2:
				showListOfGuesses();		// Show list of user guesses
				break;
			case 3:
				exit(0);					// Exit the game
		}
		checkIfUserJingo();					// Check if game have been won or lost
	}
}

bool Jingo::GuessedNumberOnCard(const int num, size_t row, size_t col) const
{
	for(size_t i{}; i <= row;  ++i)
		for(size_t j{}; j <= col; ++j)		// loop through the card array and check if the guessed 
			if(card[i][j] == num)				// number is on the card then return true or else return false
				return true;
	return false;
}

bool Jingo::userGuessOnCard(const int num) const
{
	for(auto& element1: guesses)
		if(element1 == num)					// loop through the guesses vector and return true
			return true;					// if the guess is on the card else return false
	return false;
}

bool Jingo::checkForWin()
{
	// For Horizontal
	for(size_t i{0}; i < SIZE; ++i){
		for(size_t j{0}; j < SIZE; ++j){				// a loop to check if the user have guessed all the numbers in a row horizontally
			if(userGuessOnCard(card[i][j]))
				++true_count;							// then increament true_count by 1
			else{
				true_count = 0;							// else set true count to 0 and leave inner loop
				break;
			}
		}
		if(true_count == SIZE)					// if true_count is == 5 the user have jingo
			return true;						// return true and set true_count to 0
		true_count = 0;
	}
	
	// For Vertical
	for(size_t i{0}; i < SIZE; ++i){
		for(size_t j{0}; j < SIZE; ++j){				// a loop to check if the user have guessed all the numbers in a column vertically 
			if(userGuessOnCard(card[j][i]))
				++true_count;							// then increament true_count by 1
			else{
				true_count = 0;							// else set true count to 0 and leave inner loop
				break;				
			}
		}
		if(true_count == SIZE)					// if true_count is == 5 the user have jingo
			return true;						// return true and set true_count to 0
		true_count = 0;
	}
	
	// For Diagonal
	if((userGuessOnCard(card[0][4]) && userGuessOnCard(card[1][3]) && userGuessOnCard(card[2][2]) && userGuessOnCard(card[3][1]) && userGuessOnCard(card[4][0]))
		|| (userGuessOnCard(card[0][0]) && userGuessOnCard(card[1][1]) && userGuessOnCard(card[2][2]) && userGuessOnCard(card[3][3]) && userGuessOnCard(card[4][4])))
		return true;		// check if user have jingo diagonally then return true
	return false;			// if horizontal or vertical or diagonal is not true then return false; 
}



void Jingo::welcomeScreen() const
{
	cout << "\t\t\t+--------------------------------------+"
	   << "\n\t\t\t|Welcome to Jefferson Famous JINGO GAME|"					// Home page with instructions on how to play the game for users
	   << "\n\t\t\t+--------------------------------------+"
	   << "\n\nWelcome to my Jingo game, the following are the rules to play the game below:"
	   << "\n\t1.) Player have a maximum of 10 lives, with every guess is a loss of live\n\t    if player live reaches 0, the player loses the game."
	   << "\n\t2.) A card is been displayed to the player with every box stared(\"X\")\n\t    , Every correct guess the marked X is change to the guessed number."
	   << "\n\t3.) A list of option is been displayed to the player where: "
	   << "\n\t\t. player can either enter a guess from 1 to 50"
	   << "\n\t\t. player can get a list of all his/her guesses made"
	   << "\n\t\t. player can exit the game if he chooses."
	   << "\n\nFor the player to succeed in win the game he must guess the marked number in a row either"
	   << "\ndiagonally, vertically or horizonally to JINGO!!!!!!.\n\nOk now that you know the rules.\n   GOOD LUCK AND JINGO!!!!! " << endl;	 		 
}

unsigned Jingo::getRandomNumber() const
{
	return uniform_int_distribution<unsigned> {1, LENGTH}(engine);					// return a random number from 1 to 50
}
