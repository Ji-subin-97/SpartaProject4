#pragma once
#include <string>

class Book {
private:
	std::string title;
	std::string author;
	int count;			// 기본 등록수 3개
	int rCount;
public:
	Book(const std::string& title, const std::string& author, int count = 3, int rCount = 0) {
		this->title = title;
		this->author = author;
		this->count = count;
		this->rCount = rCount;
	}
	~Book() {}

	std::string getTitle() const {
		return title;
	}

	std::string getAuthor() const {
		return author;
	}

	int getCount() const {
		return count;
	}
	int getRcount() const {
		return rCount;
	}
	void setCount(int count) {
		this->count = count;
	}
	void setRcount(int rCount) {
		this->rCount = rCount;
	}
};