#pragma once
#include "Manager.h"
#include "BookCase.h"

class BorrowManager : public Manager {
private :
	std::vector<Book> rentalBooks;
public:
	BorrowManager() {}
	~BorrowManager() {}
	// ��� ���� ���
	void findAllBooks(BookCase& bookcase);
	// ���� ��� �˻�
	void findBookByTitle(const std::string& title, BookCase& bookcase);
	// ���� ��� �˻�
	void findBookByAuthor(const std::string& author, BookCase& bookcase);
	// �߰�
	void insertBook(const std::string& title, const std::string& author, BookCase& bookcase);
	// void updateBook();			// ����
	// void deleteBook();			// ����

	// å �뿩
	void rentalBook(const std::string& title, const std::string& author, BookCase& bookcase);
	// å �ݳ�
	void returnBook(BookCase& bookcase);
};