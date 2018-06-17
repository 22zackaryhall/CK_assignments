#include "SRPG.h"
#include "SRPG_characters.h"

extern char 
*ename;
extern short 
eMHP, 
eHP, 
eMMP, 
eMP, 
eSTR, 
eAGL, 
eDEF,
eEXP;
extern bool
eUnd,
edead,
eCor,
turns;

void attackerReset() {

	ename = "어태커";
	eMHP = 60;
	eHP = 60;
	eMMP = 20;
	eMP = 20;
	eSTR = 5;
	eAGL = 5;
	eDEF = 3;
	eUnd = false;
	edead = false;
	eCor = false;
	eEXP = 50;
	turns = false;

}

void tt2Reset() {

	ename = "공격적 기계";
	eMHP = 30;
	eHP = 30;
	eMMP = 10;
	eMP = 10;
	eSTR = 3;
	eAGL = 3;
	eDEF = 2;
	eUnd = false;
	edead = false;
	eCor = false;
	eEXP = 20;
	turns = true;

}

void tt1Reset() {

	ename = "적대적 기계";
	eMHP = 20;
	eHP = 20;
	eMMP = 10;
	eMP = 10;
	eSTR = 2;
	eAGL = 2;
	eDEF = 1;
	eUnd = false;
	edead = false;
	eCor = false;
	eEXP = 20;
	turns = true;

}