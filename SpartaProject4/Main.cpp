#include <iostream>

using namespace std;

int main()
{
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl;
        cout << "2. ��� å ���" << endl;
        cout << "3. ����" << endl;
        cout << "����: ";

        int choice;
        cin >> choice;

        if (choice == 1) {

        }
        else if (choice == 2) {
        }
        else if (choice == 3) {
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }
        else {
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}