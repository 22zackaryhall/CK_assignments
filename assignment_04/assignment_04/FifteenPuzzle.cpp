#include "Ranking.h"
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

static int map[5][5]; // ���� ū ��(5)�� �ʱⰪ�� �ž���;  
static int DIM = 5; //��������
static int RType = 1; //���÷��� ���� Ÿ��
static int DirKey[4] = { Left, Right, Up, Down };
static int x, y;
static int nMove;
static clock_t tStart;

void SetDim() { // �� ũ�⸦ �����ϴ� �Լ�
	int x;
	printf("���� ũ�⸦ �����ּ���(3,4,5) : ");

	while (true) {
		scanf("%d", &x);
		if (x == 3) { static int map[3][3]; DIM = 3; return; } //map�� ������;
		else if (x == 4) { static int map[4][4]; DIM = 4; return; }
		else if (x == 5) { static int map[5][5]; DIM = 5; return; }
		else printf("�߸��� �Է��Դϴ� �ٽ� �Է��ϼ���(3,4,5) : ");
	}
}

int ReplayType() {
	int x;
	printf("���÷��� ���� Ÿ���� �������ּ��� (1, 2) : ");
	x = getch();

	return x;
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
	printf("\n\t�̵� Ƚ��:%6d\n\t�ҿ� �ð�:%6.1f\n\n", nMove, d);
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
	init();
	display();
	printRanking();
	printf("\n ������ �����ּ���(����)...");
	getche();
	shuffle(100);
	printf("\n ������ ���۵˴ϴ�...");
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