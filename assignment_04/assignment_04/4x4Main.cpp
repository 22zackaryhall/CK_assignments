#include "Ranking.h"
#include "replay.h"

extern int playFifteenPuzzle();

void main() {
	loadRanking("ranking.txt");
	//loadReplay("replay.txt");
	int rank = playFifteenPuzzle();
	printRanking();
	storeRanking("ranking.txt");
}