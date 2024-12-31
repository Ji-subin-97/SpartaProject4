#include <iostream>
#include "Manager.h"

using namespace std;

class User {
private:
    string name;
    int bookCount;          // ������ Ƚ��
    int rbookCount;         // �ݳ��� Ƚ��
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

static map<int, User> userDB;   // �ӽ�DB

int main()
{
    User user("Pizza", Role::ALL_MANAGE);
    userDB.insert({ 1, user });

    bool isRun = true;
    int choice = 0;
    Role userRole = user.getRole();

    while (isRun) {
        cout << "\n���ĸ�Ÿ�ڵ�Ŭ�� ������ ���� ���α׷�" << endl;
        cout << "�������. [ " << user.getName() << " ] �� ���Ͻô� �۾��� �������ּ���." << endl;
        cout << "1. ���� ����" << endl;
        cout << "2. ���� ���� �� �ݳ� ����" << endl;
        cout << "3. ���� �̿�" << endl;
        cout << "4. ���α׷� ����" << endl;
        cout << "����: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է��� �ּ���." << endl;
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
                cout << "�ش� �۾��� ������ �����ϴ�. �����ڿ��� �������ּ���." << endl;
                break;
            }
            break;
        case 2:
            if (userRole == Role::ALL_MANAGE || userRole == Role::BRROW_MANAGE) {
                borrowManage();
            }
            else {
                cout << "�ش� �۾��� ������ �����ϴ�. �����ڿ��� �������ּ���." << endl;
                break;
            }
            break;
        case 3:
            normalMode();
            break;
        case 4:
            cout << "���α׷��� �����մϴ�. �̿����ּż� �����մϴ�. :)" << endl;
            isRun = false;
            break;
        default:
            break;
        }
    }

    return 0; // ���α׷� ���� ����
}

void normalMode() 
{

}
void bookManage() 
{
    bool isThreadEnd = false;
    int choice = 0;
    
    while (!isThreadEnd) {
        cout << "\n=================�������� ���=================" << endl;
        cout << "1. ���� �߰�" << endl;
        cout << "2. ���� ����" << endl;
        cout << "3. ���� �˻�" << endl;
        cout << "4. ���� �޴�" << endl;
        cout << "����: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է��� �ּ���." << endl;
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
        cout << "\n=============���� ���� �� �ݳ� ���============" << endl;
        cout << "1. ���� ����" << endl;
        cout << "2. ���� �ݳ�" << endl;
        cout << "3. ���� ��� Ȯ��" << endl;
        cout << "4. ���� ��� ����" << endl;
        cout << "5. ���� �޴�" << endl;
        cout << "����: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է��� �ּ���." << endl;
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