#ifndef RPSGAME_H
#define RPSGAME_H

#include <array>

class RPSPlay{
	
	public:
		static const size_t SIZE{3};
		RPSPlay();
		
		void setUserChoice();
		const char getUserChoice() const;
		
		void getWinner(const char, const char);
		
		void play();		
		
	private:
		
		void WelcomePage() const;
		short getRandomNumber();
		
		char computerChoice();
		char userChoice;
		
		enum Status{PLAY, EXIT};
		Status gameStatus = PLAY;
		
		static const std::array<char, SIZE> rpsChoices;
};

#endif
