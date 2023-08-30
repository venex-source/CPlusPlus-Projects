#ifndef BOOK_STORE_H
#define BOOK_STORE_H

class Books{
	public:
		void setBookName();
		void setAuthorName();
		void setPages();
		void setPrice();
		
		std::string getBookName() const;
		std::string getAuthorName() const;
		short getPages() const;
		unsigned getPrice() const;
		
		void addBook();
		void displayInformation() const;
		void displayTable() const;
		
		void listByBookName(const std::string) const;
		void listByAuthor(const std::string) const;		
		
		short displayBookMenu();
		
	private:
		std::string book_name;
		std::string author_name;
		short pages;
		unsigned price;
};

#endif
