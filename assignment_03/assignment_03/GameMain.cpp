#include "Games.h"

using namespace std;

int main() {

	while (true) {
		int choice = 0;

		cout << "[���� ����]\n[1] ���þ� �귿\n[2] ��� ����\n[3] 369����\n" <<
			"�� ������ ��ȣ : ";
		cin >> choice;

		switch (choice) {
		case 1: RussianRoullete(); break;
		case 2: CalculationGame(); break;
		case 3: Game369WC(); break;
		}


	}
	return 0;

}