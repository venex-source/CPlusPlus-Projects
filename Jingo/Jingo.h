#include <array>
#include <vector>
#ifndef JINGO_H
#define JINGO_H

static const size_t SIZE{5};
static const size_t LENGTH{50};

class Jingo{
	public:
		
		// default constructor
		Jingo();
		
		// Get and Print current life of player
		short getLives() const;
		void printLivesLeft() const;
		
		// Set and print Jingo Card
		void initializeJingoCard();
		void printJingoCard() const;
		
		// Check if the player have Jingo or have been Jingled then display result
		void checkIfUserJingo();
		void displayWinOrLose() const;
		bool checkForWin();								// Verify if the play has jingo
		
		int displayOptions();			// Display the option for player
		void UserGuess();				// Get the user guess and validate if guess is from [1-50]
		void showListOfGuesses() const;	// Show list of all the guess by the player
		
		bool GuessedNumberOnCard(const int, size_t = SIZE-1, size_t = SIZE-1) const;		// Check if the number on card have been guessed correctly
		bool userGuessOnCard(const int) const;			// Check if the user guess is on the card
		
		void run();										//play game
		
	private:
		void welcomeScreen() const;					// Welcome screen with instructions
		unsigned getRandomNumber() const;			// Get a random number
		
		
		short lives{10};
		short true_count{0};
		enum Status{PLAY, WIN, LOSE};
		Status gameStatus{PLAY};
		std::array<std::array<int, SIZE>, SIZE> card;
		std::vector<int> guesses;
};

#endif
