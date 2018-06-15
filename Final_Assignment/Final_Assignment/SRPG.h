#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <iomanip>

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

struct LifeEntity {
	
	char name[16];

	//게이지
	short MAX_HP = 100;
	short HP = 100;
	short MAX_MP = 20;
	short MP = 20;
	short MAX_Exp = 20;
	short Exp = 0;

	//스텟
	short strength = 5;
	short agility = 3;
	short defence = 2;

	//소속 및 상태
	bool isUndead = false;
	bool dead = false;
	bool isCorrupted = false;
};

typedef LifeEntity Player;
typedef LifeEntity Enemy;