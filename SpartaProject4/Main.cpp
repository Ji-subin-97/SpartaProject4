#include <iostream>
#include "BookCase.h"
#include "BookManager.h"
#include "BorrowManager.h"

using namespace std;

int main()
{	
	// Manager: ���� : ���������ȸ, ������ϰ˻�
	// BookCase : å��

	BookManager bookManager;
	BorrowManager borrowManager;

	BookCase* bookCase = new BookCase("Sparta");

	int choice;
	bool isRun = true;

	while (isRun) {
		cout << "\n���ĸ�Ÿ�ڵ�Ŭ�� �����������α׷�" << endl;
		cout << "1. ���� �߰�" << endl;
		cout << "2. ���� ���" << endl;
		cout << "3. ���� �˻�" << endl;
		cout << "4. ���� ����" << endl;
		cout << "5. ���� �뿩" << endl;
		cout << "6. ���� �ݳ�" << endl;
		cout << "7. ���α׷� ����" << endl;
		cout << "����: ";
		cin >> choice;

		if (cin.fail()) {
			cout << "���ڸ� �Է°����մϴ�." << endl;
			cin.clear();
			cin.ignore();

			continue;
		}

		switch (choice)
		{
		case 1:
		{
			string title, author;
			cout << "\n���� ����: ";
			cin.ignore();
			getline(cin, title);
			cout << "���� ����: ";
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
				cout << "\n1. ������ �˻�" << endl;
				cout << "2. ���ڱ�� �˻�" << endl;
				cout << "3. ���θ޴�" << endl;
				cout << "����: ";
				cin >> choice;

				if (cin.fail()) {
					cout << "���ڸ� �Է°����մϴ�." << endl;
					cin.clear();
					cin.ignore();

					continue;
				}

				if (choice == 1) {
					string title;
					cout << "���� ����: ";
					cin.ignore();
					getline(cin, title);

					bookManager.findBookByTitle(title, *bookCase);
				}
				else if (choice == 2) {
					string author;
					cout << "���� ����: ";
					cin.ignore();
					getline(cin, author);

					bookManager.findBookByAuthor(author, *bookCase);
				}
				else if (choice == 3) {
					break;
				}
				else {
					cout << "�߸��� �Է��Դϴ�. �޴� ��ȣ�� �������ּ���." << endl;
				}
			}
		}
			break;
		case 4:
			borrowManager.findAllBooks(*bookCase);
			break;
		case 5:
			while (true) {
				cout << "\n���ĸ�Ÿ�ڵ�Ŭ�� �����뿩 �����Դϴ�. :)" << endl;
				cout << "�˻� �� ���Ͻô� ������ �������ּ���. ��ݿ��� Ȯ�� ��." << endl;
				cout << "1. ������ �˻�" << endl;
				cout << "2. ���ڱ�� �˻�" << endl;
				cout << "3. ���θ޴�" << endl;
				cout << "����: ";
				cin >> choice;

				if (cin.fail()) {
					cout << "���ڸ� �Է°����մϴ�." << endl;
					cin.clear();
					cin.ignore();

					continue;
				}

				if (choice == 1) {
					string title, author;
					cout << "���� ����: ";
					cin.ignore();
					getline(cin, title);

					borrowManager.rentalBook(title, author, *bookCase);
				}
				else if (choice == 2) {
					string title, author;
					cout << "���� ����: ";
					cin.ignore();
					getline(cin, author);

					borrowManager.rentalBook(title, author, *bookCase);
				}
				else if (choice == 3) {
					break;
				}
				else {
					cout << "�߸��� �Է��Դϴ�. �޴� ��ȣ�� �������ּ���." << endl;
				}
			}

			break;
		case 6:
			break;
		case 7:
			cout << "���α׷��� �����մϴ�. �̿��� �ּż� �����մϴ�. :)" << endl;
			isRun = false;
			break;
		default:
			cout << "�߸��� �Է��Դϴ�. �޴� ��ȣ�� �������ּ���." << endl;
			break;
		}
	}

	delete bookCase;

	return 0;
}