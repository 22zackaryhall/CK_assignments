#include "Ranking.h"

extern int SetDIM();
extern int playFifteenPuzzle();



void main() {
	loadRanking("ranking.txt");
	SetDIM();	// 퍼즐의 크기 선택
	int rank = playFifteenPuzzle();
//	printRanking();
//	storeRanking("ranking.txt");
}