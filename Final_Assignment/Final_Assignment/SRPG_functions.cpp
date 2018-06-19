#include "SRPG.h"
#include "SRPG_characters.h"

extern char
*pname,
*ename;
extern short
pMHP,
pHP,
pMAP,
pAP,
pMEXP,
pEXP,
pSTR,
pAGL,
pDEF,
pLV,
eMHP,
eHP,
eMAP,
eAP,
eSTR,
eAGL,
eDEF,
eEXP,
eNumber;
extern bool
pUnd,
pdead,
pCor,
eUnd,
edead,
eCor,
ispDEFup,
iseDEFup,
iseSMKed,
turns;

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

void getEXP(short get) {

	pEXP += get;
	short SPs = 2;

	if (pEXP >= pMEXP) {
		pEXP -= pMEXP;
		pLV++;
		pMEXP += 25;
		cout << endl << "레벨이 올랐습니다!" << endl;
		while (SPs != 0) {
			cout << "스텟 포인트가 " << SPs << "점 남았습니다." << endl <<
				"[1] 힘    [2] 민첩    [3] 방어" << endl;
			switch (getNums(3)) {
			case 1: --SPs; player.strength++; cout << endl << "힘 스텟이 1 증가하여 " << player.strength << " 가(이) 되었습니다." << endl << endl; break;
			case 2: --SPs; player.agility++; cout << endl << "민첩 스텟이 1 증가하여 " << player.agility << " 가(이) 되었습니다." << endl << endl; break;
			case 3: --SPs; player.defence++; cout << endl << "방어 스텟이 1 증가하여 " << player.defence << " 가(이) 되었습니다." << endl << endl; break;
			}
		}
	}
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

void bAttack(bool turn, bool hvAttack) {
	short temp = ((pSTR * 2) - (eDEF));
	short temp2 = (pAP - 5);
	bool nEnough = false;

	switch (turn) {
	case true:
		if (temp2 >= 0 && hvAttack == true) { 
			cout << endl << pname << "가(이) " << ename << "을(를) 강타!" << endl;
			temp = (pSTR * 2);
			pAP = temp2;
			nEnough = false;
		}
		else {
			if (temp2 < 0 && hvAttack == true) {
				cout << "AP 가 " << !temp2 << " 만큼 부족합니다." << endl;
				nEnough = true;
			}
			cout << endl << pname << "가(이) " << ename << "을(를) 공격!" << endl;
			temp = ((pSTR * 2) - (eDEF));
		}
		eHP -= temp;
		if (eHP < 0) {
			temp += eHP;
			eHP = 0;
		}
		if (((pSTR * 2) - (eDEF)) <= 0) {
			temp = 1;
		}
		_sleep(1000);
		cout << endl << ename << "은(는) " << temp << "만큼의 데미지를 입었다!" << endl;
		cout << ename << " HP " << eHP << " / " << eMHP << "   AP " << eAP << " / " << eMAP << endl;
		_sleep(1000);
		if (ispDEFup == true) {
			pDEF -= 2;
			ispDEFup = false;
		}
		if (eHP <= 0) {
			edead = true;
		}
		if (iseSMKed == true) {
			cout << endl << ename << "은 연막탄의 효과에서 벗어났다!" << endl;
			switch (eNumber) {
			case 1: eAGL = 2; break;
			case 2: eAGL = 3; break;
			case 3: eAGL = 5; break;
			}
			iseSMKed = false;
		}
		turns = false;
		break;

	case false:
		cout << endl << ename << "가(이) " << pname << "을(를) 공격!" << endl;
		pHP -= ((eSTR * 2) - (pDEF));
		_sleep(1000);
		cout << endl << pname << "은(는) " << temp << "만큼의 데미지를 입었다!" << endl;
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

void SKLsmokeBomb() {

	short temp = (pAP - 10);
	short temp2 = (eAGL - 3);
	
	if (temp < 0) {
		cout << endl << "AP가 " << !temp << " 만큼 모자랍니다." << endl;
	}
	if (temp >= 0) {
		cout << endl << pname << " 은(는) " << ename << " 에게 연막탄을 투척했다!" << endl;
		if (temp2 < 0) {
			eAGL = 1;
		}
		else {
			eAGL = temp2;
		}
		pAP = temp;
		iseSMKed = true;
	}
	turns = false;

}

void bDefence(bool turn) {

	switch (turn) {
	case true:
		if (ispDEFup == true) {
			pDEF -= 2;
			ispDEFup = false;
		}
		cout << endl << pname << "은(는) 공격에 대비했다." << endl;
		_sleep(1000);
		pDEF += 2;
		ispDEFup = true;
		if (iseSMKed = true) {
			cout << endl << ename << "은(는) 연막탄의 효과에서 벗어났다!" << endl;
			switch (eNumber) {
			case 1: eAGL = 2; break;
			case 2: eAGL = 3; break;
			case 3: eAGL = 5; break;
			}
			iseSMKed = false;
		}
		turns = false;
		break;
	case false:
		if (iseDEFup == true) {
			eDEF -= 2;
			iseDEFup = false;
		}
		cout << endl << ename << "은(는) 공격에 대비했다." << endl;
		_sleep(1000);
		eDEF += 2;
		iseDEFup = true;
		turns = true;
		break;
	}
}

bool bRunaway(bool turn) {

	short temp;
	bool temp2;

	if (pAGL > eAGL) {
		temp = rand() % 100;
		if (temp < 89) {
			cout << endl << "도주 성공." << endl;
			_sleep(1000);
			temp2 = true;
		}
		else {
			cout << endl << "도주 실패." << endl;
			_sleep(1000);
			turns = false;
			temp2 = false;
		}
	}
	else {
		temp = rand() % 100;
		if (temp < 54) {
			cout << endl << "도주 성공." << endl;
			_sleep(1000);
			temp2 = true;
		}
		else {
			cout << endl << "도주 실패." << endl;
			_sleep(1000);
			turns = false;
			temp2 = false;
		}
	}
	if (iseSMKed = true) {
		switch (eNumber) {
		case 1: eAGL = 2; break;
		case 2: eAGL = 3; break;
		case 3: eAGL = 5; break;
		}
		iseSMKed = false;
	}
	return temp2;
}


void Battle() {

	int pChoice = 1, eChoice = 1;

	bool Runaway = false;

	cout << endl << "! 교전 !" << endl;
	
	_sleep(1500);

	do {
		switch (turns) {
		case true:
			if (isBattleover() != 2 || Runaway != false) {
				break;
			}
			else {
				cout << endl << "[" << pname << "] HP " << pHP << " / " << pMHP << "   AP " << pAP << " / " << pMAP << endl;
				cout << "당신의 차례 입니다." << endl <<
					"[1] 공격" << endl << "[2] 강타 (AP 5 소모)" << endl << "[3] 연막탄 (AP 10 소모)" << endl << "[4] 방어" << endl << "[5] 도망" << endl;
				pChoice = getNums(5);
				switch (pChoice) {
				case 1: bAttack(turns, false); break;
				case 2: bAttack(turns, true); break;
				case 3: SKLsmokeBomb(); break;
				case 4: bDefence(turns); break;
				case 5: Runaway = bRunaway(turns); break;
				}
			}
		case false:
			if (isBattleover() != 2 || Runaway != false) {
				break;
			}
			else {
				eChoice = (rand() % 3);
				switch (eChoice) {
				case 0: bAttack(turns,false); break;
				case 1: bAttack(turns,false); break;
				case 2: bDefence(turns); break;
				}
			}
		}
		rewind(stdin);
	} while (eHP > 0 && pHP > 0 && Runaway == false);
	cout << endl << "교전 종료" << endl << endl;
	_sleep(1000);

	if (edead == true) {
		getEXP(eEXP);
	}
	_sleep(1500);
}

void walking(short Distance, short howmany) {

	short temp, temp2 = 0;
	bool way[10];
	for (int i = 0; i < 10; i++) {
		way[i] = false;
	}
	while(temp2 < howmany){
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
		cout << endl << "목표까지 " << i + 1 << "/" << Distance << endl;
		if (way[i] == true) {
			tt2Reset();
			Battle();
		}
	}
}

void LfABaseFirst() {
	
	cout << endl << "베이스의 좌표에 도착하였습니다." << endl;
	_sleep(1500);
	cout << endl << "상당히 위협적인 적대적 신호가 감지됩니다. " << endl;
	_sleep(1500);
	cout << endl << "신호가 가까워집니다." << endl;
	_sleep(2000);
	
	attackerReset();
	Battle();

	cout << endl << "아무런 신호도 감지되지 않습니다." << endl;
	_sleep(1000);

	cout << endl << "현재 위치 식별 완료" << endl;
	_sleep(1000);
	
	LfABase(false);

}

void LfABase(bool isLoad) {

	if (isLoad == true) {
		system("cls");
	}

	while (true) {

		cout << endl << "현재 위치 - 해방군 기지";
		_sleep(1500);

		cout << endl << "무엇을 하시겠습니까?" << endl;
		_sleep(750);
		cout << "[1] 순찰" << endl <<
			"[2] 회복" << endl <<
			"[3] 상태" << endl <<
			"[4] 저장" << endl <<
			"[5] 종료" << endl;

		switch (getNums(5)) {
		case 1: walking(5, 2); break;
		case 2: pHP = pMHP;
			pAP = pMAP;
			cout << endl << "회복이 완료되었습니다." << endl;
			_sleep(750);
			cout << endl << "[" << pname << "] HP " << pHP << " / " << pMHP << "   AP " << pAP << " / " << pMAP << endl;
			break;
		case 3: cout << endl << "상태" << endl <<
			"AI - " << pname << endl <<
			"LV - " << pLV << endl <<
			"HP - " << pHP << "/" << pMHP << endl <<
			"AP - " << pAP << "/" << pMAP << endl <<
			"STR - " << pSTR << endl <<
			"AGL - " << pAGL << endl <<
			"DEF - " << pDEF << endl <<
			"Exp - " << pEXP << "/" << pMEXP << endl;
			cout << endl << "엔터(Enter)키 를 누르면 돌아갑니다." << endl;
			getch();
			rewind(stdin);
			break;
		case 4: saveFile(); break;
		case 5: exit(0); break;
		}

	}

}