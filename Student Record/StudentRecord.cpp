#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

static size_t LASTSTUDENT{0};

struct StudentDetail{
	int roll;
	string firstname;
	string surname;
	string cellno;
	string DOB;
	string address;
};

short MenuPage();
void showRecord();
void studentInfo(int, StudentDetail []);
void addStudent(int, StudentDetail []);
void editStudent(StudentDetail []);
bool isStudent(int, StudentDetail []);
void searchStudent(StudentDetail []);
void listAllStudent(StudentDetail []);
int main(){
	system("color B1");
	StudentDetail student[10];
	while(true){
		switch(MenuPage()){
			case 1:
				addStudent(LASTSTUDENT, student);
				break;
				
			case 2:
				editStudent(student);
				break;
				
			case 3:
				searchStudent(student);
				break;
			
			case 4:
				listAllStudent(student);
				break;
			case 5:
				exit(0);			
		}
	}
	return 0;
}

short MenuPage(){
	short choice;
	cout << "\n\t\t\t\tWhat to you want to do?\n"
		 << "\t\t\t\t-----------------------\n"
		 << "\t\t\t\t1-Add Student\n"
		 << "\t\t\t\t2-Edit Student\n"
		 << "\t\t\t\t3-Search Student\n"
		 << "\t\t\t\t4-List All Student\n"
		 << "\t\t\t\t5-Quit\n"
		 << "\t\t\t\t-----------------------\n"
	<< "Enter your choice: ";
	cin >> choice;
	return choice;
}

void showRecord(){
	cout << "--------------------------------------------------------------------------------------------------------\n";
	cout << left << setw(16) << "ID" << setw(16) << "Roll" << setw(16) << "Name" << setw(16) <<
		  	"Surname" << setw(16) << "Cell no." << setw(16) << "DOB" <<
		   	setw(16) << "Address" << endl;
	cout << "--------------------------------------------------------------------------------------------------------\n";
}

void studentInfo(int id, StudentDetail student[]){
	cout << endl << setw(16) << id << setw(16) << student[id].roll << setw(16) << student[id].firstname << setw(16) <<
		  	student[id].surname << setw(16) << student[id].cellno << setw(16) << student[id].DOB <<
		   	setw(16) << student[id].address << endl;
}

void addStudent(int id, StudentDetail student[]){
	cout << "Input student rollnumber in format (1XXX): ";
	cin >> student[id].roll;
	
	cout << "Input student first name: ";
	cin >> student[id].firstname;
	
	cout << "Input student surname: ";
	cin >> student[id].surname;
	
	cout << "Input student cell phone number: ";
	cin >> student[id].cellno;
	
	cout << "Input student Date Of Birth (dd/mm/yyyy): ";
	cin >> student[id].DOB;
	
	cout << "Input student Home Address: ";
	cin >> student[id].address;
	
	showRecord();
	studentInfo(id, student);
	++LASTSTUDENT;
}

void editStudent(StudentDetail student[]){
	short id;
	cout << "What ID number do you want to edit: ";
	cin >> id;
	isStudent(id, student) ? addStudent(id, student) : throw ("Id record was not found\n");
}

void searchStudent(StudentDetail student[]){
	short id;
	cout << "Please enter the student id number: ";
	cin >> id;
	if(isStudent(id, student)){
		showRecord();
		studentInfo(id, student);
	}
	else cout << "Student doesn't exisit / cannot be found in database" << endl;
}

void listAllStudent(StudentDetail student[]){
	cout << "--------------------------------------------------------------------------------------------------------\n"
		 << "------------------------------------------Student Record Table------------------------------------------\n";
	showRecord();
	for(int i{0}; i<LASTSTUDENT; ++i)
		studentInfo(i, student);
}

bool isStudent(int id, StudentDetail student[]){
	return !student[id].firstname.empty();
}


