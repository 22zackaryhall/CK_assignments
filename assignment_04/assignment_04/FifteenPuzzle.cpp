#include "Ranking.h"
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

int playFifteenPuzzle();
static int DirKey[4] = { Left, Right, Up, Down };
static int map[5][5];	//퍼즐의 최대 크기만큼 초기값 선언
static int R_getDirKey[1000];	//리플레이 재생을 위해 플레이를 저장하기 위한 배열
static int ReplayShuffle[100];	//리플레이에 사용될 셔플값을 저장할 배열
static bool isReplay = false;	//리플레이인지 확인하기 위한 변수
static int x, y;		//빈칸의 위치
static int nMove;		//이동 회수
static int DIM = 5;		//이후 선택에 의해 변경될 퍼즐의 크기의 초기값
static clock_t tStart;	//시작 시간

//SetDIM = 퍼즐의 크기를 지정하기 위한 함수
int SetDIM() {

	int Choice = 0;

	cout << "숫자 퍼즐 게임입니다." << endl <<
		"가로 세로 3~5까지의 정사각형 퍼즐을 선택해 주세요." << endl << endl <<
		"[1] 3x3 숫자 퍼즐" << endl <<
		"[2] 4x4 숫자 퍼즐" << endl <<
		"[3] 5x5 숫자 퍼즐" << endl << 
		"[4] 이전 플레이를 재생 (replay)" << endl << endl <<
		"선택 : ";

	while (true) {

		cin >> Choice;

		switch (Choice) {
		case 1: return map[3][3], DIM = 3; break;
		case 2: return map[4][4], DIM = 4; break;
		case 3: return map[5][5], DIM = 5; break;
		case 4: return isReplay = true,
			DIM = loadReplayDIM("replay.replay"),
			map[DIM][DIM]; break;
		default: cout << "올바르지 않은 입력입니다. 재 입력 바랍니다.(1~4)" << endl;
		}

	}

	return 0;

}

void init() {
	for (int i = 0; i < DIM*DIM; i++) {
		map[i / DIM][i % DIM] = i + 1;
	}
	map[DIM - 1][DIM - 1] = 0;
	x = DIM - 1; y = DIM - 1;

	srand(time(NULL));
	tStart = clock();
	nMove = 0;
}

static void display() {
	system("cls");
	printf("\tFifteen Puzzle\n\t");
	printf("---------------\n\t");
	for (int r = 0; r < DIM; r++) {
		for (int c = 0; c < DIM; c++) {
			if (map[r][c] > 0) {
				printf("%3d", map[r][c]);
			}
			else { printf("   "); }
		}
		printf("\n\t");
	}
	printf("---------------\n\t");
	clock_t t1 = clock();
	double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
	printf("\n\t이동 횟수:%6d\n\t소요 시간:%6.1f\n\n", nMove, d);
}

static bool move(int dir) {
	if (dir == Right && x > 0) {
		map[y][x] = map[y][x - 1];
		map[y][--x] = 0;
	}
	else if (dir == Left && x < DIM-1) {
		map[y][x] = map[y][x + 1];
		map[y][++x] = 0;
	}
	else if (dir == Up && y < DIM-1) {
		map[y][x] = map[y + 1][x];
		map[++y][x] = 0;
	}
	else if (dir == Down && y > 0) {
		map[y][x] = map[y - 1][x];
		map[--y][x] = 0;
	}
	else {
		return false;
	}
	
	nMove++;
	R_getDirKey[nMove] = dir;	//리플레이
	return true;
}

static void shuffle(int nShuffle) {

	int key;

	for (int i = 0; i < nShuffle; i++) {
		if (isReplay == false )
		{ 
			key = DirKey[rand() % 4];

			if (move(key) == false) {
				i--;
				continue;
			}
			else {
				ReplayShuffle[i] = key;		// 리플레이
			}
		}
		else // (isReplay != false)
		{
			ifstream R_fin;
			R_fin.open("replay.replay");
			if (R_fin.good() == false) {}
			else {
				for (int i = 0; i <= nShuffle; i++) {
					key = loadReplayShuffle("replay.replay",i);
				}
			}
			R_fin.close();
		}
		display();
		Sleep(50);
	}
}

static bool isDone() {
	for (int r = 0; r < DIM; r++) {
		for (int c = 0; c < DIM; c++) {
			if (map[r][c] != r * DIM + c + 1) {
				return (r == DIM - 1) && (c == DIM - 1);
			}
		}
	}
	return true;
}

static int getDirKey() {
	return getche() == 224 ? getche() : 0; 
}

int playFifteenPuzzle() {
	init();
	display();
	printRanking();
	printf("\n 퍼즐을 섞어주세요(엔터)...");
	getche();
	shuffle(100);
	printf("\n 게임이 시작됩니다...");
	getche();

	nMove = 0;
	tStart = clock();

	if (isReplay == false) {
		while (!isDone()) {
			move(getDirKey());
			display();
		}
	}
	else {
		int i = 0;
		while (!isDone()) {
			move(R_getDirKey[i]);
			display();
			i++;
		}
	}
	if (isReplay == true) {
		storeReplay("replay.replay", DIM, R_getDirKey, ReplayShuffle);
	}
	else {
		printRanking();
		storeRanking("ranking.txt");
	}

		clock_t t1 = clock();
		double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
		return addRanking(nMove, d);
}
