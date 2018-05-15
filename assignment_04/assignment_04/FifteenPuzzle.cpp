#include "Ranking.h"
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

int playFifteenPuzzle();
static int DirKey[4] = { Left, Right, Up, Down };
static int map[5][5];	//������ �ִ� ũ�⸸ŭ �ʱⰪ ����
static int R_getDirKey[1000];	//���÷��� ����� ���� �÷��̸� �����ϱ� ���� �迭
static int ReplayShuffle[100];	//���÷��̿� ���� ���ð��� ������ �迭
static bool isReplay = false;	//���÷������� Ȯ���ϱ� ���� ����
static int x, y;		//��ĭ�� ��ġ
static int nMove;		//�̵� ȸ��
static int DIM = 5;		//���� ���ÿ� ���� ����� ������ ũ���� �ʱⰪ
static clock_t tStart;	//���� �ð�

//SetDIM = ������ ũ�⸦ �����ϱ� ���� �Լ�
int SetDIM() {

	int Choice = 0;

	cout << "���� ���� �����Դϴ�." << endl <<
		"���� ���� 3~5������ ���簢�� ������ ������ �ּ���." << endl << endl <<
		"[1] 3x3 ���� ����" << endl <<
		"[2] 4x4 ���� ����" << endl <<
		"[3] 5x5 ���� ����" << endl << 
		"[4] ���� �÷��̸� ��� (replay)" << endl << endl <<
		"���� : ";

	while (true) {

		cin >> Choice;

		switch (Choice) {
		case 1: return map[3][3], DIM = 3; break;
		case 2: return map[4][4], DIM = 4; break;
		case 3: return map[5][5], DIM = 5; break;
		case 4: return isReplay = true,
			DIM = loadReplayDIM("replay.replay"),
			map[DIM][DIM]; break;
		default: cout << "�ùٸ��� ���� �Է��Դϴ�. �� �Է� �ٶ��ϴ�.(1~4)" << endl;
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
	R_getDirKey[nMove] = dir;	//���÷���
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
				ReplayShuffle[i] = key;		// ���÷���
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
	printf("\n ������ �����ּ���(����)...");
	getche();
	shuffle(100);
	printf("\n ������ ���۵˴ϴ�...");
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
