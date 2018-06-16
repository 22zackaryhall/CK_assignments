#include "SRPG.h"
#include "SRPG_characters.h"


int getNums(const int MAX) {

	int Num = 0;

	cout << "입력 : ";
	cin >> Num;

	if (cin.fail()) {
		cout << "틀린 값입니다. 다시 입력하여 주세요." << endl;
		cin.clear();
		rewind(stdin);
		return getNums(MAX);
	}
	if (Num > MAX || Num <= 0) {
		cout << MAX << " 이하, 1 이상의 값을 입력해 주세요." << endl;
		cin.clear();
		rewind(stdin);
		return getNums(MAX);
	}

	return Num;
}

void isCorrupted(bool in) {
	
	if (in == true) {
		cout << "감염";
	}
	else {
		cout << "정상";
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
	cout << "! 교전 !" << endl << endl;
	while (eHP > 0 && pHP > 0 && battleEnd != true) {
		cout << " HP " << pHP << " / " << pMHP << "   MP " << pMP << " / " << pMMP << endl;
		cout << "당신의 차례 입니다." << endl <<
			"[1] 공격   [2] 방어   [3] 아이템   [4] 도망" << endl;
		pChoice = getNums(4);
		switch (pChoice) {
		case 1: 
			cout << pname << "이(가) " << ename << "을(를) 공격!" << endl;
			eHP -= ((pSTR * 2) - (eDEF));
			cout << ename << "은(는) " << ((pSTR * 2) - (eDEF)) << "만큼의 데미지를 입었다!" << endl;
			_sleep(500);
			if (eHP > 0) {
			cout << ename << "이(가) " << pname << "을(를) 공격!" << endl;
			pHP -= ((eSTR * 2) - (pDEF));
			cout << pname << "은(는) " << ((eSTR * 2) - (pDEF)) << "만큼의 데미지를 입었다!" << endl;
			}
			else {
				break;
			}
			break;
		case 2: 
			cout << pname << "는(은) 공격에 대비했다." << endl;
			pDEF = (pDEF - (pDEF / 2));
			_sleep(500);
				cout << ename << "이(가) " << pname << "을(를) 공격!" << endl;
				pHP -= ((eSTR * 2) - (pDEF));
				cout << pname << "은(는) " << ((eSTR * 2) - (pDEF)) << "만큼의 데미지를 입었다!" << endl;
			break;
		case 3: break;
		case 4: break;
		}
	}
	cout << "교전 종료" << endl;
	_sleep(2000);
}

