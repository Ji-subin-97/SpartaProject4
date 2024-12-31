#include <iostream>
#include "BookManager.h"

using namespace std;

int main()
{
    BookManager manager;

    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl;
        cout << "2. ��� å ���" << endl;
        cout << "3. ����" << endl;
        cout << "4. å �˻�" << endl;
        cout << "����: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string title, author;
            cout << "å ����: ";
            cin.ignore();
            getline(cin, title);
            cout << "å ����: ";
            getline(cin, author);

            manager.addBook(title, author);
        }
        else if (choice == 2) {
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }
        else if (choice == 4) {
            cout << "1. �̸����� �˻�" << endl;
            cout << "2. ���ڷ� �˻�" << endl;
            cout << "����: ";
            cin >> choice;

            if (choice == 1) {
                string title;
                cout << "���� �˻�: ";
                cin.ignore();
                getline(cin, title);

                manager.searchByTitle(title);
            }
            else if (choice == 2) {
                string author;
                cout << "���� �˻�: ";
                cin.ignore();
                getline(cin, author);

                manager.searchByAuthor(author);
            }
            else {
                cout << "�߸��� �Է��Դϴ�. ó��ȭ������ ���ư��ϴ�." << endl;
            }
        }
        else {
            // ���ڰ� �ƴҶ� ���ѷ���
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}