#pragma once
#include <string>
using namespace std;

class Book {
public:
	string title;
	string author;

	// 1

	Book(const string& title, const string& author) : title(title), author(author) {}
};