#include "replay.h"
#include "Ranking.h"
#include <conio.h>

#define NUM_RP 5

static int nRP = NUM_RP;

void showRanking() {
	system("cls");
	printRanking();
	printf("리플레이를 볼 순위을 선택해주세요(1~5) : ");
	getche();
}

void loadReplay(char* fname) {
	ifstream fin;
	fin.open(fname);
	if (!fin.good()) {
		cout << "리플레이 데이터가 없습니다.";
		return;
	}
	else {
		for (int i = 0; i < nRP; i++) {
			//fin >> MVP[i].nMove >> MVP[i].name >> MVP[i].tElapsed;
		}
		fin.close();
	}
}

