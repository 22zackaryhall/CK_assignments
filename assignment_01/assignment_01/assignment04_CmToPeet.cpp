#include <iostream>
#include <cmath>		// double���� �������� ���ϱ� ���� �����Լ��� ���

using namespace std;


int main() {

	double cm, feet, inch, rinch, fti;
	int manswer, ianswer01, ianswer02;
Main:
	cm, feet, inch, rinch, fti = 0;
	manswer, ianswer01, ianswer02 = 0;

	system("cls");
	cout << "<cm <=> feet,inch ��ȯ ���α׷�>" << endl <<
		"[���� ��ȯ���� ����Ͻðڽ��ϱ�?]" << endl <<
		"[1] cm \t\t=> feet,inch" << endl <<
		"[2] feet,inch\t=> cm" << endl;
	cin >> manswer;		// �ռ� ��µ� ��ȯ�� �� �� �ϳ��� ��ȣ�� �Է��ϸ� manswer ���� ����

	if (manswer == 1) {	// manswer���� 1�� �Է¹����� cm -> feet, inch ��ȯ���� ����
	CMtFI:
		rinch, feet, inch = 0;

		system("cls");
		cout << "[cm => feet,inch ��ȯ]" << endl <<
			"��ȯ�� cm : ";
		cin >> cm;
		rinch = cm / 2.54;	// 2.54cm = 1inch �̹Ƿ� cm�� 2.54�� ������ rinch���� ��
		feet = rinch / 12;	// 12inch�� 1feet�̹Ƿ� rinch���� 12�� ������ feet���� ����
		inch = fmod(rinch, 12.00);	// feet�� ����� �� ���� ���� inch �̹Ƿ� rinch���� 12�� �������� ���ϸ� inch���� ����
		
		
		cout.precision(2);	// �Ҽ��� 1�ڸ������� ǥ��
		cout << (int)feet << " feet " << inch << " inch �Դϴ�." << endl << endl <<
			"[1] �ٽ� ��ȯ�ϱ�" << endl <<
			"[2] �������� ���ư���" << endl;

		rinch = 0;

		cin >> ianswer01;	// ��ȯ�� �ٽ� �������� ó������ ���ư��� ������ ���� ianswer01�� ����
		if (ianswer01 == 1) {
			ianswer01 = 0;
			goto CMtFI;	// ianswer01�� 1�� �ԷµǸ� cm -> feet, inch ��ȯ ������������ ��
		}
		else {
			goto Main; // ianswer01�� 1�� �ƴ� ���� �ԷµǸ� ó�� ȭ������ ���ư�
		}
		
	}
	else if (manswer == 2){	// manswer ���� 2�� �Է¹޾��� ��� feet, inch -> cm ��ȯ���� ����
	FItCM:
		feet, inch, cm = 0;

		system("cls");
		cout << "[feet,inch => cm ��ȯ]" << endl <<
			"��ȯ�� feet : ";
		cin >> feet;
		cout << "��ȯ�� inch : ";
		cin >> inch;

		cm = feet * 30.48 + inch * 2.54;	//1feet�� 30.48cm�� ���� 1inch�� 2.54cm�� ����

		cout << endl << cm << "cm �Դϴ�." << endl <<
			"[1] �ٽ� ��ȯ�ϱ�" << endl <<
			"[2] �������� ���ư���" << endl;

		cin >> ianswer02;	// ��ȯ�� �ٽ� �������� ó������ ���ư��� ������ ���� ianswer02�� ����
		if (ianswer02 == 1) {
			ianswer02 = 0;
			goto FItCM;	// ianswer02�� 1�� �ԷµǸ� feet, inch -> cm ��ȯ ������������ ��
		}
		else {
			goto Main;	// ianswer02�� 1�� �ƴ� ���� �ԷµǸ� ó�� ȭ������ ���ư�
		}

	}
	else {	// manswer ���� 1�� 2 �̿��� ���� �Է¹����� ����ó�� �� ó������ ���ư�
		cout << "�ùٸ� ������ �ƴմϴ�." << endl;
		_sleep(1500);
		goto Main;
	}


	return 0;
}