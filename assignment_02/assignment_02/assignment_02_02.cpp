#include <iostream>

using namespace std;

int main() {
	int choice, lvalue, rvalue, error, result;
	char Oper;
	while (true) {
		choice = 0; lvalue = 0; rvalue = 0; Oper = 0; error = 0; result = 0;

		cout << "�� ���� ��Ģ������ �������ִ� ���� �����Դϴ�." << endl <<
			"���� ��Ģ ������ ����Ͻðڽ��ϱ�?" << endl <<
			"[1] ���ϱ� ( + )" << endl << "[2] ���� ( - )" << endl <<
			"[3] ���ϱ� ( * )" << endl << "[4] ������ ( / )" << endl;
		cin >> choice;

		switch (choice) {	//  ������ ������ ���� ������ �������� ����
		case 1: Oper = '+'; break;	//Oper���� ������ + �� ����
		case 2: Oper = '-'; break;	//Oper���� ������ - �� ����
		case 3: Oper = '*'; break;	//Oper���� ������ * �� ����
		case 4: Oper = '/'; break;	//Oper���� ������ / �� ����
		default: error += 1; break;	//�ùٸ��� ���� �Է��� �� error���� 1�� ����
		}
		if (error > 0) {	//error���� 1�̻��� ��� ������ ����ϸ� ó������ ���� ��
			cout << "ERROR!" << endl;
			_sleep(1000);
			system("cls");
			continue;
		}

		cout << "������ �����ڴ� '" << Oper << "' �Դϴ�." << endl <<
			"�ش� ������ ������ �� ���� �Է��Ͽ� �ּ���." << endl <<
				"ù ��° �� : ";
			cin >> lvalue;		//�������� ���ʿ� ��ġ�� ��

			cout << "�� ��° �� : ";
			cin >> rvalue;		//�������� �����ʿ� ��ġ�� ��

		switch (choice) {	//�ռ� ������ ���� ���� ���� ������ ������ �� ����
		case 1: result = lvalue + rvalue; break;
		case 2: result = lvalue - rvalue; break;
		case 3: result = lvalue * rvalue; break;
		case 4: result = lvalue / rvalue; break;
			// ���õ� �����ڿ� ���� ����� �� result ���� ����
		}

	rechoice:
		cout << "[���] " << lvalue << " " << Oper << " " << rvalue << " = " << result << endl << endl <<
			"ó������ ���ư��� ���⸦ ���� �մϱ�?" << endl <<
			"[1] ��" << endl << "[2] �ƴϿ�" << endl;
		cin >> choice;
		// ����� ��� �� ���⸦ �ٽ� ������� �������� ����
		
		if (choice == 1) {
			system("cls");
			continue;	//���⸦ �ٽ� ����ϱ� ���� �ܼ��� �����ϰ� ó������ ���� ��
		}
		else if (choice == 2) {
			break;	//���⸦ ������
		}
		else {	//1,2�̿��� ���� �Է����� ��� ������ ó���ϸ� �ܼ��� �����ϰ� ����â���� ���� ��
			cout << "�ùٸ��� ���� �Է��Դϴ�." << endl;
			_sleep(1000);
			system("cls");
			goto rechoice;
		}

		}
	return 0;
}