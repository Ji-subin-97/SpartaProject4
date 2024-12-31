#include <iostream>
#include "BookManager.h"

void BookManager::addBook(const string& title, const string& author)
{
	books.push_back(Book(title, author));
	cout << "책이 추가되었습니다: " << title << " by " << author << endl;
}

void BookManager::displayAllBooks() const
{
	if (books.empty()) {
		cout << "현재 등록된 책이 없습니다." << endl;
		return;
	}

	cout << "현재 도서 목록: " << endl;
	for (size_t i = 0; i < books.size(); i++) {
		cout << "- " << books[i].title << " by " << books[i].author << endl;
	}

}