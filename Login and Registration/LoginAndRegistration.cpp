#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool IsLoggedIn()
{
	string username, password, un, pw;
	
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;
	
	ifstream read("C:\\Users\\Josephine\\Documents\\Others\\C++ Project\\" + username + ".txt");
	getline(read, un);
	getline(read, pw);
	
	return un == username && pw == password;
}

int main(){
	unsigned int choice{0};
	while(true){
		cout << "1] Register\n"
			<< "2] Login\n";	
		cout << "Enter your choice: ";
		cin >> choice;
		switch(choice){
			case 1:{
				string username, password;
				cout << "Enter Username: ";
				cin >> username;
				cout << "Enter Password: ";
				cin >> password;
				
				ofstream MyFile;
				MyFile.open("C:\\Users\\USER\\Documents\\C++ Project\\" + username + ".txt");
				MyFile << username << endl << password;
				MyFile.close();
				break;
			}
			case 2:
				if(!(IsLoggedIn())){
					cout << "False Login" << endl;
					system("PAUSE");
					return 0;
				}
				else{
					cout << "Succesfully logged in!" << endl;
					system("PAUSE");
					return 1;
				}
		}
	}
		
}
