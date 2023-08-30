#ifndef STUDENT_RECORD_H
#define STUDENT_RECORD_H

class StudentRecord{
	public:
		StudentRecord(std::string, std::string, short = 0, short = 0, short = 0);
		virtual ~StudentRecord() = default;
		
		void setName(std::string&);
		std::string getName() const;
		
		void setCollege(std::string&);
		std::string getCollege() const;
		
		void setAttendance(short);
		short getAttendance() const;
		
		void setMath(short);
		short getMath() const;
		
		void setEnglish(short);
		short getEnglish() const;
		
		virtual short TotalMark() const;
		virtual double TotalMarkToPercentage() const;
		virtual char TotalMarkInGrade() const;
		virtual std::string toString() const;
		
	private:
		std::string name;
		std::string college;
		short attendance;
		short math;
		short english;
};

#endif
