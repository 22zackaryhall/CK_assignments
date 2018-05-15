#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct PlayInfo {
	char	name[200];
	int		nMove;
	double	tElapsed;
};

struct s_Replay {
	int		R_DIM;
	int		R_getDirKey[1000];
	int		ReplayShuffle[100];
//	int		R_Turns;
//	int		Ri;
};

extern void loadRanking(char* filename);
extern void storeRanking(char* filename);
extern void printRanking();
extern int addRanking(int nMove, double tElap);
extern int loadReplayDIM(char* fname);
extern int loadReplayShuffle(char* fname,int i);
extern void storeReplay(char* fname, int R_DIM, int R_getDirKey[], int ReplayShuffle[]);