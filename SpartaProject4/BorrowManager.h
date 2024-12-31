#pragma once
#include "Manager.h"

class BorrowManager {
private:
	Role role = Role::BRROW_MANAGE;
public:
	BorrowManager() {}
	//Role getRole() const override;
	//void displayAllBooks() override;


	// 책 빌려주기
	// 책 반납받기
	// 책 재고 확인하기
	// 책 재고 수정하기
};