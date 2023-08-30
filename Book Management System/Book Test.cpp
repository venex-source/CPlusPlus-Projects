#include <iostream>
#include <string>
#include "Book Store.cpp"

using namespace std;

short HomeMenu()
{
	short choice;
	cout << "***************************\n"
		 << "[LIBRARY MANAGEMENT SYSTEM]\n"
		 << "***************************\n" << endl;
		 
	cout << "\n1). User Login"
		 << "\n2). Admin Login"
		 << "\n3). Exit\n" << endl;
		 
	cout << "Enter an option: ";
	cin >> choice;
	
	return choice;
}

short UserLoginMenu()
{
	short choice;
	cout << "\t\t\t\t\n*************##### WELCOME TO E-LIBRARY #####*************\n"
		 << "1). Book issuing and depositing\n"
		 << "2). Display book information\n"
		 << "3). View All Books\n"
		 << "4). Back\n";
		 
	cout << "Enter an option: ";
	cin >> choice;
	
	return choice;
}

short AdminLoginMenu()
{
	short choice;
	cout << "\t\t\t\t\n*************##### WELCOME TO E-LIBRARY #####*************\n"
		 << "1). Add new book\n"
		 << "2). Update existing book\n"
		 << "3). Delete book\n"
		 << "4). View All Books\n"
		 << "5). List the count of books in the library\n"
		 << "6). Back\n";
		 
	cout << "Enter an option: ";
	cin >> choice;
	
	return choice;
}


int main()
{
	
	short cb{};
	Books book[10];
	
		switch(HomeMenu()){
			while(true){
			case 1:
				{
					switch(UserLoginMenu()){
						case 1:
							break;
							
						case 2:
							{
								cin.ignore();
								string name;
					
								switch(book[cb].displayBookMenu()){
									book[cb].displayTable();
									case 1:{
										cout << "\nEnter the Book name: ";
										getline(cin, name);
										for(int i{}; i < cb; ++i)
											book[i].listByBookName(name);
										break;
										}
							
									case 2:{
										short num;
										cout << "\nEnter the Book serial number: ";
										cin >> num;
										book[num].displayInformation();
										break;
										}
							
									case 3:{
										cout << "\nEnter the Author's name: ";
										getline(cin, name);
										for(int i{}; i < cb; ++i)
											book[i].listByAuthor(name);
										break;
										}
							
									case 4:
										break;
										
									default:
										cout << "\nNumber not in the options" << endl;
									}
									break;
							}
							
							case 3:
								book[cb].displayTable();
								for(int i{}; i < cb; ++i)
									book[i].displayInformation();
								break;
								
							case 4:
								break;
								
							default:
								cout << "The option you pick was wrong\n" << endl;
						}
					break;
				}
				
			case 2:
				{
					switch(AdminLoginMenu()){
						case 1:
							book[cb].addBook();
							++cb;
							break;
							
						case 2:
							short choice;
							cout << "Enter the book serial number you want to update: ";
							cin >> choice;
							book[choice].addBook();
							break;
							
						case 3:
							break;
							
						case 4:
							book[cb].displayTable();
								for(int i{}; i < cb; ++i)
									book[i].displayInformation();
							break;
							
						case 5:
							cout << "Number of books in the library is " << cb << endl;
							
						case 6:
							break;
							
					}
					break;
				}
		}
	}
	return 0;
}
