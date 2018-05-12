#include "Games.h"

bool is369(int aa);		// 3,6,9일때
int digit_num(int aa);	// 자리수
int count369(int aa);	// 3,6,9가 몇개인가
int asts(int aa);	// * 의 개수
static int i = 1, in = 0, j = 0, iAstIn = 0, ast = 0, AstC = 1, tns = 0;
char astIn;	//플레이어의 턴일때 3,6,9 대신 *을 입력

int Game369WC() {
	while (true) {
		system("cls");

		cout << "[컴퓨터와 하는 369게임]" << endl <<
			"준비가 되시면 엔터(Enter)키를 누르세요!" << endl <<
			"1부터 시작합니다! 3,6,9가 포함되면 개수만큼 * 를 입력하세요!" << endl <<
			"틀리면 게임이 끝납니다!" << endl;
		getchar();
		static int turns = 0;	//게임의 턴 카운트
		int Missed = 0;	//틀렸는지 판단하기 위한 변수

		while (true) {

			tns = count369(i);
			turns++;

			if (tns == 0) {	// 3,6,9가 들어가지 않을 때
				if (turns % 2 == 0) {	// 턴이 짝수일 경우 COM이 진행
					printf("[%3d회]COM\t: %d\n", turns, i);
				}
				else {	//턴이 홀수일 경우 플레이어가 진행
					printf("[%3d회]YOU\t: ", turns);
					scanf("%d", &in);
					if (in != i) {	//답이 틀렸을 경우 게임 끝
						Missed++;
						break;
					}
					else {
					}
				}
			}
			else if (tns >= 1) {	// 3,6,9가 들어갈 때
				if (turns % 2 == 0) {
					printf("[%3d회]COM\t: ", turns);
					for (j = 0; j < tns; j++) {
						cout << "*";
						AstC++;
					}
					cout << "\n";
				}
				else {
					printf("[%3d회]YOU\t: ", turns);
					cin >> astIn;
					if (iAstIn == '*') {
						iAstIn = ((astIn - '0') / 42);
					//*의 ASCII값인 42를 사용
					}
					else {
						iAstIn = ((astIn - '0')*2 / 42);
					}

					ast = ('*' - '0');

					if (iAstIn != asts(tns)) {
						Missed++;
						break;
					}
					else {
					}
					iAstIn = 0;

				}

			}
			i++;
		}
		int choice = 0;
		printf("\n틀렸습니다.\n");
		printf("총 %d회 진행되었습니다.\n\n", turns);
		cout << "다시 하겠습니까?" << endl <<
			"[1] 예" << endl <<
			"[2] 메인으로" << endl <<
			"[3] 게임을 종료" << endl;
		cin >> choice;

		if (choice == 2) {
			system("cls");
			break;
		}
		else if (choice == 3) {
			exit(0);
		}
		else {
			system("cls");
		}
		turns = 0, i = 1, in = 0, j = 0, iAstIn = 0, ast = 0, AstC = 1;
	}
	return 0;
}

bool is369(int aa) {

	bool isr369 = false;

	if ((aa != 0) && (aa % 3 == 0)) {
		isr369 = true;
	}


	return isr369;
}

int digit_num(int aa) {

	int num = 0;

	while (aa != 0) {
		num++;
		aa /= 10;
	}

	return num;
}

int count369(int aa) {

	int tmp = aa;
	int num = 0;
	int digit = digit_num(aa);

	for (int i = 0; i < digit; i++) {
		if (is369(tmp % 10)) {
			num++;
		}
		tmp /= 10;
	}


	return num;

}

int asts(int aa) {
	
	int Asts = 0;

		Asts += (('*' - '0') * aa / 42);

	return Asts;
}