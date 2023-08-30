#ifndef ART_CLASS_H
#define ART_CLASS_H

#include "Student Record.h"

class Art: public StudentRecord{
	public:
		Art(std::string, std::string, short = 0, short = 0, short = 0, short = 0, short = 0);
		virtual ~Art() = default;
		
		void setLiterature(short);
		short getLiterature() const;
		
		void setVisualArt(short);
		short getVisualArt() const;
		
		virtual short TotalMark() const override;
		virtual std::string toString() const override;
		
	private:
		short literature;
		short visualArt;
		const std::string department{"Art"};
};

#endif
