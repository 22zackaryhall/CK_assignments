#include "SRPG.h"
#include "SRPG_characters.h"


int getNums(const int MAX) {

	int Num = 0;

	cout << "�Է� : ";
	cin >> Num;

	if (cin.fail()) {
		cout << "Ʋ�� ���Դϴ�. �ٽ� �Է��Ͽ� �ּ���." << endl;
		cin.clear();
		rewind(stdin);
		return getNums(MAX);
	}
	if (Num > MAX || Num <= 0) {
		cout << MAX << " ����, 1 �̻��� ���� �Է��� �ּ���." << endl;
		cin.clear();
		rewind(stdin);
		return getNums(MAX);
	}

	return Num;
}

void isCorrupted(bool in) {
	
	if (in == true) {
		cout << "����";
	}
	else {
		cout << "����";
	}
}

void Battle() {

	int pChoice = 1, eChoice = 1;
	bool battleEnd = false;

//	char pname[16], ename[16];
//	strcpy(pname, player.name);
//	strcpy(ename, enemy.name);
	
	char *pname = player.name;
	char *ename = enemy.name;
	short pHP = player.HP, pMHP = player.MAX_HP, pMP = player.MP, pMMP = player.MAX_MP, pSTR = player.strength, pAGL = player.agility, pDEF = player.defence;
	bool pUnd = player.isUndead, pdead = player.dead, pCor = player.isCorrupted;
	short eHP = enemy.HP, eMHP = enemy.MAX_HP, eMP = enemy.MP, eMMP = enemy.MAX_MP, eSTR = enemy.strength, eAGL = enemy.agility, eDEF = enemy.defence;
	bool eUnd = enemy.isUndead, edead = enemy.dead, eCor = enemy.isCorrupted;

	system("cls");
	cout << "! ���� !" << endl << endl;
	while (eHP > 0 && pHP > 0 && battleEnd != true) {
		cout << " HP " << pHP << " / " << pMHP << "   MP " << pMP << " / " << pMMP << endl;
		cout << "����� ���� �Դϴ�." << endl <<
			"[1] ����   [2] ���   [3] ������   [4] ����" << endl;
		pChoice = getNums(4);
		switch (pChoice) {
		case 1: 
			cout << pname << "��(��) " << ename << "��(��) ����!" << endl;
			eHP -= ((pSTR * 2) - (eDEF));
			cout << ename << "��(��) " << ((pSTR * 2) - (eDEF)) << "��ŭ�� �������� �Ծ���!" << endl;
			_sleep(500);
			if (eHP > 0) {
			cout << ename << "��(��) " << pname << "��(��) ����!" << endl;
			pHP -= ((eSTR * 2) - (pDEF));
			cout << pname << "��(��) " << ((eSTR * 2) - (pDEF)) << "��ŭ�� �������� �Ծ���!" << endl;
			}
			else {
				break;
			}
			break;
		case 2: 
			cout << pname << "��(��) ���ݿ� ����ߴ�." << endl;
			pDEF = (pDEF - (pDEF / 2));
			_sleep(500);
				cout << ename << "��(��) " << pname << "��(��) ����!" << endl;
				pHP -= ((eSTR * 2) - (pDEF));
				cout << pname << "��(��) " << ((eSTR * 2) - (pDEF)) << "��ŭ�� �������� �Ծ���!" << endl;
			break;
		case 3: break;
		case 4: break;
		}
	}
	cout << "���� ����" << endl;
	_sleep(2000);
}

