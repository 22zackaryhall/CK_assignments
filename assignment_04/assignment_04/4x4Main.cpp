#include "Ranking.h"

extern int SetDIM();
extern int playFifteenPuzzle();



void main() {
	loadRanking("ranking.txt");
	SetDIM();	// ������ ũ�� ����
	int rank = playFifteenPuzzle();
//	printRanking();
//	storeRanking("ranking.txt");
}