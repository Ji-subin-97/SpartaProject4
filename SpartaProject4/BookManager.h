#pragma once
#include "Manager.h"
#include "BookCase.h"

class BookManager : public Manager {
public:
	~BookManager() {}
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
};