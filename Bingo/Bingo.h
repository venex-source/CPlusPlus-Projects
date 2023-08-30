#ifndef BINGO_H
#define BNGO_H

#include <string>
#include <array>

static const size_t PLAYERLENGTH{2};		
static const size_t SIZE{5};
static const size_t NUMLEN{25};

class Bingo{
	public:
		
		Bingo();		// Constructor
		
		void setPlayers();		// data member function to set players path
		
		void initializePlayerCard(std::array<std::array<int, SIZE>, SIZE>& );		// Set values for a player(s) card
		void displayCard(const std::array<std::array<int, SIZE>, SIZE>&) const;		// Display the player(s) Card
		
		void checkValueInCard(std::array<std::array<int, SIZE>, SIZE>&, int);		// Check if the player(s) number is active in the card
		bool isNotADuplicate(std::array<std::array<int, SIZE>, SIZE>&, int, size_t, size_t);			// Check if the number assigned to card is not a duplicate number in player(s) card
		bool checkForWin(const std::array<std::array<int, SIZE>, SIZE>&);			// Check if player(s) won or drew the game
		
		void displayWinOrDraw();				// Display result for the player(s) that won the game 
				
		void play();					// Play/Run the game
		
	private:
		
		void WelcomeScreen() const;			// Home Screen
		unsigned getRandomNumber();			// data member function to return a random number from [1-25]
		
		std::array<std::array<int, SIZE>, SIZE> Player1Card; 
		std::array<std::array<int, SIZE>, SIZE> Player2Card; 
		
		int true_count{};
		char PLAYERS[PLAYERLENGTH];
		
		enum Player{PLAYER1, PLAYER2};
		Player activePlayer{PLAYER1};
		
		enum Status{CONTINUE, WIN, DRAW, EXIT};
		Status gameStatus = CONTINUE;
};

#endif
