#include "SRPG.h"
#include "SRPG_characters.h"

static char *pname = player.name;
char *ename = enemy.name;
static short pHP = player.HP, pMHP = player.MAX_HP, pMP = player.MP, pMMP = player.MAX_MP, pSTR = player.strength, pAGL = player.agility, pDEF = player.defence, pLV = player.Level,pMEXP = player.MAX_Exp, pEXP = player.Exp;
static bool pUnd = player.isUndead, pdead = player.dead, pCor = player.isCorrupted, ispDEFup = false;
short eHP = enemy.HP, eMHP = enemy.MAX_HP, eMP = enemy.MP, eMMP = enemy.MAX_MP, eSTR = enemy.strength, eAGL = enemy.agility, eDEF = enemy.defence, eEXP = enemy.Exp;
bool eUnd = enemy.isUndead, edead = enemy.dead, eCor = enemy.isCorrupted, iseDEFup = false;
bool turns = true;

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

short getEXP(short get) {

	short EXP = pEXP + get;
	short SPs = 2;

	if (EXP >= pMEXP) {
		EXP = pEXP - pMEXP;
		pLV++;
		pMEXP += 25;
		cout << endl << "레벨이 올랐습니다!" << endl;
		while (SPs != 0) {
			cout << "스텟 포인트가 " << SPs << "점 남았습니다." << endl <<
				"[1] 힘    [2] 민첩    [3] 방어" << endl;
			switch (getNums(3)) {
			case 1: --SPs; player.strength++; cout << endl << "힘 스텟이 1 증가하여 " << player.strength << " 이(가) 되었습니다." << endl << endl; break;
			case 2: --SPs; player.agility++; cout << endl << "민첩 스텟이 1 증가하여 " << player.agility << " 이(가) 되었습니다." << endl << endl; break;
			case 3: --SPs; player.defence++; cout << endl << "방어 스텟이 1 증가하여 " << player.defence << " 이(가) 되었습니다." << endl << endl; break;
			}
		}
	}
	return EXP;
}

short isBattleover() {
	int over;
	if (pdead == true) {
		cout << endl << pname << "은(는) 파괴되었습니다." << endl;
		_sleep(1000);
		over = 0;	//패배
	}
	if (edead == true) {
		cout << endl << ename << "은(는) 파괴되었습니다." << endl;
		_sleep(1000);
		over = 1;	//승리
	}
	if (pdead != true && edead != true) {
		over = 2;	//지속
	}
	return over;
}

void CORDLINEEND() {
	cout << endl << "!!! END LINE !!!" << endl;
	getch();
	rewind(stdin);
}

void bAttack(bool turn) {
	switch (turn) {
	case true:
		cout << endl << pname << "이(가) " << ename << "을(를) 공격!" << endl;
		eHP -= ((pSTR * 2) - (eDEF));
		_sleep(1000);
		cout << endl << ename << "은(는) " << ((pSTR * 2) - (eDEF)) << "만큼의 데미지를 입었다!" << endl;
		cout << ename << " HP " << eHP << " / " << eMHP << "   MP " << eMP << " / " << eMMP << endl;
		_sleep(1000);
		if (ispDEFup == true) {
			pDEF -= 2;
			ispDEFup = false;
		}
		if (eHP <= 0) {
			edead = true;
		}
		turns = false;
		break;

	case false:
		cout << endl << ename << "이(가) " << pname << "을(를) 공격!" << endl;
		pHP -= ((eSTR * 2) - (pDEF));
		_sleep(1000);
		cout << endl << pname << "은(는) " << ((eSTR * 2) - (pDEF)) << "만큼의 데미지를 입었다!" << endl;
		_sleep(1000);
		if (iseDEFup == true) {
			eDEF -= 2;
			iseDEFup = false;
		}
		if (pHP <= 0) {
			pdead = true;
		}
		turns = true;
		break;
	}
}

void bDefence(bool turn) {

	switch (turn) {
	case true:
		if (ispDEFup == true) {
			pDEF -= 2;
			ispDEFup = false;
		}
		cout << endl << pname << "는(은) 공격에 대비했다." << endl;
		_sleep(1000);
		pDEF += 2;
		ispDEFup = true;
		turns = false;
		break;
	case false:
		if (iseDEFup == true) {
			eDEF -= 2;
			iseDEFup = false;
		}
		cout << endl << ename << "는(은) 공격에 대비했다." << endl;
		_sleep(1000);
		eDEF += 2;
		iseDEFup = true;
		turns = true;
		break;
	}
}

