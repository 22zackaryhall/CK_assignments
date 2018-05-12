#include "Games.h"

int cChoice = 0;

int CalculationGame() {
	
	system("cls");

	cout << "[계산게임 리스트]" << endl <<
		"[1] 스피드 구구단" << endl <<
		"[2] 2자리수 곱셈" << endl <<
		"[3~9] 3~9자리 덧셈 " << endl << endl <<
		"하고싶은 게임의 번호: ";

		cin >> cChoice;

		if (cChoice >= 1 && cChoice <= 9) {
			system("cls"); Gugu();
		}
		else {	//선택이 올바르지 않을 경우 종료
			cout << "올바르지 않은 입력입니다." << endl <<
				"프로그램을 종료합니다." << endl;
			_sleep(1500);
			exit(1);
		}

	return 0;
}