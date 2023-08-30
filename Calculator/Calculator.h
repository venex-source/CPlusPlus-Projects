#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calc{
	public:
		void setFirstNumber();
		void setSecondNumber();
		void setChoice();
		
		double getFirstNumber() const;
		double getSecondNumber() const;
		int getChoice() const;
		
		void run();
		
		void calculate() const;

	private:
		double firstNumber{0};
		double secondNumber{0};
		int choice{1};	
};

#endif
