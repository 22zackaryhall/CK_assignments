#include "Games.h"

int cChoice = 0;

int CalculationGame() {
	
	system("cls");

	cout << "[������ ����Ʈ]" << endl <<
		"[1] ���ǵ� ������" << endl <<
		"[2] 2�ڸ��� ����" << endl <<
		"[3~9] 3~9�ڸ� ���� " << endl << endl <<
		"�ϰ���� ������ ��ȣ: ";

		cin >> cChoice;

		if (cChoice >= 1 && cChoice <= 9) {
			system("cls"); Gugu();
		}
		else {	//������ �ùٸ��� ���� ��� ����
			cout << "�ùٸ��� ���� �Է��Դϴ�." << endl <<
				"���α׷��� �����մϴ�." << endl;
			_sleep(1500);
			exit(1);
		}

	return 0;
}