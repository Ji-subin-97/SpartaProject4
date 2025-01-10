#include <iostream>
#include "BookManager.h"

// 2

void BookManager::addBook(const string& title, const string& author)
{
	books.push_back(Book(title, author));
	cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
}

void BookManager::displayAllBooks() const
{
	if (books.empty()) {
		cout << "���� ��ϵ� å�� �����ϴ�." << endl;
		return;
	}

	cout << "���� ���� ���: " << endl;
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
				cout << "���� ��� �˻� ���� ���: " << endl;
				first = false;
			}
			cout << "- " << book.title << " by " << book.author << endl;
			count++;
		}
	}

	if (count == 0) {
		cout << "���� ��ϵ� å�� �����ϴ�." << endl;
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
				cout << "���� ��� �˻� ���� ���: " << endl;
				first = false;
			}
			cout << "- " << book.title << " by " << book.author << endl;
			count++;
		}
	}

	if (count == 0) {
		cout << "���� ��ϵ� å�� �����ϴ�." << endl;
	}
}