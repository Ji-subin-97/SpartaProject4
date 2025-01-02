#pragma once
#include "BookCase.h"

class Manager {
public:
	virtual ~Manager() {}
	// 모든 도서 출력
	virtual void findAllBooks(BookCase& bookcase) = 0;
	// 제목 기반 검색
	virtual void findBookByTitle(const std::string& title, BookCase& bookcase) = 0;
	// 저자 기반 검색
	virtual void findBookByAuthor(const std::string& author, BookCase& bookcase) = 0;

	// 추가
	virtual void insertBook(const std::string& title, const std::string& author, BookCase& bookcase) = 0;
	//virtual void updateBook() = 0;			// 수정
	//virtual void deleteBook() = 0;			// 삭제
};