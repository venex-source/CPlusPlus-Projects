#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>

static const size_t SIZE{ 9 };

class Sudoku{
	
		enum class Status{ PLAY, CONTINUE, END };
		Status gameStatus{Status::CONTINUE};
		
		short PlayerCard[SIZE][SIZE];
		
		short getRandomNumber(const short = 0, const short = 1);
		const void WelcomeScreen();
		
		short emptySpaces;
		short PlayerFilledSpaces;
	
	public:
		
		explicit Sudoku();
		
		void run();
		void gamePlay();
		void setEmptySpacesInCard();
		void initializeNonEmptySpacesInCard();
		
		void displaySudokuCard();
		void checkAndAssignRandomNumberToCard(const short&, const short&);
		void DisplayGridValues(short&, short&);
		
		short checkPlayerInputRowOrCol(const std::string&);
		short PlayerInput(const std::string&);
		short checkPlayerInputGuessedNumber(const std::string&);
		
		bool isMod3(const short&);
		bool isInRowAndCol(const short&, const short&, const short&);
		bool isInGrid(const short&, const short&, const short&);
		bool isInCard(const short&, const short&, const short&);
		bool isPresentInRowColGrid(const short&, const short&, const short&);
		bool AssignNumberIfValid(const short, const short, const short);
		bool isEmptySpacesFilled() const;
		
		
		
		short getSudokuCardNumber(short, short) const;
		void setSudokuCardNumber(const short, const short, const short);
		
		short getGridBegin(const short&);
		void solveSudoku(const short, const short, const short);
		void PlayersInputData();	
		
};

#endif
