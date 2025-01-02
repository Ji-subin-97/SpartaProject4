#include <iostream>
#include "BookCase.h"
#include "BookManager.h"
#include "BorrowManager.h"

using namespace std;

int main()
{	
	// Manager: 공통 : 도서목록조회, 도서목록검색
	// BookCase : 책장

	BookManager bookManager;
	BorrowManager borrowManager;

	BookCase* bookCase = new BookCase("Sparta");

	int choice;
	bool isRun = true;

	while (isRun) {
		cout << "\n스파르타코딩클럽 도서관리프로그램" << endl;
		cout << "1. 도서 추가" << endl;
		cout << "2. 도서 목록" << endl;
		cout << "3. 도서 검색" << endl;
		cout << "4. 도서 관리" << endl;
		cout << "5. 도서 대여" << endl;
		cout << "6. 도서 반납" << endl;
		cout << "7. 프로그램 종료" << endl;
		cout << "선택: ";
		cin >> choice;

		if (cin.fail()) {
			cout << "숫자만 입력가능합니다." << endl;
			cin.clear();
			cin.ignore();

			continue;
		}

		switch (choice)
		{
		case 1:
		{
			string title, author;
			cout << "\n도서 제목: ";
			cin.ignore();
			getline(cin, title);
			cout << "도서 저자: ";
			getline(cin, author);

			bookManager.insertBook(title, author, *bookCase);
		}
			break;
		case 2:
			bookManager.findAllBooks(*bookCase);
			break;
		case 3:
		{
			while (true) {
				cout << "\n1. 제목기반 검색" << endl;
				cout << "2. 저자기반 검색" << endl;
				cout << "3. 메인메뉴" << endl;
				cout << "선택: ";
				cin >> choice;

				if (cin.fail()) {
					cout << "숫자만 입력가능합니다." << endl;
					cin.clear();
					cin.ignore();

					continue;
				}

				if (choice == 1) {
					string title;
					cout << "도서 제목: ";
					cin.ignore();
					getline(cin, title);

					bookManager.findBookByTitle(title, *bookCase);
				}
				else if (choice == 2) {
					string author;
					cout << "도서 저자: ";
					cin.ignore();
					getline(cin, author);

					bookManager.findBookByAuthor(author, *bookCase);
				}
				else if (choice == 3) {
					break;
				}
				else {
					cout << "잘못된 입력입니다. 메뉴 번호중 선택해주세요." << endl;
				}
			}
		}
			break;
		case 4:
			borrowManager.findAllBooks(*bookCase);
			break;
		case 5:
			while (true) {
				cout << "\n스파르타코딩클럽 도서대여 서비스입니다. :)" << endl;
				cout << "검색 후 원하시는 도서를 선택해주세요. 대반여부 확인 필." << endl;
				cout << "1. 제목기반 검색" << endl;
				cout << "2. 저자기반 검색" << endl;
				cout << "3. 메인메뉴" << endl;
				cout << "선택: ";
				cin >> choice;

				if (cin.fail()) {
					cout << "숫자만 입력가능합니다." << endl;
					cin.clear();
					cin.ignore();

					continue;
				}

				if (choice == 1) {
					string title, author;
					cout << "도서 제목: ";
					cin.ignore();
					getline(cin, title);

					borrowManager.rentalBook(title, author, *bookCase);
				}
				else if (choice == 2) {
					string title, author;
					cout << "도서 저자: ";
					cin.ignore();
					getline(cin, author);

					borrowManager.rentalBook(title, author, *bookCase);
				}
				else if (choice == 3) {
					break;
				}
				else {
					cout << "잘못된 입력입니다. 메뉴 번호중 선택해주세요." << endl;
				}
			}

			break;
		case 6:
			break;
		case 7:
			cout << "프로그램을 종료합니다. 이용해 주셔서 감사합니다. :)" << endl;
			isRun = false;
			break;
		default:
			cout << "잘못된 입력입니다. 메뉴 번호중 선택해주세요." << endl;
			break;
		}
	}

	delete bookCase;

	return 0;
}