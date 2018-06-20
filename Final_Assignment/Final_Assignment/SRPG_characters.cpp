#include "SRPG.h"
#include "SRPG_characters.h"

//����ü�� �⺻������ �ҽ����Ͽ��� ������ ����
char *pname = player.name;
char *ename = enemy.name;
short pHP = player.HP, pMHP = player.MAX_HP, pAP = player.AP, pMAP = player.MAX_AP, pSTR = player.strength, pAGL = player.agility, pDEF = player.defence, pLV = player.Level, pMEXP = player.MAX_Exp, pEXP = player.Exp;
bool pUnd = player.isUndead, pdead = player.dead, pCor = player.isCorrupted, ispDEFup = false;
short eHP = enemy.HP, eMHP = enemy.MAX_HP, eAP = enemy.AP, eMAP = enemy.MAX_AP, eSTR = enemy.strength, eAGL = enemy.agility, eDEF = enemy.defence, eEXP = enemy.Exp;
bool eUnd = enemy.isUndead, edead = enemy.dead, eCor = enemy.isCorrupted, iseDEFup, iseSMKed = false;
bool turns = true;
short eNumber = 0;

//����
void saveFile() {

	ofstream savefile("save.bin");

	if (savefile.good() == false) { cout << endl << "���� ���忡 �����Ͽ����ϴ�" << endl; return; }

	savefile << pname << " " << pMHP << " " << pHP << " " << pMAP << " " << pAP << " " << pSTR << " " << pAGL << " " << pDEF << " " << pLV << " " << pMEXP << " " << pEXP << " " << pUnd << " " << pdead << " " << pCor << " " << ispDEFup;
	cout << endl << "������ ���������� �Ϸ�Ǿ����ϴ�." << endl;
	savefile.close();

}

//�ҷ�����
void loadFile() {

	system("cls");

	ifstream savefile("save.bin");
	if (savefile.is_open() == false) { cout << endl << "���̺� �����Ͱ� ���ų� �ҷ����⿡ �����Ͽ����ϴ�" << endl; return; }

	savefile >> pname >> pMHP >> pHP >> pMAP >> pAP >> pSTR >> pAGL >> pDEF >> pLV >> pMEXP >> pEXP >> pUnd >> pdead >> pCor >> ispDEFup;

	cout << endl << "�ε�� ���̺� ����" << endl <<
		"AI - " << pname << endl <<
		"LV - " << pLV << endl <<
		"HP - " << pHP << "/" << pMHP << endl <<
		"AP - " << pAP << "/" << pMAP << endl <<
		"STR - " << pSTR << endl <<
		"AGL - " << pAGL << endl <<
		"DEF - " << pDEF << endl <<
		"Exp - " << pEXP << "/" << pMEXP << endl;
	
	savefile.close();

	cout << endl << "����(Enter)Ű �� ������ �����մϴ�." << endl;
	getch();
	rewind(stdin);
	LfABase(true);

}

//�÷��̾� �����͸� ���½�Ŵ
void PlayerReset() {

	pname = player.name;
	pMHP = player.MAX_HP;
	pHP = player.HP;
	pMAP = player.MAX_AP;
	pAP = player.AP;
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

//�� �����͸� ����Ŀ�� �ʱ�ȭ��Ŵ
void attackerReset() {

	eNumber = 3;
	ename = "����Ŀ";
	eMHP = 60;
	eHP = 60;
	eMAP = 20;
	eAP = 20;
	eSTR = 5;
	eAGL = 5;
	eDEF = 4;
	eUnd = false;
	edead = false;
	eCor = false;
	eEXP = 50;
	turns = false;
	iseSMKed = false;

}

//�� �����͸� ������ ���� �ʱ�ȭ��Ŵ
void tt2Reset() {

	eNumber = 2;
	ename = "������ ���";
	eMHP = 30;
	eHP = 30;
	eMAP = 10;
	eAP = 10;
	eSTR = 3;
	eAGL = 3;
	eDEF = 2;
	eUnd = false;
	edead = false;
	eCor = false;
	eEXP = 20;
	turns = true;
	iseSMKed = false;

}

//�� �����͸� ������ ���� �ʱ�ȭ��Ŵ
void tt1Reset() {
	
	eNumber = 1;
	ename = "������ ���";
	eMHP = 20;
	eHP = 20;
	eMAP = 10;
	eAP = 10;
	eSTR = 2;
	eAGL = 2;
	eDEF = 1;
	eUnd = false;
	edead = false;
	eCor = false;
	eEXP = 20;
	turns = true;
	iseSMKed = false;

}