#pragma once
#include "Manager.h"
#include "BookCase.h"

class BookManager : public Manager {
public:
	~BookManager() {}
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
};