bool bRunaway(bool turn) {

	short temp;

	if (pAGL > eAGL) {
		temp = rand() % 100;
		if (temp > 89) {
			cout << endl << "도주 성공." << endl;
			_sleep(1000);
			return true;
		}
		else {
			cout << endl << "도주 실패." << endl;
			_sleep(1000);
			return false;
		}
	}
	else {
		temp = rand() % 100;
		if (temp > 74) {
			cout << endl << "도주 성공." << endl;
			_sleep(1000);
			return true;
		}
		else {
			cout << endl << "도주 실패." << endl;
			_sleep(1000);
			return false;
		}
	}
}
/*
void enemyReset() {
	eMHP = enemy.MAX_HP;
	eMHP += 10;
	eHP = enemy.HP;
	eHP += 10;
	eMMP = enemy.MAX_MP;
	eMP = enemy.MP;
	eSTR = enemy.strength;
	eSTR += 2;
	eAGL = enemy.agility;
	eAGL++;
	eDEF = enemy.defence;
	eDEF++;
	eUnd = enemy.isUndead;
	edead = enemy.dead;
	eCor = enemy.isCorrupted;
}
*/

void Battle() {

	int pChoice = 1, eChoice = 1;

	pname;
	pHP;
	pMHP;
	pMP;
	pMMP;
	pSTR;
	pAGL;
	pDEF;
	//	pUnd = player.isUndead, pdead = player.dead, pCor = player.isCorrupted;
//	pname = player.name;
	//ename = enemy.name;
//	pHP = player.HP, pMHP = player.MAX_HP, pMP = player.MP, pMMP = player.MAX_MP, pSTR = player.strength, pAGL = player.agility, pDEF = player.defence;
//	pUnd = player.isUndead, pdead = player.dead, pCor = player.isCorrupted;
	//eHP = enemy.HP, eMHP = enemy.MAX_HP, eMP = enemy.MP, eMMP = enemy.MAX_MP, eSTR = enemy.strength, eAGL = enemy.agility, eDEF = enemy.defence;
	//eUnd = enemy.isUndead, edead = enemy.dead, eCor = enemy.isCorrupted;

	bool Runaway = false;

	cout << endl << "! 교전 !" << endl;
	do {
		switch (turns) {
		case true:
			if (isBattleover() != 2 || Runaway != false) {
				break;
			}
			else {
				cout << endl << "[" << pname << "] HP " << pHP << " / " << pMHP << "   MP " << pMP << " / " << pMMP << endl;
				cout << "당신의 차례 입니다." << endl <<
					"[1] 공격   [2] 방어   [3] 도망" << endl;
				pChoice = getNums(3);
				switch (pChoice) {
				case 1: bAttack(turns); break;
				case 2: bDefence(turns); break;
				case 3: Runaway = bRunaway(turns); break;
				}
			}
		case false:
			if (isBattleover() != 2 || Runaway != false) {
				break;
			}
			else {
				eChoice = (rand() % 3);
				switch (eChoice) {
				case 0: bAttack(turns); break;
				case 1: bAttack(turns); break;
				case 2: bDefence(turns); break;
				}
			}
		}
	} while (eHP > 0 && pHP > 0 && Runaway == false);
	cout << endl << "교전 종료" << endl << endl;
	_sleep(1000);

	if (edead == true) {
		getEXP(eEXP);
	}
	
	_sleep(1500);
}

void walking(short Distance, short howmany) {

//	enemyReset();
	short temp, temp2 = 0;
	bool way[10];
	for (int i = 0; i < 10; i++) {
		way[i] = false;
	}
	while(temp2 > howmany){
		temp = ((rand() % Distance));
		if (way[temp] == false) {
			way[temp] = true;
			temp2++;
		}
	}

	for (int i = 0; i < Distance; i++) {
		cout << endl << "엔터(Enter)키를 눌러 전진합니다." << endl;
		getch();
		rewind(stdin);
		cout << endl << "목표까지의 거리 " << i + 1 << "/" << Distance << endl;
		if (way[i] == true) {
			tt2Reset();
			Battle();
		}
	}
}

void LfABaseFirst() {
	
	cout << endl << "LfA 기지의 좌표에 도착하였습니다." << endl;
	_sleep(1500);
	cout << endl << "상당히 위협적인 적대적 신호가 감지됩니다. " << endl;
	_sleep(1500);
	cout << endl << "신호가 가까워집니다." << endl;
	_sleep(2000);

	
	attackerReset();
	Battle();

}