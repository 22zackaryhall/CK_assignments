#include <iostream>

using namespace std;

int main() {

	int choice, Height, width, length;

START:
	choice = 0; Height = 0; width = 0; length = 0;


	cout << "'*' �� �̿��Ͽ� ������ ����� ���α׷��Դϴ�." << endl <<
		"4���� ���� �� �� ������ ������ �ּ���" << endl <<
		"[1] �ﰢ��	[2] ���ﰢ��" << endl <<
		"[3] ������	[4] �簢��" << endl << endl <<
		"���� : ";
	cin >> choice;	//� �������� ����� �� ������ ���� choice���� ����
	cout << endl;
	switch (choice) {	//�ռ� ������ �������� ������ ����ϴ��� �˸�
	case 1: cout << "������ ������ �ﰢ�� �Դϴ�." << endl; break;
	case 2: cout << "������ ������ ���ﰢ�� �Դϴ�." << endl; break;
	case 3: cout << "������ ������ ������ �Դϴ�." << endl; break;
	case 4: cout << "������ ������ �簢�� �Դϴ�." << endl; break;
	default: cout << "�־��� ��(1~4) �� �Է����ּ���!" << endl; //1~4�̿��� ���� �Է��Ͽ��� ��� �ܼ��� �����ϰ� �������� ���� ��
		_sleep(1000);
		system("cls");
		goto START;
	}
	
	switch (choice) {	//�ռ� ������ �������� ����
	case 1:
		cout << "�ﰢ���� ���̸� ������ �ֽʽÿ�." << endl <<
			"���� : ";
		cin >> Height;	//�Է� ���� ���̸� Height���� ����
		for (int i = 1; i <= Height; i++) {	//Height�� ���� ����Ƚ���� ����
			for (int b = 0; b < Height - i; b++) {	//Height-1 ��ŭ ������ ���
				cout << " ";
			}
			for (int ast = 0; ast < i; ast++) {	//i�� ��ŭ  '* '�� ���
				cout << "* ";
			}
			cout << endl;

		}
		break;

	case 2:
		cout << "���ﰢ���� ���̸� ������ �ֽʽÿ�." << endl <<
			"���� : ";
		cin >> Height;
		for (int i = 0; i <= Height; i++) {
			for (int b = 0; b <= i; b++) {	//i�� ��ŭ ������ ���
				cout << " ";
			}
			for (int ast = 0; ast < Height - i; ast++) {	//Height - i�� ��ŭ  '* '�� ���
				cout << "* ";
			}
			cout << endl;
		}
		break;

	case 3:
		cout << "�������� ���̸� ������ �ֽʽÿ�." << endl <<
			"���� : ";
		cin >> Height;
		for (int i = 1; i <= Height; i++) {
			for (int b = 0; b <= Height - i; b++) {	//Height - i ��ŭ ������ ���
				cout << " ";
			}
			for (int ast = 0; ast < i; ast++) {	//i�� ��ŭ  '* '�� ���
				cout << "* ";
			}
			cout << endl;
		}	//�ﰢ�� ���� ���� �� ���ﰢ�� ���� ����
		for (int i = 1; i <= Height; i++) {
			for (int b = 0; b <= i; b++) {	//i�� ��ŭ ������ ���
				cout << " ";
			}
			for (int ast = 0; ast < Height - i; ast++) {	//Height - i�� ��ŭ  '* '�� ���
				cout << "* ";
			}
			cout << endl;
		}
		break;

	case 4:
		cout << "�簢���� ���ο� ���θ� ������ �ֽʽÿ�." << endl <<
			"���� : ";
		cin >> width;	//�Է� ���� ���� ���� width���� ����

		cout << "���� : ";
		cin >> length;	//�Է� ���� ���� ���� length���� ����

		for (int i = 1; i <= length; i++) {	//length�� ��ŭ �ݺ�
			for (int ast = 1; ast <= width; ast++) { // width�� ���� '* '�� ���
				cout << "* ";
			}
			cout << endl;
		}
		cout << endl;
		break;
	}

	cout << endl << "ó������ ���ư��� �ٸ� ������ ���ðڽ��ϱ�?" << endl <<
		"[1]	��	[2]	�ƴϿ�" << endl;
	cin >> choice;	//ó������ ���ư��� �������� ����

	if (choice == 1) {	//�ܼ��� �����ϰ� ó������ ���� ��
		_sleep(500);
		system("cls");
		goto START;
	}
	else
	{
		//���α׷��� ������
	}

	return 0;
}