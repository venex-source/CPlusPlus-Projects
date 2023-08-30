#include <string>
#include <iomanip>
#include <ctime>
#include <random>
#include <array>
#include "TicTacToe.h"

using namespace std;

default_random_engine engine(static_cast<unsigned>(time(0)));

TicTacToe::TicTacToe()
{
	resetBoard();		//set board all board value to 0
	WelcomeScreen();	//display welcome screen
	for(size_t i = 1; i < 3; ++i)
		setPlayersData();
}

void TicTacToe::setPlayersData()
{
	char choice;
	while(true){
		cout << "Please select a path for Player" << activePlayer << "([h]uman or [c]omputer > ";
		cin >> choice;
		if(choice == 'h' || choice == 'c'){
			(isPlayer1Active() ? player1 : player2) = choice;
			break;
		}		
	}
	switchActivePlayer();
}

bool TicTacToe::isPlayer1Active() const
{
	return activePlayer == PLAYER1;
}

void TicTacToe::switchActivePlayer()
{
	activePlayer = (isPlayer1Active() ? PLAYER2 : PLAYER1);
}

const char TicTacToe::getPlayer1() const { return player1; } 

const char TicTacToe::getPlayer2() const { return player2; }

void TicTacToe::drawBoard() const
{
	for(auto& element1: board){
		for(auto& element2: element1)
			cout << element2 << " ";	
		cout << endl;
	}		
}

void TicTacToe::resetBoard()
{
	for(auto& element1: board)
		for(auto& element2: element1)
			element2 = 0;
}

const bool TicTacToe::checkForWin()
{
	// FOR HORIZONTAL
	for(size_t i{}; i<SIZE; ++i){
		for(size_t j{}; j<SIZE; ++j){
			if(isAcvtivePlayerSide(i, j))
				++true_count;
			else{
				true_count = 0;
				break;
			}
		}
		if(isGameOver()) return true;
	}
	
	// FOR 	VERTICAL
	for(size_t i{}; i<SIZE; ++i){
		for(size_t j{}; j<SIZE; ++j){
			if(isAcvtivePlayerSide(j, i))
				++true_count;
			else{
				true_count = 0;
				break;
			}
		}
		if(isGameOver()) return true;
	}
	
	// FOR DIAGONAL ( \ )
	for(size_t i{}; i<SIZE; ++i)
		if(isAcvtivePlayerSide(i, i))
			++true_count;
		else break;
		
	if(isGameOver()) return true;
			
	// FOR DIAGONAL ( / )
	for(int i{}, j{2}; j >= 0; ++i,--j)
		if( isAcvtivePlayerSide(i, j) )
			++true_count;
		else break;
	
	if(isGameOver()) return true;	
		
	return false;
}

void TicTacToe::isGameOver()
{
	if(isGameOver()) return true;
	true_count = 0;
	return false;
}

bool TicTacToe::isActivePlayerSide(int side1, int side2) const
{
	return board[side1][side2] == activePlayer
}

bool TicTacToe::ActiveSideComplete() const
{
	return true_count == SIZE;
}

const bool TicTacToe::checkForDraw() const
{
	for(auto& element1: board)
		for(auto& element2: element1)
			if(element2 == 0)
				return false;
	return true;
}

void TicTacToe::displayResult() const
{
	if(gameStatus == WON)
		cout << "\nPlayer" << activePlayer << " won the game.\n" << endl;
	else
		cout << "\nGame Over. It's a Draw\n" << endl;
}

void TicTacToe::validateUserInput(const int r, const int c)
{
	if((r >= 0 && r < SIZE) && (c >= 0 && c < SIZE)){
		if(board[r][c] == 0){
			board[r][c] = activePlayer;
			if(checkForWin()){
				gameStatus = WON;
				displayResult();
			}
			if(checkForDraw() and gameStatus != WON){
				gameStatus = DRAW;
				displayResult();
			}
			switchActivePlayer(); 
		}
	}
}

void TicTacToe::ActivePlayerTurn(char activeUser, int row, int col)
{
	if(activeUser == 'h')
		cin >> row >> column;
	else{
		row = getRandomNumber(); column = getRandomNumber();
		cout << row << ' ' << column << endl;
	}
	validateUserInput(row, column);
}

void TicTacToe::play()
{
	int row, column;
	cout << "\nPlayer" << activePlayer << ": ";	
	ActivePlayerTurn((isPlayer1Active() ? getPlayer1() : getPlayer2()), row, col);
	drawBoard();
}

void TicTacToe::playAgain()
{
	char* choice = new char;
	
	while(true){
		cout << "\nDo you want to play again.Enter (y/n): ";
		cin >> *choice;
		if(*choice == 'y' or *choice == 'Y' or *choice == 'n' or *choice == 'N') break;
	}
	
	if(*choice == 'Y' or *choice == 'y'){
		delete choice;
		resetBoard();
		gameStatus = PLAY;
		run();
	}
}

void TicTacToe::run()
{
	cout << "\n\nGOOD LUCK!!!!!\n\n";
	drawBoard();
	while(gameStatus == PLAY){
		play();
	}
	playAgain();
}

const void TicTacToe::WelcomeScreen() const
{
	cout << setw(50) << "Welcome to Tic-Tac-Toe Game"
		<< "\n\nThe player that succed in placing three of their marks\n"
		<< "in a horizontal, vertical, or diagonal rowis the winner.\n"
		<< "\nEnter two numbers in format ROW COLUMN(starting index is 0),\n"
		<< "or negative number to terminate the game.\n" << endl;
}

unsigned TicTacToe::getRandomNumber()
{
	return uniform_int_distribution<unsigned>{0, SIZE - 1}(engine);
}
