#include <iostream>
#include <iomanip>

#include "ChessGame.h"

using namespace std;

ChessGame::ChessGame()
{
	WelcomeMessage();
	DisplayChessBoard();
	runGame();
}

void Chess

void ChessGame::DisplayChessBoard() const
{
	for(auto& row: board){
		for(auto& col: row)
			cout << col << ' ';
		cout << endl;
	}
}

short ChessGame::PromptMessage(const string& message)
{
	short value;
	do{
		cout << message;
		cin >> value;
	} while(value > SIZE - 1);
	return value;
}

void ChessGame::CheckSelectedPiece(const string& piece)
{
	switch
}

const void ChessGame::WelcomeMessage()
{
	cout << setw(80) << "Welcome to chess Game Developed by Jefferson\n\n" << endl;
	cout << setw(30) << "Keys to symbols used\n\n" << endl;
	
	cout << "Blank space = **\n"
		<< "WP = White Pawn & BP = Black Pawn\n"
		<< "WN = White Knight & BN = Black Knight\n"
		<< "WB = White Bishop & BB = Black Bishop\n"
		<< "WR = White Rook & BR = Black Rook\n"
		<< "WQ = White Queen & BQ = Black Queen\n"
		<< "WK = White King & BK = Black King\n"
		<< "Rule for moving is: "
		<< "Move by seleting the piece row & column to another valid location using row & column\n\n" << endl;
}

void ChessGame::runGame()
{
	switch(activePlayer)
	{
		case Players::WHITE:
			{
				cout << "\n\nWhite Turn" << endl;
				short from_row = PromptMessage(PIECE_ROW_MESSAGE);
				short from_col = PromptMessage(PIECE_COL_MESSAGE);
				short to_row = PromptMessage(MOVE_ROW_MESSAGE);
				short to_col = PromptMessage(MOVE_COL_MESSAGE);
				break;
			}

		case Players::BLACK:
			{
				cout << "\n\nActive player is black" << endl;
				break;	
			}

		default:
			cout << "There is no active player" << endl;
	}
}
