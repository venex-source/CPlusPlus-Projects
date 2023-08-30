#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

const int LENGTH{10};
const int SIZE{2};

default_random_engine engine(static_cast<int>(time(0)));

int getRandomNumber();
bool isGuessed(char, const vector<char>&);

int main(){
	
	ifstream inWordText{"words.txt", ios::in};
	
	if(!inWordText){
		cerr << "Invalid error. File not found." << endl;
		exit(EXI_FAILURE);
	}
	
	enum class Status{PLAY, CONTINUE, END};
	
	Status gameStatus{Status::CONTINUE};
	
	vector<char> guesses;
	char choice;
	int num;
	int letterGuessed{};
	
	string ScrabbleChoice[LENGTH][SIZE]{
		
		{ "thanos",     "Name of a villian in the MCU Universe"},
		{ "jefferson",  "The name of the greatest Pes Player in history"},
		{ "spongebob",  "A yellow character from bikini bottom"},
		{ "biology",    "A subject taught in school that teaches about living things"},
		{ "javascript", "A popular programming language commonly used to create web"},
		{ "keyboard",   "Used to write characters or keys to a screen"},
		{ "cout",       "A C++ keyword used to display content on the screen"},
		{ "church",     "A place where christian go to whorship"},
		{ "drake",      "Sang the popular hit song \" God\'s plan \""},
		{ "griffins",   "Name of a cartoon character in family guys"}
		
	};
	
	cout << "=====================================\n"
		 << "    Welcome to Word Scrabble Game\n"
		 << "=====================================\n\n"; 
	
	while(gameStatus == Status::CONTINUE){
		num = getRandomNumber();
		string word = ScrabbleChoice[num][0];
		for(auto& elem: word) cout << "_ ";
		cout << "\n\nHint: " << ScrabbleChoice[num][1] << endl;
		
		gameStatus = Status::PLAY;
		
		while(gameStatus == Status::PLAY){
			cout << "\n==========================================\n";
			cout << "\nEnter a character: "; cin >> choice;
			
			if(isGuessed(choice, guesses)) cout << "\nThe letter " << choice << " has already been guessed" << endl;
			else{
				for(auto& elem: word)	
					if(elem == choice)
						guesses.push_back(choice);
			}
			
			for(auto& elem: word){
				if(isGuessed(elem, guesses)){
					cout << elem << ' ';
					++letterGuessed;
				} 
				else cout << "_ ";
			}
			cout << "\n\nHint: " << ScrabbleChoice[num][1] << endl << endl;
			if(letterGuessed == word.length()) gameStatus = Status::END;
			else letterGuessed = 0;
		}
		
		cout << "\nDo you still want to play(y/n): ";
		cin >> choice;
		if(choice == 'y' || choice == 'Y'){
			gameStatus = Status::CONTINUE;
			letterGuessed = 0;
			guesses = {};
			cin.clear();
		} 	
	}	
	
	return 0;
}

int getRandomNumber(){
	return uniform_int_distribution<int> {0, 9}(engine);
}

bool isGuessed(char value, const vector<char>& arr) {
	for(auto item: arr)
		if(item == value)
			return true;
	return false;
}
