#include "Ranking.h"
#include "replay.h"
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define MAXTURN 500 //리플레이 최대저장 턴

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

static int map[5][5]; // 가장 큰 값(5)이 초기값이 돼야함;  
static int DIM = 5; //마찬가지
static int DirKey[4] = { Left, Right, Up, Down };
static int RType = 1;
static int x, y;
static int nMove;
static bool IsReady = false;
static char Record1[MAXTURN + 1]; //replay.txt 파일의 크기를 최소화 할 목적이 있음
static char Record2[MAXTURN][25]; //이건 그런거 없다
static clock_t tStart;

bool IsRePlay() {
	char x;
	printf("리플레이를 보시겠습니까? (y,n)\n");

	while (true) {
		x = getch();
		if (x == 'y') return true;
		else if (x == 'n') return false;
 	}
}

int SetSaveType() {
	char x;
	printf("리플레이 저장 타입을 골라주세요 (1, 2)\n");

	while (true) {
		x = getch();
		if (x == 49) return 1;
		else if (x == 50) return 2;
	}
}

void SetDim() { // 맵 크기를 설정하는 함수
	char x;
	printf("맵의 크기를 정해주세요 (2,3,4,5) : ");

	while (true) {
		x = getche();
		if (x == 50) { static int map[2][2]; DIM = 2; return; } //map을 재정의;
		else if (x == 51) { static int map[3][3]; DIM = 3; return; } 
		else if (x == 52) { static int map[4][4]; DIM = 4; return; }
		else if (x == 53) { static int map[5][5]; DIM = 5; return; }
		else printf("\n잘못된 입력입니다 다시 입력하세요(2,3,4,5) : ");
	}
}

void init() {

	SetDim();

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
	printf("\n\tFifteen Puzzle\n\t");
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

static void record(int dir) { 
	if (IsReady) { //셔플중에 데이터가 저장되는것 방지
		Record1[nMove] = dir; //방향키 저장(저장 타입1)
		for (int i = 0; i < DIM; i++) { //맵저장 (저장 타입2) 
			for (int j = 0; j < DIM; j++) {
				Record2[nMove][DIM * i + j] = map[i][j];
			}
		}
	}

	nMove++;
}

static void ReplayMode() { //게임이 끝난 직후의 리플레이
	int turn = 0, Rmap[5][5];
	static int maxturn = MAXTURN;
	char input;

	if (Record1[0] != 0) { //방향키 저장(저장 타입1)
		for (int i = 0; i < MAXTURN; i++) { //최대턴을 구하는 함수
			if (Record1[i] == 0) {
				maxturn = i - 1;
				break;
			}
		}

		for (int i = 0; i < DIM*DIM; i++) {
			Rmap[i / DIM][i % DIM] = i + 1;
		}
		Rmap[DIM - 1][DIM - 1] = 0;
		x = DIM - 1; y = DIM - 1;

		do {
			system("cls");
			for (int i = maxturn; i > turn; i--) {
				printf("for\n");
				if (Record1[i] == Right && x < DIM - 1) {	 //키가 오른쪽이면
					Rmap[y][x] = Rmap[y][x + 1];			 //왼쪽으로 이동
					Rmap[y][++x] = 0;
					printf("RIGHT\n");
				}
				else if (Record1[i] == Left && x > 0) {
					Rmap[y][x] = Rmap[y][x - 1];
					Rmap[y][--x] = 0;
					printf("LEFT\n");
				}
				else if (Record1[i] == Up && y > 0) {
					Rmap[y][x] = Rmap[y - 1][x];
					Rmap[--y][x] = 0;
					printf("UP\n");
				}
				else if (Record1[i] == Down && y < DIM - 1) {
					Rmap[y][x] = Rmap[y + 1][x];
					Rmap[++y][x] = 0;
					printf("DOWN\n");
				}
			}
			printf("\n\t Replay Mode 1\n\t");
			printf("---------------\n\t");
			for (int r = 0; r < DIM; r++) {
				for (int c = 0; c < DIM; c++) {
					if (Rmap[r][c] > 0) {
						printf("%3d", Rmap[r][c]);
					}
					else { printf("   "); }
				}
				printf("\n\t");
			}
			printf("---------------\n\t");
			printf("\n[%d / %d]\n종료하려면 q를 입력하세요", turn, maxturn);

			input = getch();
			if (input == 75 && turn > 0) turn--;
			else if (input == 77 && turn < maxturn) turn++;

		} while (input != 113 || input != NULL);
	}
	else { //맵저장 (저장 타입2) 
		for (int i = 0; i < MAXTURN; i++) {
			if (Record2[i][0] == 0 && Record2[i][1] == 0) { // 데이터가 없는 배열(int형)안엔 초기화 되지 않은값(0)이 들어있다.
				maxturn = i - 1;
				break;
			}
		}

		do {
			system("cls");
			printf("\n\t Replay Mode 2\n\t");
			printf("---------------\n\t");
			for (int i = 0; i < DIM; i++) {
				for (int j = 0; j < DIM; j++) {
					Rmap[i][j] = Record2[turn][DIM * i + j];
				}
			}
			for (int r = 0; r < DIM; r++) {
				for (int c = 0; c < DIM; c++) {
					if (Rmap[r][c] > 0) {
						printf("%3d", Rmap[r][c]);
					}
					else { printf("   "); }
				}
				printf("\n\t");
			}
			printf("---------------\n\t");
			printf("\n[%d / %d]\n종료하려면 q를 입력하세요", turn, maxturn);

			input = getch();
			if (input == 75 && turn > 0) turn--;
			else if (input == 77 && turn < maxturn) turn++;

		} while (input != 113 || input != NULL);
	}
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
	else if (dir == 1); // 그냥 통과(첫턴 저장용)
	else {
		return false;
	}

	record(dir);
	return true;
}

static void shuffle(int nShuffle) {
	for (int i = 0; i < nShuffle; i++) {
		int key = DirKey[rand() % 4];
		if (move(key) == false) {
			i--;
			continue;
		}
		display();
		Sleep(5);
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
	/*if (IsRePlay()) {
		showRanking();
		return 0;
	}
	else SetSaveType();*/
	init();
	display();
	printRanking();
	printf("\n 퍼즐을 섞어주세요(엔터)...");
	getche();
	shuffle(3);
	printf("\n 게임이 시작됩니다...");
	getche();

	nMove = 0;
	IsReady = true;
	record(1);
	tStart = clock();
	while (!isDone()) {
		move(getDirKey());
		display();
	}
	clock_t t1 = clock();
	double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
	if (IsRePlay()) {
		ReplayMode();
	}
	return addRanking(nMove, d);
}