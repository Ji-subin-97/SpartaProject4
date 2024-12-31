#include <iostream>
#include "BookManager.h"

using namespace std;

int main()
{
    BookManager manager;

    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl;
        cout << "2. 모든 책 출력" << endl;
        cout << "3. 종료" << endl;
        cout << "4. 책 검색" << endl;
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string title, author;
            cout << "책 제목: ";
            cin.ignore();
            getline(cin, title);
            cout << "책 저자: ";
            getline(cin, author);

            manager.addBook(title, author);
        }
        else if (choice == 2) {
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else if (choice == 4) {
            cout << "1. 이름으로 검색" << endl;
            cout << "2. 저자로 검색" << endl;
            cout << "선택: ";
            cin >> choice;

            if (choice == 1) {
                string title;
                cout << "제목 검색: ";
                cin.ignore();
                getline(cin, title);

                manager.searchByTitle(title);
            }
            else if (choice == 2) {
                string author;
                cout << "저자 검색: ";
                cin.ignore();
                getline(cin, author);

                manager.searchByAuthor(author);
            }
            else {
                cout << "잘못된 입력입니다. 처음화면으로 돌아갑니다." << endl;
            }
        }
        else {
            // 숫자가 아닐때 무한루프
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0; // 프로그램 정상 종료
}