#pragma once
#include "Manager.h"
#include "BookCase.h"

class BorrowManager : public Manager {
private :
	std::vector<Book> rentalBooks;
public:
	BorrowManager() {}
	~BorrowManager() {}
	// 모든 도서 출력
	void findAllBooks(BookCase& bookcase);
	// 제목 기반 검색
	void findBookByTitle(const std::string& title, BookCase& bookcase);
	// 저자 기반 검색
	void findBookByAuthor(const std::string& author, BookCase& bookcase);
	// 추가
	void insertBook(const std::string& title, const std::string& author, BookCase& bookcase);
	// void updateBook();			// 수정
	// void deleteBook();			// 삭제

	// 책 대여
	void rentalBook(const std::string& title, const std::string& author, BookCase& bookcase);
	// 책 반납
	void returnBook(BookCase& bookcase);
};