#include "Ranking.h"

#define Replays 1

static s_Replay nReplay[Replays];
static int nReplays = Replays;
static int gDK = 0, RS = 0, DIM = 0;

/*
void loadReplay(char* fname) {
	ifstream R_fin;
	R_fin.open(fname);
	if (R_fin.good() == false) {}
	else {
		for (int i = 0; i < nReplays; i++) {
			R_fin >> nReplay[i].R_getDirKey[i] >>
				nReplay[i].ReplayShuffle[i] >>
				nReplay[0].R_DIM;
		}
		R_fin.close();
	}
}
*/
int loadReplayDIM(char* fname) {
	int out = 0;
	ifstream R_fin;
	R_fin.open(fname);
	if (R_fin.good() == false) {}
	else {
		R_fin >> nReplay[0].R_DIM;
		out = nReplay[0].R_DIM;
		}
		R_fin.close();

		return out;
	}

int loadReplayShuffle(char* fname, int i) {
	int out[100];
	ifstream R_fin;
	R_fin.open(fname);
	if (R_fin.good() == false) {}
	else {
		for (int j = 0; j <= 100; j++) {
			R_fin >> nReplay[i].R_DIM;
			out[i] = nReplay[i].R_DIM;
		}
	}
	R_fin.close();

	return out[i];
}

void storeReplay(char* fname, int R_DIM, int R_getDirKey[], int ReplayShuffle[]) {
	ofstream R_fout;
	R_fout.open(fname);
	if (R_fout.good() == false) return;
	R_fout << nReplay[0].R_DIM << R_DIM << setw(1) << endl;
	for (int i = 0; i < nReplays; i++) {

		R_fout << "  " << left << setw(4) <<
			nReplay[i].R_getDirKey[i] << R_getDirKey << "  " << setw(5) <<
			nReplay[i].ReplayShuffle[i] << ReplayShuffle << setw(5) << endl;
	}
	R_fout.close();
}