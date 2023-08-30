#ifndef COMMERCIAL_CLASS_H
#define COMMERCIAL_CLASS_H

#include "Student Record.h"

class Commercial: public StudentRecord{
	public:
		Commercial(std::string, std::string, short = 0, short = 0, short = 0, short = 0, short = 0);
		virtual ~Commercial() = default;
		
		void setMarketing(short);
		short getMarketing() const;
		
		void setCommerce(short);
		short getCommerce() const;
		
		virtual short TotalMark() const override;
		virtual std::string toString() const override;
		
	private:
		short marketing;
		short commerce;
		const std::string department{"Commercial"};
};

#endif
