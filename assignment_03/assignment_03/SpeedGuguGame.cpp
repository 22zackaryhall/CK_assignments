#include "Games.h"

void Gugu() {
	srand((unsigned)time(NULL));	//난수 시작지점을 시간을 이용한 시드로 정함
	extern int cChoice;	//cChoice를 불러와서 사용
	int choice = 0;
	while (true) {
		int nPlay = 10;	//최대 게임 횟수
		switch (cChoice)
		{
		case 1: printf("[스피드 구구단]\n"); break;
		case 2: printf("[두 자리 수 곱셈]\n"); break;
		case 3: printf("[%d 자리수 덧셈]\n", cChoice); break;
		case 4: printf("[%d 자리수 덧셈]\n", cChoice); break;
		case 5: printf("[%d 자리수 덧셈]\n", cChoice); break;
		case 6: printf("[%d 자리수 덧셈]\n", cChoice); break;
		case 7: printf("[%d 자리수 덧셈]\n", cChoice); break;
		case 8: printf("[%d 자리수 덧셈]\n", cChoice); break;
		case 9: printf("[%d 자리수 덧셈]\n", cChoice); break;
		}
		cout << "당신의 연산능력은 어느정도 입니까?" << endl <<
			"게임은 총 10번 진행됩니다." << endl <<
			"준비가 되시면 엔터(Enter)키를 누르세요!" << endl;
		getchar();
		getchar();
		system("cls");
		double score = 0;
		if (cChoice == 1 || cChoice == 2) {	//1~2를 선택했을 경우 곱셈
			score = playSpeedGugu(nPlay);
		}
		else if (cChoice >= 3 && cChoice <= 9) {	//3~9를 선택했을 경우 덧셈
			score = playdigit3t9add(nPlay);
		}
		printf("\n점수 = %4.1f점(총 %4.1f초)\n\n", score, tElapsed);
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

	}

}