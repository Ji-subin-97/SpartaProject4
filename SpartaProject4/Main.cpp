#include <iostream>
#include "Manager.h"

using namespace std;

class User {
private:
    string name;
    int bookCount;          // 빌려간 횟수
    int rbookCount;         // 반납한 횟수
    Role role;
public:
    User(string name, Role role) : name(name), role(role) 
    {
        bookCount = 0;
        rbookCount = 0;
    }
    string getName()
    {
        return name;
    }
    int getBookCount()
    {
        return bookCount;
    }
    int getRbookCount()
    {
        return rbookCount;
    }
    Role getRole()
    {
        return role;
    }
};

// void checkAuth(User user);
void normalMode();
void bookManage();
void borrowManage();

static map<int, User> userDB;   // 임시DB

int main()
{
    User user("Pizza", Role::ALL_MANAGE);
    userDB.insert({ 1, user });

    bool isRun = true;
    int choice = 0;
    Role userRole = user.getRole();

    while (isRun) {
        cout << "\n스파르타코딩클럽 도서관 관리 프로그램" << endl;
        cout << "어서오세요. [ " << user.getName() << " ] 님 원하시는 작업을 선택해주세요." << endl;
        cout << "1. 도서 관리" << endl;
        cout << "2. 도서 대출 및 반납 관리" << endl;
        cout << "3. 도서 이용" << endl;
        cout << "4. 프로그램 종료" << endl;
        cout << "선택: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "잘못된 입력입니다. 숫자만 입력해 주세요." << endl;
            cin.clear();
            cin.ignore();

            continue;
        }

        switch (choice)
        {
        case 1:
            if (userRole == Role::ALL_MANAGE || userRole == Role::BOOK_MANAGE) {
                bookManage();
            }
            else {
                cout << "해당 작업에 권한이 없습니다. 관리자에게 문의해주세요." << endl;
                break;
            }
            break;
        case 2:
            if (userRole == Role::ALL_MANAGE || userRole == Role::BRROW_MANAGE) {
                borrowManage();
            }
            else {
                cout << "해당 작업에 권한이 없습니다. 관리자에게 문의해주세요." << endl;
                break;
            }
            break;
        case 3:
            normalMode();
            break;
        case 4:
            cout << "프로그램을 종료합니다. 이용해주셔서 감사합니다. :)" << endl;
            isRun = false;
            break;
        default:
            break;
        }
    }

    return 0; // 프로그램 정상 종료
}

void normalMode() 
{

}
void bookManage() 
{
    bool isThreadEnd = false;
    int choice = 0;
    
    while (!isThreadEnd) {
        cout << "\n=================도서관리 모드=================" << endl;
        cout << "1. 도서 추가" << endl;
        cout << "2. 도서 삭제" << endl;
        cout << "3. 도서 검색" << endl;
        cout << "4. 메인 메뉴" << endl;
        cout << "선택: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "잘못된 입력입니다. 숫자만 입력해 주세요." << endl;
            cin.clear();
            cin.ignore();

            continue;
        }

        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 4:
            isThreadEnd = true;
            break;
        default:
            break;
        }
    }
}
void borrowManage() 
{
    bool isThreadEnd = false;
    int choice = 0;

    while (!isThreadEnd) {
        cout << "\n=============도서 대출 및 반납 모드============" << endl;
        cout << "1. 도서 대출" << endl;
        cout << "2. 도서 반납" << endl;
        cout << "3. 도서 재고 확인" << endl;
        cout << "4. 도서 재고 수정" << endl;
        cout << "5. 메인 메뉴" << endl;
        cout << "선택: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "잘못된 입력입니다. 숫자만 입력해 주세요." << endl;
            cin.clear();
            cin.ignore();

            continue;
        }

        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 5:
            isThreadEnd = true;
            break;
        default:
            break;
        }
    }
}