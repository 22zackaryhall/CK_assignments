#include <iostream>
#include <cmath>		//��������� ���� ������ ���� �����Լ��� �ҷ���.
#define Pi 3.141592		//�������� ����� ����.

using namespace std;

int main() {

	float radius, rsquare, diameter, circumference, Area;

start:		//���α׷� ������ �������� ���ƿ� ���� ������

	radius, rsquare, diameter, circumference, Area = 0;

	cout << "<���� �ѷ��� ������ ���ϴ� ���α׷�>" << endl << endl;
	cout << "���� �������� �Է��Ͽ� �ּ��� : ";
	cin >> radius;

	if (radius <= 0) {		//�Է¹��� �������� ���� 0�� ���ų� ������ ����ó��.
		cout << "1 �̻��� ���� �Է��Ͽ� �ֽʽÿ�." << endl;
		_sleep(1500);		//�ȳ��� ȭ�鿡 ��� �� 1500ms�� �������Ѽ� Ȯ�ν�Ŵ.
		system("cls");		//ó������ ���ư��� �� �ܼ��� ���� �����Ͽ� ����ϰ� ��.
		goto start;		//ó������ ���ư�
	}

	else (radius > 0); {		//�Է¹��� �������� ���� 0���� ũ�� ������
		cout << "�Է¹��� ���� �������� '" << radius << "' �Դϴ�." << endl;

		rsquare = pow(radius, 2);		// �������� 2������ �����Լ�(pow)�� ���
		diameter = radius * 2.0;		// ���� = ������ * 2
		circumference = diameter * Pi;	// �ѷ� = ���� * ������
		Area = Pi * rsquare;			// ���� = ������ * �������� 2����

		cout << "���� ����: " << diameter << endl <<
			"���� �ѷ�: " << circumference<< endl <<
			"���� ����: " << Area << endl;				//����� ���� ������ ȭ�鿡 ���
	}


	return 0;
}