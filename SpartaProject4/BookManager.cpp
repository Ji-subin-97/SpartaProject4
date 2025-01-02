#include <iostream>
#include <string>
#include <vector>
#include "BookManager.h"

using namespace std;

void BookManager::findAllBooks(BookCase& bookcase) {
	const vector<Book>& books = bookcase.getBooks();
	
	if (books.empty()) {
		cout << "현재 등록된 도서가 없습니다." << endl;
		return;
	}

	for (const Book& book : books) {
		cout << "- " << book.getTitle() << " by " << book.getAuthor() << endl;
	}
}

void BookManager::findBookByTitle(const string& title, BookCase& bookcase) {
	int count = 0;
	bool isFirst = true;
	const vector<Book>& books = bookcase.getBooks();

	if (books.empty()) {
		cout << "현재 등록된 도서가 없습니다." << endl;
		return;
	}

	for (const Book& book : books) {
		if (book.getTitle().find(title) != string::npos) {
			if (isFirst) {
				cout << "[ " << title << " ] 제목으로 검색된 도서 목록입니다." << endl;
				isFirst = false;
			}
			cout << "- " << book.getTitle() << " by " << book.getAuthor() << endl;
			count++;
		}
	}

	if (count == 0) {
		cout << "[ " << title << " ] 제목으로 검색된 도서가 없습니다." << endl;
	}
}

void BookManager::findBookByAuthor(const string& author, BookCase& bookcase) {
	int count = 0;
	bool isFirst = true;
	const vector<Book>& books = bookcase.getBooks();

	if (books.empty()) {
		cout << "현재 등록된 도서가 없습니다." << endl;
		return;
	}

	for (const Book& book : books) {
		if (book.getAuthor().find(author) != string::npos) {
			if (isFirst) {
				cout << "[ " << author << " ] 저자로 검색된 도서 목록입니다." << endl;
				isFirst = false;
			}
			cout << "- " << book.getTitle() << " by " << book.getAuthor() << endl;
			count++;
		}
	}

	if (count == 0) {
		cout << "[ " << author << " ] 저자로 검색된 도서가 없습니다." << endl;
	}
}

void BookManager::insertBook(const string& title, const string& author, BookCase& bookcase) {
	vector<Book>& books = bookcase.getBooks();
	
	books.push_back(Book(title, author));
	cout << "도서가 추가되었습니다: " << title << " by " << author << endl;
}