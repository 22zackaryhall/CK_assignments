#include <iostream>

using namespace std;

int main() {

	short innumber, cD1, cD2, cD3, rcD3, cD4, rcD4;
	bool restart;

start:
	innumber, cD1, cD2, cD3, rcD3, cD4, rcD4 = 0;
	restart = 0;
	
	cout << "<10000���� ���� ���� �Է¹޾Ƽ� �ڸ����� ������ ���α׷�>" << endl <<
		"ex) 9536�Է� -> õ�� �ڸ� 9, ���� �ڸ� 5, ���� �ڸ� 3, ���� �ڸ� 6" << endl <<
		"1~9999������ ���ڸ� �Է��Ͻʽÿ� : ";

	cin >> innumber;

	if ((innumber < 10000) && (innumber > 0)) {		//�Է��� 10000���� �۰� 0���� Ŭ�� ��� ����
		cout << "�Է¹��� ���� " << innumber << " �Դϴ�." << endl;

		cD4 = innumber / 1000;	// õ�� �ڸ����� ��� ���� �Է� ���� 1000�� ����
		rcD4 = innumber % 1000;
		cD3 = rcD4 / 100; // ���� �ڸ����� ��� ���� ���� ���� 100�� ����
		rcD3 = rcD4 % 100;
		cD2 = rcD3 / 10;	// ���� �ڸ����� ��� ���� ���� ���� 10�� ����
		cD1 = rcD3 % 10;	// ���� �ڸ����� ���� �� ���� ���� 1�� �ڸ����� 

		cout << "õ�� �ڸ��� : " << cD4 << endl <<
			"���� �ڸ��� : " << cD3 << endl <<
			"���� �ڸ��� : " << cD2 << endl <<
			"���� �ڸ��� : " << cD1 << endl;
	}
	else {		//�Է��� 1~9999 ������ ���� �ƴ� �� ����ó��
		cout << "�ùٸ��� ���� �Է��Դϴ�." << endl <<
			"ó������ ���ư��ϴ�." << endl;
		_sleep(1500);
		system("cls");
		goto start;
	}

	cout << "�ڸ��� ���ı⸦ ����� �Ͻ÷��� 1�� �Է��� �ֽʽÿ�." << endl;
	cin >> restart;
	
	if (restart == 1) {
		cout << "�ڸ��� ���ı⸦ ����� �մϴ�." << endl;
		_sleep(1500);
		system("cls");
		goto start;
	}
	else {
		cout << "�߸��� �Է��Դϴ�." << endl <<
			"���α׷��� �����մϴ�." << endl;
	}


	return 0;
}