#include <iostream>
#include "BookManager.h"

// 2

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


void BookManager::searchByTitle(const string& title)
{
	int count = 0;
	bool first = true;
	for (Book book : books)
	{
		if (string::npos != book.title.find(title))
		{
			if (first) {
				cout << "제목 기반 검색 도서 목록: " << endl;
				first = false;
			}
			cout << "- " << book.title << " by " << book.author << endl;
			count++;
		}
	}

	if (count == 0) {
		cout << "현재 등록된 책이 없습니다." << endl;
	}
}

void BookManager::searchByAuthor(const string& author)
{
	int count = 0;
	bool first = true;
	for (Book book : books)
	{
		if (string::npos != book.author.find(author))
		{
			if (first) {
				cout << "저자 기반 검색 도서 목록: " << endl;
				first = false;
			}
			cout << "- " << book.title << " by " << book.author << endl;
			count++;
		}
	}

	if (count == 0) {
		cout << "현재 등록된 책이 없습니다." << endl;
	}
}