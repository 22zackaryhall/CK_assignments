#include "Games.h"

using namespace std;

int main() {

	while (true) {
		int choice = 0;

		cout << "[게임 모음]\n[1] 러시안 룰렛\n[2] 계산 게임\n[3] 369게임\n" <<
			"할 게임의 번호 : ";
		cin >> choice;

		switch (choice) {
		case 1: RussianRoullete(); break;
		case 2: CalculationGame(); break;
		case 3: Game369WC(); break;
		}


	}
	return 0;

}