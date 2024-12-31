#include <iostream>
#include "BookManager.h"

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