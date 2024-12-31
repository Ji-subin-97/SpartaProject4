#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Book.h"
#include "Role.h"
#include "BookManager.h"
#include "BorrowManager.h"

using namespace std;

class Manager {
public:
	virtual ~Manager() {}
	//virtual Role getRole() const = 0;
	//virtual void displayAllBooks() = 0;
};