#include <iomanip>
#include "Book Store.h"

using namespace std;

void Books::setBookName()
{
	cin.ignore();
	do{
		cout << "Enter the books name: ";
		getline(cin, book_name);
	} while(book_name.length() <= 1);
}

void Books::setAuthorName()
{
	do{
		cout << "Enter the authors name: ";
		getline(cin, author_name);
	} while(author_name.length() <= 1);
}

void Books::setPages()
{
	do{
		cout << "Enter the number of pages: ";
		cin >> pages;
	} while(pages < 1);
}

void Books::setPrice()
{
	do{
		cout << "Enter the books price: ";
		cin >> price;
	} while(price < 0);
}
		
string Books::getBookName() const { return book_name; }

string Books::getAuthorName() const { return author_name; }

short Books::getPages() const { return pages; }

unsigned Books::getPrice() const { return price; }

void Books::displayInformation() const
{
	cout << setw(19) << getBookName() << setw(19) << getAuthorName() << setw(19)  << getPages() << setw(15);
		 if(getPrice()) cout << getPrice() << endl;
		 else cout << "FREE" << endl;
}

void Books::displayTable() const
{
	cout << "\n============================================================================\n\n"
		 << setw(19) << "Book Name" << setw(19) << "Author's Name" << setw(19) << "Pages" << setw(15) << "Price"
		 << "\n============================================================================\n\n";
}

void Books::listByBookName(const string name) const
{
	if( name == getBookName() ) displayInformation();
}

void Books::listByAuthor(const string name) const
{
	if( name == getAuthorName() ) displayInformation();
}

void Books::addBook()
{
	setBookName();
	setAuthorName();
	setPages();
	setPrice();
}

short Books::displayBookMenu()
{
	short choice;
	cout << "\t\t\n Display Book By\n"
		 << "1). Book Name\n" 
		 << "2). Serial Number\n"
		 << "3). Author Name\n"
		 << "4). Back\n";
		 
	cout << "Enter an option: ";
	cin >> choice;
	
	return choice;
}
