#ifndef TICTACTOE_H 
#define TICTACTOE_H

#include <array>

static const size_t SIZE{3};

class TicTacToe{
	public:
		//constructor
		TicTacToe();
		
		//setters function for players
		void setPlayersData();
		
		bool isPlayer1Active() const;
		
		void ActivePlayerTurn(char, int, int);
		
		bool isGameOver();
		
		// Switch to the next Player
		void switchActivePlayer();
		
		//get the current player for each player
		const char getPlayer1() const;
		const char getPlayer2() const;
		
		//Draw Board And Reset Board 
		void drawBoard() const;
		void resetBoard();
		
		//Check game for win or draw
		const bool checkForWin();
		const bool checkForDraw() const;
		
		bool ActiveSideComplete() const;
		bool isActivePlayerSide(int, int) const;
		
		//Display Winner or Draw
		void displayResult() const; 
		
		//check user inputs
		void validateUserInput(const int, const int);
		
		//play the game
		void play();
		void playAgain();
		void run();
		
	private:
		//Homescreen
		const void WelcomeScreen() const;
		
		//get random number
		unsigned getRandomNumber();
		
		char player1{'h'};
		char player2{'h'};
		
		short true_count{};
		
		enum Players{PLAYER1 = 1, PLAYER2};
		Players activePlayer{PLAYER1};
		
		enum Status{PLAY, WON, DRAW};
		Status gameStatus{PLAY};
		
		std::array<std::array<int, SIZE>, SIZE> board;
		
};

#endif
