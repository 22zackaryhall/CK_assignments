#include "Ranking.h"

extern int SetDIM();
extern int playFifteenPuzzle();

void main() {
	loadRanking("ranking.txt");
	SetDIM();
	int rank = playFifteenPuzzle();
	printRanking();
	storeRanking("ranking.txt");
}