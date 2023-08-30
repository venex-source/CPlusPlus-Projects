#include <string>
#include <iomanip>
#include <random>
#include <ctime>
#include "Bingo.h"

using namespace std;

default_random_engine engine(static_cast<unsigned>(time(0)));

Bingo::Bingo()
{
	WelcomeScreen();		
	setPlayers();
	initializePlayerCard(Player1Card);			// setting player1 card by passing the player1 card as a reference argument
	initializePlayerCard(Player2Card);			// setting player2 card by passing the player2 card as a reference argument
}

void Bingo::setPlayers()
{	
	for(size_t i{}; i<PLAYERLENGTH; ++i) do{				// for loop with do while to set both player1 and player2
		cout << "Player" << i + 1 << "([h]uman or[c]omputer): ";		// Prompt current player for choice
		cin >> PLAYERS[i];
	} while(PLAYERS[i] != 'h' && PLAYERS[i] != 'c');		 // loop while player does not choose [h]uman or [c]omputer
}

void Bingo::initializePlayerCard(array<array<int, SIZE>, SIZE>& card)
{
	int number;
	for(size_t i{}; i < SIZE; ++i){				// looping through the player card 
		for(size_t j{ }; j < SIZE; ++j){
			do{
				number = getRandomNumber();
			} while(isNotADuplicate(card, number, i, j));
			card[i][j] = number;		
		}
	}
}


void Bingo::displayCard(const array<array<int, SIZE>, SIZE>& card) const
{
	cout << "\n\tPlayer" << activePlayer+1 << " turn" <<  endl;		// Displaying the current player card
	cout << left << "+-----------------------------+\n"
				 << "|BINGO|BINGO|BINGO|BINGO|BINGO|\n"
				 << "+-----------------------------+\n";
	for(auto& element1: card){
		for(auto& element2: element1){
			cout << setw(3) << '|' << setw(3);  (element2 ? cout << element2 : cout << 'X');
		}
		cout << setw(2) << '|' << endl;	
	}
	cout << "+-----------------------------+\n";
}

void Bingo::play()
{
	while(gameStatus == CONTINUE){				// Play game as long as the game is set to CONTINUE
		int value;
		if(PLAYERS[activePlayer] == 'h'){			// return true if the active player is a human 
			displayCard(((activePlayer) ? Player2Card : Player1Card));			// display the active player card using a ternary operator
			cout << "\nPlease enter a number from [1-25] or enter -1 to exit\n> ";
			cin >> value;			// Prompt player for his value
		}
		else{					// else active player is a computer
			value = {static_cast<int>(getRandomNumber())};		// get a random value for the computer
			cout << "\nPlayer" << activePlayer+1 << " choose the number " << value << endl; 		// display the computer number to the human player
		}
		if(value == -1) gameStatus = EXIT;		// if active human player enters -1 game quit
		if(value > 0 and value <= NUMLEN){			// validate if the player number is in the range [1-25]
			checkValueInCard(Player1Card, value);			//check if the value is in player2 card
			checkValueInCard(Player2Card, value);			//check if the value is in player2 card
			
			bool result1{checkForWin(Player1Card)};			// Declare and initialize true if player1 win the game else initialize false
			bool result2{checkForWin(Player2Card)}; 		// Declare and initialize true if player2 win the game else initialize false
					
			if(result1 or result2){						// return true if one of the player won the game
				gameStatus = (result1 and result2) ? DRAW : WIN;		// initialize gameStatus to draw if both player won the game else initialize gameStatus to win
				displayWinOrDraw();				// display the winner or draw
			}	
			
			activePlayer = ((activePlayer) ? PLAYER1 : PLAYER2);		// Change active player using ternary operator
		}		
	}
}

void Bingo::displayWinOrDraw()
{
	if(gameStatus == WIN){		//return true if gameStatus was set to win
		cout << "\nBINGOOOOOO!!!!!. Congratulation, on win the game Player" << activePlayer+1 << endl;
		cout << "Here is the winning Bingo Card \n" << endl;
		displayCard(((activePlayer) ? Player2Card : Player1Card));				// Display winner 
	}	
	else{				// else display draw if gameStatus was set to draw
		cout << "\nBINGOOOOOO!!!!!. Wait, what damn it's a draw" << endl;
		cout << "Here are the Cards" << endl;		// Display draw 
		
		activePlayer = PLAYER1;
		displayCard(Player1Card);
		
		cout << endl;
		
		activePlayer = PLAYER2;
		displayCard(Player2Card);
	}
}

void Bingo::checkValueInCard(array<array<int, SIZE>, SIZE>& card, int num)
{
	for(auto& element1: card)
		for(auto& element2: element1)			// Check if the player value is in the card the set the number to 0
			if(element2 == num)
				element2 = 0;
}

bool Bingo::isNotADuplicate(array<array<int, SIZE>, SIZE>& card, int num, size_t row, size_t col)
{
	for(size_t i{row}; i >= 0; --i)
		for(size_t j{col}; j >= 0; --j)			// Check if the value being assigned to the card already exist
			if(card[i][j] == num)
				return false;					//return false if number exist
	return true;								//else return true
}

bool Bingo::checkForWin(const std::array<std::array<int, SIZE>, SIZE>& card)
{
	// For Horizontal
	for(size_t i{0}; i < SIZE; ++i){
		for(size_t j{0}; j < SIZE; ++j){				// a loop to check if the user have guessed all the numbers in a row horizontally
			if(!card[i][j])
				++true_count;							// then increament true_count by 1
			else{
				true_count = 0;							// else set true count to 0 and leave inner loop
				break;
			}
		}
		if(true_count == SIZE){					// if true_count is == 5 the user have bingo
			cout << "\nUser Bingo Horizontally" << endl;
			return true;						// return true and set true_count to 0
		}
		true_count = 0;	
	}		
	
	// For Vertical
	for(size_t i{0}; i < SIZE; ++i){
		for(size_t j{0}; j < SIZE; ++j){				// a loop to check if the user have guessed all the numbers in a row horizontally
			if(!card[j][i])
				++true_count;							// then increament true_count by 1
			else{
				true_count = 0;							// else set true count to 0 and leave inner loop
				break;
			}
		}
		if(true_count == SIZE){					// if true_count is == 5 the user have bingo
			cout << "\nUser Bingo Vertically" << endl;
			return true;						// return true and set true_count to 0
		}
		true_count = 0;	
	}
	
	// For Diagonal
	if((!card[0][4] and !card[1][3] and !card[2][2] and !card[3][1] and !card[4][0])
		|| (!card[0][0] and !card[1][1] and !card[2][2] and !card[3][3] and !card[4][4])){
		cout << "\nUser Bingo Diagonally" << endl;
		return true;			// check if user have bingo diagonally then return true
		}
	return false;				// if horizontal or vertical or diagonal is not true then return false;  
}

void Bingo::WelcomeScreen() const
{
	cout << setw(50) << "============================\n"
		 << setw(50) << "  Welcome to my Bingo Game\n"
		 << setw(50) << "============================\n"													// Home screen / welcome page
		 << "\nWelcome to console application Bingo game built with C++, to play"
		 << "\nuser have to pick a number from his/her card then wait for the call"
		 << "\nof his/her opponent, the player who succeds in placing five of their"
		 << "\nmarks in a horizontal, vertical or diagonal, succeds and wins the game.\n" << endl;
}

unsigned Bingo::getRandomNumber()
{
	return uniform_int_distribution<unsigned> {1, NUMLEN}(engine);			// data member function to return a non-negative number in the range [1-25]
}
