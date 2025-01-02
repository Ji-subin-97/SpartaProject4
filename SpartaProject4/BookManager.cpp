#include <iostream>
#include <string>
#include <vector>
#include "BookManager.h"

using namespace std;

void BookManager::findAllBooks(BookCase& bookcase) {
	const vector<Book>& books = bookcase.getBooks();
	
	if (books.empty()) {
		cout << "���� ��ϵ� ������ �����ϴ�." << endl;
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
		cout << "���� ��ϵ� ������ �����ϴ�." << endl;
		return;
	}

	for (const Book& book : books) {
		if (book.getTitle().find(title) != string::npos) {
			if (isFirst) {
				cout << "[ " << title << " ] �������� �˻��� ���� ����Դϴ�." << endl;
				isFirst = false;
			}
			cout << "- " << book.getTitle() << " by " << book.getAuthor() << endl;
			count++;
		}
	}

	if (count == 0) {
		cout << "[ " << title << " ] �������� �˻��� ������ �����ϴ�." << endl;
	}
}

void BookManager::findBookByAuthor(const string& author, BookCase& bookcase) {
	int count = 0;
	bool isFirst = true;
	const vector<Book>& books = bookcase.getBooks();

	if (books.empty()) {
		cout << "���� ��ϵ� ������ �����ϴ�." << endl;
		return;
	}

	for (const Book& book : books) {
		if (book.getAuthor().find(author) != string::npos) {
			if (isFirst) {
				cout << "[ " << author << " ] ���ڷ� �˻��� ���� ����Դϴ�." << endl;
				isFirst = false;
			}
			cout << "- " << book.getTitle() << " by " << book.getAuthor() << endl;
			count++;
		}
	}

	if (count == 0) {
		cout << "[ " << author << " ] ���ڷ� �˻��� ������ �����ϴ�." << endl;
	}
}

void BookManager::insertBook(const string& title, const string& author, BookCase& bookcase) {
	vector<Book>& books = bookcase.getBooks();
	
	books.push_back(Book(title, author));
	cout << "������ �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
}