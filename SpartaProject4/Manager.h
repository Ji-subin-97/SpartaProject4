#pragma once
#include "BookCase.h"

class Manager {
public:
	virtual ~Manager() {}
	// ��� ���� ���
	virtual void findAllBooks(BookCase& bookcase) = 0;
	// ���� ��� �˻�
	virtual void findBookByTitle(const std::string& title, BookCase& bookcase) = 0;
	// ���� ��� �˻�
	virtual void findBookByAuthor(const std::string& author, BookCase& bookcase) = 0;

	// �߰�
	virtual void insertBook(const std::string& title, const std::string& author, BookCase& bookcase) = 0;
	//virtual void updateBook() = 0;			// ����
	//virtual void deleteBook() = 0;			// ����
};