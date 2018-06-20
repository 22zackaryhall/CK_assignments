#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <fstream>

//#define DEBUG
#define RELEASE

#define DEFup 4

using namespace std;

extern void main();
extern int SRPG_page1();
extern void SRPG_Credits();
extern int SRPG_Prologue();
extern int SRPG_1st_sence();
extern int SRPG_2nd_sence();
extern int getNums(const int MAX);
extern char getName();
extern void isCorrupted(bool in);
extern void Battle();
extern void CORDLINEEND();
extern void LfABaseFirst();
extern void LfABase(bool isLoad);
extern void walking(short Distance, short howmany);
extern void gameOver();
extern void printpStatus();
extern void saveFile();
extern void loadFile();

extern void PlayerReset();
extern void tt1Reset();
extern void tt2Reset();
extern void attackerReset();