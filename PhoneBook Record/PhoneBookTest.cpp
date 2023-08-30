#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

#include "PhoneBook.cpp"

using namespace std;

enum class Menu{ ADD = 1, DELETE, MODIFY, SEARCH, DISPLAY, COUNT, END};

Menu menu();
inline void enterNumber(unsigned&);

int main(){
	fstream book("record.dat", ios::in | ios::out | ios::binary);
	
	if(!book){
		cerr << "File could not be opened.\n";
		exit(EXIT_FAILURE);
	}
	
	Record rec;
	Menu select;
	
	while( (select = menu()) != Menu::END){
		unsigned id;
		string fname;
		string lname;
		string city;
		string address;
		
		cout <<endl;
		
		switch(select){
			case Menu::ADD:
				enterNumber(id);
				book.seekg(sizeof(Record) * id);
				book.read(reinterpret_cast<char*>(&rec), sizeof(Record));
				if(!rec.getFirstName().empty())
					cout << "Phone number " << id << " already exists\n";
				else{
					cout << "Enter First Name: "; cin >> fname;
					cout << "Enter Last Name: "; cin >> lname;
					cout << "Enter your city: "; cin >> city;
					cout << "Enter your address: "; cin >> address;
					rec = Record{id, fname, lname, city, address};
					book.seekp(sizeof(Record) * id);
					book.write(reinterpret_cast<char*>(&rec), sizeof(Record));
				}
				break;
				
			case Menu::DELETE:
				
				enterNumber(id);
				book.seekg(sizeof(Record) * id);
				book.read(reinterpret_cast<char*>(&rec), sizeof(Record));
				if(rec.getFirstName().empty())
					cout << "Phone number " << id << " is empty\n";
				else{
					rec = Record{id};
					book.seekp(sizeof(Record) * id);
					book.write(reinterpret_cast<char*>(&rec), sizeof(Record));
					cout << "Phone number " << id << " has been deleted\n";
				}
				break;
				
			case Menu::MODIFY:
				enterNumber(id);
				book.seekg(sizeof(Record) * id);
				book.read(reinterpret_cast<char*>(&rec), sizeof(Record));
				if(rec.getFirstName().empty())
					cout << "Phone Number " << id << " is empty\n";
				else{
					unsigned newID;
					cout << "New Phone Nmber"; enterNumber(newID);
					cout << "New First Name: "; cin >> fname;
					cout << "New Last Name: "; cin >> lname;
					cout << "New City: "; cin >> city;
					cout << "New Address: "; cin >> address;
					book.seekp(sizeof(Record) * id);
					if(newID != id){
						rec = Record{id};
						book.write(reinterpret_cast<char*>(&rec), sizeof(Record));
						cout << "Phone number " << id << " deleted\n";
						book.seekp(sizeof(Record) * newID);	
					}
					rec = Record{newID, fname, lname, city, address};
					book.write(reinterpret_cast<char*>(&rec), sizeof(Record));
					cout << "Phone number " << newID << " updated\n";
				}
				break;
				
			case Menu::DISPLAY:
				cout << "  #  Phone Number     First Name        Last Name          City         Address\n"
					<< "-------------------------------------------------\n";
				book.seekg(0);
				while(book.read( reinterpret_cast<char*>(&rec), sizeof(Record)))
					if(!rec.getFirstName().empty())
						cout << fixed << setprecision(2) 
							<<          setw(3)  << rec.getPhoneNumber() << " " 
							<< left <<  setw(20) << rec.getFirstName() << " " 
							<<  setw(20)         << rec.getLastName() << " " 
							<< right << setw(3)  << rec.getCity() << " " 
							<<          setw(20) << rec.getAddress() << " " << endl;
				break;
		}
	}
}

Menu menu()
{
	cout << "1) Add Phone Number\n"
		 << "2) Delete Phone Number\n"
		 << "3) Modify Phone Number\n"
		 << "4) Search Phone Number\n"
		 << "5) Display All Record\n"
		 << "6) Count Of Phone Number\n"
		 << "7) Exit\n>";
	int choice;
	cin >> choice;
	return static_cast<Menu>(choice);
}

void enterNumber(unsigned& id){
	do{
		cout << "\nEnter a phone number: ";
		cin >> id;
	} while(id < 0 || id > 1000);
}
