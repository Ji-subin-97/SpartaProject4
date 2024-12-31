#pragma once
#include <vector>
#include "Book.h"
using namespace std;

class BookManager {
private:
	vector<Book> books;
public:
	void addBook(const string& title, const string& author);
	void displayAllBooks() const;

	void searchByTitle(const string& title);
	void searchByAuthor(const string& author);
};