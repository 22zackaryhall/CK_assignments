#include "SRPG.h"
#include "SRPG_characters.h"

char *pname = player.name;
char *ename = enemy.name;
short pHP = player.HP, pMHP = player.MAX_HP, pMP = player.MP, pMMP = player.MAX_MP, pSTR = player.strength, pAGL = player.agility, pDEF = player.defence, pLV = player.Level, pMEXP = player.MAX_Exp, pEXP = player.Exp;
bool pUnd = player.isUndead, pdead = player.dead, pCor = player.isCorrupted, ispDEFup = false;
short eHP = enemy.HP, eMHP = enemy.MAX_HP, eMP = enemy.MP, eMMP = enemy.MAX_MP, eSTR = enemy.strength, eAGL = enemy.agility, eDEF = enemy.defence, eEXP = enemy.Exp;
bool eUnd = enemy.isUndead, edead = enemy.dead, eCor = enemy.isCorrupted, iseDEFup = false;
bool turns = true;

void saveFile() {

	ofstream savefile("save.bin");

	if (savefile.good() == false) { cout << endl << "파일 저장에 실패하였습니다" << endl; return; }

	savefile << pname << " " << pMHP << " " << pHP << " " << pMMP << " " << pMP << " " << pSTR << " " << pAGL << " " << pDEF << " " << pLV << " " << pMEXP << " " << pEXP << " " << pUnd << " " << pdead << " " << pCor << " " << ispDEFup;
	cout << endl << "저장이 정상적으로 완료되었습니다." << endl;
	savefile.close();

}

void loadFile() {

	system("cls");

	ifstream savefile("save.bin");

	if (savefile.good() == false) { cout << endl << "파일 불러오기에 실패하였습니다" << endl; return; }

	savefile >> pname >> pMHP >> pHP >> pMMP >> pMP >> pSTR >> pAGL >> pDEF >> pLV >> pMEXP >> pEXP >> pUnd >> pdead >> pCor >> ispDEFup;

	cout << endl << "로드된 세이브 파일" << endl <<
		"AI - " << pname << endl <<
		"LV - " << pLV << endl <<
		"HP - " << pHP << "/" << pMHP << endl <<
		"MP - " << pMP << "/" << pMMP << endl <<
		"STR - " << pSTR << endl <<
		"AGL - " << pAGL << endl <<
		"DEF - " << pDEF << endl <<
		"Exp - " << pEXP << "/" << pMEXP << endl;
	
	savefile.close();

	cout << endl << "엔터(Enter)키 를 누르면 진행합니다." << endl;
	getch();
	rewind(stdin);

}

void PlayerReset() {

	pname = player.name;
	pMHP = player.MAX_HP;
	pHP = player.HP;
	pMMP = player.MAX_MP;
	pMP = player.MP;
	pMEXP = player.MAX_Exp;
	pEXP = player.Exp;
	pSTR = player.strength;
	pAGL = player.agility;
	pDEF = player.defence;
	pLV = player.Level;
	pUnd = player.isUndead;
	pdead = player.dead;
	pCor = player.isCorrupted;

}

void attackerReset() {

	ename = "어태커";
	eMHP = 60;
	eHP = 60;
	eMMP = 20;
	eMP = 20;
	eSTR = 5;
	eAGL = 5;
	eDEF = 4;
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