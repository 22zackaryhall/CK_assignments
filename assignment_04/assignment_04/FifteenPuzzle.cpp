#include "Ranking.h"
#include "replay.h"
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

static int map[5][5]; // 가장 큰 값(5)이 초기값이 돼야함;  
static int DIM = 5; //마찬가지
static int DirKey[4] = { Left, Right, Up, Down };
static int x, y;
static int nMove;
static char Record[301]; //replay.txt 파일의 크기를 최소화 할 목적이 있음
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

void SetDim() { // 맵 크기를 설정하는 함수
	char x;
	printf("맵의 크기를 정해주세요(2,3,4,5) : ");

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
	char x;
	if (dir == Right) x = '1'; //값 변환
	else if (dir == Left) x = '2';
	else if (dir == Up) x = '3';
	else x = '4';
	strcat(Record, );
	Record[nMove] = x;
	nMove++;
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
	if (IsRePlay()) { 
		showRanking();
		return 0;
	}
	init();
	display();
	printRanking();
	printf("\n 퍼즐을 섞어주세요(엔터)...");
	getche();
	shuffle(10);
	printf("\n 게임이 시작됩니다...");
	getche();

	nMove = 0;
	tStart = clock();
	while (!isDone()) {
		move(getDirKey());
		display();
	}
	clock_t t1 = clock();
	double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
	return addRanking(nMove, d);
}