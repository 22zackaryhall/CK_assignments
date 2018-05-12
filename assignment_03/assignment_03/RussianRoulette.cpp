#include "Games.h"

int RussianRoullete() {
	//nPlayer == 게임 참가자 수  //nBullets == 장전된 탄환 수  //nCylinder == 최대 장탄수
	static int nPlayer = 0, nBullets = 0, nCylinder = 0;
	system("cls");
	cout << "[러시안 룰렛]" << endl << endl;
	printf("참가 인원 (예: 3) ==> ");
	scanf("%d", &nPlayer);
	printf("탄창의 최대 장탄수 (예: 6) == > ");
	scanf("%d", &nCylinder);
	while (true) {	//최대 장탄수 비례 총알 개수가 비정상적일 때 반복
		printf("장전할 총알 개수는? (예: 2) == > ");
		scanf("%d", &nBullets);
		if (nCylinder < nBullets) {	//총알이 최대 장탄수를 넘어간 경우
			printf("최대 장탄수%d보다 많은 총알(%d)을 장전할 수는 없습니다!\n", nCylinder, nBullets);
		}
		else if (nCylinder >= nBullets) {	//총알이 최대 장탄수보다 작을 경우
			system("cls");
			printf("참가 인원은 %d명 이며 최대 장탄수는 %d, 장전되어있는 총알은 %d발 입니다.\n", nPlayer, nCylinder, nBullets);

			break;
		}
	}
	srand((unsigned)time(NULL));	//시간을이용한 시드로 난수의 시작지점을 정함
	
	cout << "총은 준비되었습니다. 엔터(Enter)키를 누르면 시작합니다." << endl;
	getchar();

	printf("실린더를 돌렸습니다. 시작합니다.\n");

	static int DeathCount = 0;	//죽은 인수
	static int nTurn = 0;	//몇번째 발사
	while (true) {
		int pos = rand() % nCylinder;
		printf("[%d회]\t실린더를 돌렸습니다.\n",nTurn + 1);
		printf("\t엔터(Enter)키를 누르면 격발됩니다.\n");
		getchar();
		if (pos < nBullets) {
			printf("\t(탕!) 참가자가 사망했습니다.\n\n");
			DeathCount++;
			if (DeathCount >= nBullets) {	//사망자가 총알 개수보다 크거나 같을 경우
				break;
			}
		}
		else {
			printf("\t(틱)살았습니다.\n\n");
		}
		nTurn++;
	}

	printf("\n -----> %d명의 참가자가 사망하였습니다.\n", DeathCount);
	cout << "메인으로 돌아가시겠습니까?" << endl <<
		"[1] 예\n[2] 아니오\n";
	static int choice = 0;
	cin >> choice;

	switch (choice) {
	case 1: system("cls"); break;	//콘솔을 정리하고 본 함수에서 빠져나감
	case 2: exit(0);	//프로그램을 종료
	}


	return 0;

}