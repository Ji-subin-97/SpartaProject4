#include <iostream>
#include <string>
#include <vector>
#include "BorrowManager.h"

using namespace std;

void BorrowManager::findAllBooks(BookCase& bookcase) {
	const vector<Book>& books = bookcase.getBooks();

	if (books.empty()) {
		cout << "���� ��ϵ� ������ �����ϴ�." << endl;
		return;
	}

	for (const Book& book : books) {
		string status = book.getCount() > 0 ? "����" : "�Ұ���";

		cout << "[ ����: " << book.getTitle() << " ]" << "[ ����: " << book.getAuthor() << " ]"
			<< "[ ��� ��: " << book.getCount() << "�� ]"  << "[ �뿩 ��: " << book.getRcount() << "�� ]"
			<< "[ ��ݿ���: " << status << " ]" << endl;
	}
}

void BorrowManager::findBookByTitle(const string& title, BookCase& bookcase) {
	int choice;
	int count = 0;
	bool isFirst = true;
	vector<Book>& books = bookcase.getBooks();
	
	if (books.empty()) {
		cout << "���� ��ϵ� ������ �����ϴ�." << endl;
		return;
	}

	for (Book& book : books) {
		if (book.getTitle().find(title) != string::npos && book.getCount() > 0) {
			if (isFirst) {
				cout << "[ " << title << " ] �������� �˻��� ���� �뿩������ ���� ����Դϴ�." << endl;
				isFirst = false;
			}

			cout << "- " << book.getTitle() << " by " << book.getAuthor() << endl;
			cout << "�ش� ������ �뿩 ��Ͽ� �����ðڽ��ϱ�? (�� : 1 / �ƴϿ� : 2)" << endl;
			cout << "����: ";
			cin >> choice;

			if (choice == 1) {
				rentalBooks.push_back(book);
				book.setCount(book.getCount() - 1);
				book.setRcount(book.getRcount() + 1);
			}
			else if (choice == 2) {
				break;
			}
			else {
				cout << "�߸��� �Է��Դϴ�. ��(1) �� �ƴϿ�(2)�� �������ּ���." << endl;
			}

			count++;
		}
	}

	if (count == 0) {
		cout << "[ " << title << " ] �������� �˻��� �뿩������ ������ �����ϴ�." << endl;
	}
}

void BorrowManager::findBookByAuthor(const string& author, BookCase& bookcase) {
	int choice;
	int count = 0;
	bool isFirst = true;
	vector<Book>& books = bookcase.getBooks();

	if (books.empty()) {
		cout << "���� ��ϵ� ������ �����ϴ�." << endl;
		return;
	}

	for (Book& book : books) {
		if (book.getAuthor().find(author) != string::npos && book.getCount() > 0) {
			if (isFirst) {
				cout << "[ " << author << " ] ���ڷ� �˻��� ���� �뿩������ ���� ����Դϴ�." << endl;
				isFirst = false;
			}

			cout << "- " << book.getTitle() << " by " << book.getAuthor() << endl;
			cout << "�ش� ������ �뿩 ��Ͽ� �����ðڽ��ϱ�? (�� : 1 / �ƴϿ� : 2)" << endl;
			cout << "����: ";
			cin >> choice;

			if (choice == 1) {
				rentalBooks.push_back(book);
				book.setCount(book.getCount() - 1);
				book.setRcount(book.getRcount() + 1);
			}
			else if (choice == 2) {
				break;
			}
			else {
				cout << "�߸��� �Է��Դϴ�. ��(1) �� �ƴϿ�(2)�� �������ּ���." << endl;
			}

			count++;
		}
	}

	if (count == 0) {
		cout << "[ " << author << " ] ���ڷ� �˻��� �뿩������ ������ �����ϴ�." << endl;
	}
}

void BorrowManager::insertBook(const string& title, const string& author, BookCase& bookcase) {
}

void BorrowManager::rentalBook(const std::string& title, const std::string& author, BookCase& bookcase) {

	if (!title.empty()) {
		findBookByTitle(title, bookcase);
	}
	else {
		findBookByAuthor(author, bookcase);
	}
	
	bookcase.getBooks();
}

