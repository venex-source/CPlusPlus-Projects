#ifndef MATHTABLE_H
#define MATHTABLE_H

class Table{
	public:
		void setValue();
		void setChoice();
		
		const int getValue() const;
		const int getChoice() const;
		
		void printTable() const;
		void run();	
	
	private:
	
		void tableChoices() const;
		
		int value{0};
		int choice{1};
};

#endif
