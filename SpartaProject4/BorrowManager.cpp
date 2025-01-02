#include <iostream>
#include <string>
#include <vector>
#include "BorrowManager.h"

using namespace std;

void BorrowManager::findAllBooks(BookCase& bookcase) {
	const vector<Book>& books = bookcase.getBooks();

	if (books.empty()) {
		cout << "현재 등록된 도서가 없습니다." << endl;
		return;
	}

	for (const Book& book : books) {
		string status = book.getCount() > 0 ? "가능" : "불가능";

		cout << "[ 제목: " << book.getTitle() << " ]" << "[ 저자: " << book.getAuthor() << " ]"
			<< "[ 등록 수: " << book.getCount() << "개 ]"  << "[ 대여 수: " << book.getRcount() << "개 ]"
			<< "[ 대반여부: " << status << " ]" << endl;
	}
}

void BorrowManager::findBookByTitle(const string& title, BookCase& bookcase) {
	int choice;
	int count = 0;
	bool isFirst = true;
	vector<Book>& books = bookcase.getBooks();
	
	if (books.empty()) {
		cout << "현재 등록된 도서가 없습니다." << endl;
		return;
	}

	for (Book& book : books) {
		if (book.getTitle().find(title) != string::npos && book.getCount() > 0) {
			if (isFirst) {
				cout << "[ " << title << " ] 제목으로 검색된 현재 대여가능한 도서 목록입니다." << endl;
				isFirst = false;
			}

			cout << "- " << book.getTitle() << " by " << book.getAuthor() << endl;
			cout << "해당 도서를 대여 목록에 넣으시겠습니까? (예 : 1 / 아니오 : 2)" << endl;
			cout << "선택: ";
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
				cout << "잘못된 입력입니다. 예(1) 및 아니오(2)중 선택해주세요." << endl;
			}

			count++;
		}
	}

	if (count == 0) {
		cout << "[ " << title << " ] 제목으로 검색된 대여가능한 도서가 없습니다." << endl;
	}
}

void BorrowManager::findBookByAuthor(const string& author, BookCase& bookcase) {
	int choice;
	int count = 0;
	bool isFirst = true;
	vector<Book>& books = bookcase.getBooks();

	if (books.empty()) {
		cout << "현재 등록된 도서가 없습니다." << endl;
		return;
	}

	for (Book& book : books) {
		if (book.getAuthor().find(author) != string::npos && book.getCount() > 0) {
			if (isFirst) {
				cout << "[ " << author << " ] 저자로 검색된 현재 대여가능한 도서 목록입니다." << endl;
				isFirst = false;
			}

			cout << "- " << book.getTitle() << " by " << book.getAuthor() << endl;
			cout << "해당 도서를 대여 목록에 넣으시겠습니까? (예 : 1 / 아니오 : 2)" << endl;
			cout << "선택: ";
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
				cout << "잘못된 입력입니다. 예(1) 및 아니오(2)중 선택해주세요." << endl;
			}

			count++;
		}
	}

	if (count == 0) {
		cout << "[ " << author << " ] 저자로 검색된 대여가능한 도서가 없습니다." << endl;
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

