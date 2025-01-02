#pragma once
#include <string>
#include <vector>
#include "Book.h"

class BookCase {
private:
	std::string caseName;
	std::vector<Book> books;
public:
	BookCase(const std::string& caseName){
		this->caseName = caseName;
	}

	const std::string& getCaseName() {
		return caseName;
	}

	std::vector<Book>& getBooks() {
		return books;
	}
};
