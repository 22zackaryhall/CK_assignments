#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <fstream>
//#include "SRPG_characters.h"
#define DEBUG

enum lvl {l1 = 20, l2 = 50, l3 = 100, l4 = 150, l5 = 200, l6 = 250, l7 = 300, l8 = 350, l9 = 400, lA = 500 };

using namespace std;

extern void main();
extern int SRPG_page1();
extern void SRPG_Credits();
extern int SRPG_Prologue();
extern int SRPG_1st_sence();
extern int SRPG_2nd_sence();
extern int getNums(const int MAX);
extern void isCorrupted(bool in);
extern void Battle();
extern void CORDLINEEND();
extern void LfABaseFirst();
extern void LfABase(bool isLoad);
extern void walking(short Distance, short howmany);

extern void saveFile();
extern void loadFile();

extern void PlayerReset();
extern void tt1Reset();
extern void tt2Reset();
extern void attackerReset();

//void enemyReset();