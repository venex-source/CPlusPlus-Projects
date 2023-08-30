#ifndef SCIENCE_CLASS_H
#define SCIENCE_CLASS_H

#include "Student Record.cpp"

class Science: public StudentRecord{
	public:
		Science(std::string, std::string, short = 0, short = 0, short = 0, short = 0, short = 0);
		virtual ~Science() = default;
		
		void setPhysic(short);
		short getPhysic() const;
		
		void setChemistry(short);
		short getChemistry() const;
		
		virtual short TotalMark() const override;
		virtual std::string toString() const override;
		
	private:
		short physic;
		short chemistry;
		const std::string department{"Science"};
};

#endif
