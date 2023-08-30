#include <random>
#include <ctime>

#include "Sudoku.h"

using namespace std;

default_random_engine engine(static_cast<short>(time(0)));

Sudoku::Sudoku()
{
	run();
}

const void Sudoku::WelcomeScreen()
{
	cout << "\t\t============================\n"
		 << "\t\t     Sudoku Game Program!\n"
		 << "\t\t============================\n\n";
		 
	cout << "Welcome to my Sudoku game program, where the player has to fill in the blank spaces indicated with the character (0)\n"
		 << "with the right number, which is not repeated in the row, column and grid, in other to win the game. Player can play thier\n"
		 << "guess by inputing the row,column and your guess.\n"
		 << "\nExample:"
		 << "\nPlease input the row to include your number: 1"
		 << "\nPlease input the column to include your number: 3"
		 << "\nPlease enter your guesse number from (1-9): 6\n\nLET'S GOOOOO!!!\n\n";

}

void Sudoku::setEmptySpacesInCard()
{
	for(auto& row: PlayerCard)
		for(auto& col: row)
			if(!(col = getRandomNumber())) ++emptySpaces;
}

void Sudoku::initializeNonEmptySpacesInCard()
{
	for(short row{}; row < SIZE; ++row)
		for(short col{}; col < SIZE; ++col)
			if(getSudokuCardNumber(row, col)) checkAndAssignRandomNumberToCard(row, col);
}

short Sudoku::PlayerInput(const std::string& prompt)
{
	short userInput;
	cout << prompt;
	cin >> userInput;
	return userInput;
}

short Sudoku::checkPlayerInputRowOrCol(const std::string& prompt)
{
	short PlayerChoice; 
	while(true){
		PlayerChoice = PlayerInput(prompt);
		if(PlayerChoice >= 0 && PlayerChoice < SIZE) return PlayerChoice;
	}		
}


short Sudoku::checkPlayerInputGuessedNumber(const std::string& prompt)
{
	short PlayerChoice;
	while(true){
		PlayerChoice = PlayerInput(prompt);
		if(PlayerChoice > 0 && PlayerChoice <= SIZE) return PlayerChoice;	
	} 
}

void Sudoku::checkAndAssignRandomNumberToCard(const short& row, const short& col)
{
	while(true)
		if(AssignNumberIfValid(row, col, getRandomNumber(0, 9)))
			break;
}

bool Sudoku::AssignNumberIfValid(const short currentRow, const short currentColumn, const short numberToValidate)
{
	if(isPresentInRowColGrid(currentRow, currentColumn, numberToValidate)){
		setSudokuCardNumber(currentRow, currentColumn, numberToValidate);
		return true;
	}
	else return false;
}

void Sudoku::displaySudokuCard()
{
	for(short row{}; row < SIZE; ++row){
		for(short col{}; col < SIZE; ++col) DisplayGridValues(row, col);
		isMod3(row) ? cout << "\n\n" : cout << endl;		
	}
}

void Sudoku::DisplayGridValues(short& currRow, short& currCol)
{
	cout << getSudokuCardNumber(currRow, currCol);
	cout << (isMod3(currCol)  ? '\t' : ' ');
}

short Sudoku::getSudokuCardNumber(short row, short col) const
{
	return PlayerCard[row][col];
}

void Sudoku::setSudokuCardNumber(const short row, const short col, const short value)
{
	PlayerCard[row][col] = value;
}

bool Sudoku::isMod3(const short& line)
{
	return ( line + 1 ) % 3 == 0;	
}

short Sudoku::getRandomNumber(const short MIN, const short MAX)
{
	return uniform_int_distribution<short>{MIN, MAX}(engine);
}

bool Sudoku::isInRowAndCol(const short& currRow, const short& currCol, const short& numberToValidate)
{
	for(short i{}; i < SIZE; ++i)
		if(isInCard(currRow, i, numberToValidate) || isInCard(i, currCol, numberToValidate))
			return true;
	return false;
}

bool Sudoku::isInGrid(const short& currRow, const short& currCol, const short& number)
{
	for(int beginRow{getGridBegin(currRow)}, endRow{beginRow + 2}; beginRow <= endRow; ++beginRow){
		for(int beginCol{getGridBegin(currCol)}, endCol{beginCol + 2}; beginCol <= endCol; ++beginCol){
			if(isInCard(beginRow, beginCol, number)) return true;
		}	
	}
	return false;
}

bool Sudoku::isInCard(const short& row, const short& col, const short& numberToValidate)
{
	return getSudokuCardNumber(row, col) == numberToValidate;
}

bool Sudoku::isPresentInRowColGrid(const short& row, const short& col, const short& number)
{
	return !isInRowAndCol(row, col, number) && !isInGrid(row, col, number);
}

short Sudoku::getGridBegin(const short& value)
{
	return value - (value % 3);
}

void Sudoku::solveSudoku(const short playerRow, const short playerCol, const short guessedNumber)
{
	if(!getSudokuCardNumber(playerRow, playerCol)){
		if(AssignNumberIfValid(playerRow, playerCol, guessedNumber)) ++PlayerFilledSpaces;
		else cout << "\nOppss! Wrong guess. Please try again!\n"; 
	}
	else cout << "\nSorry! You can't change these number\n";
}

void Sudoku::PlayersInputData()
{
	short* PlayerRow = new short(checkPlayerInputRowOrCol("Please input the row to include your number from [0 - 8]: "));
	short* PlayerCol = new short(checkPlayerInputRowOrCol("Please input the column to include your number from [0 - 8]: "));
	short* PlayerGuessedNumber = new short(checkPlayerInputGuessedNumber("Please enter your guesse number from (1-9): "));
	
	solveSudoku(*PlayerRow, *PlayerCol, *PlayerGuessedNumber);
	
	delete PlayerRow;
	delete PlayerCol;
	delete PlayerGuessedNumber;
}

void Sudoku::gamePlay()
{
	while(gameStatus == Status::CONTINUE){
		displaySudokuCard();
		PlayersInputData();
		if(PlayerFilledSpaces == emptySpaces){
			cout << "You Won The Game.";
			gameStatus = Status::END;
		}
	}
}

void Sudoku::run()
{
	WelcomeScreen();
	setEmptySpacesInCard();
	initializeNonEmptySpacesInCard();
	gamePlay();
}
