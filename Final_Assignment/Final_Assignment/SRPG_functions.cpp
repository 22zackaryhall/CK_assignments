#include "SRPG.h"
#include "SRPG_characters.h"

//SRPG_characters.cpp에 선언한 플레이어 데이터와 적 데이터를 외부참조
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

bool isSMKfail = false;


//MAX값을 입력받아 1 ~ MAX 중의 입력받은 정수를 반환해주는 재귀호출함수
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

//이름을 입력받는 함수
char getName() {
	char name[16];
	bool inFail = false;

	while (!inFail) {
		for (int i = 0; i < sizeof(name); i++) {
			name[i] = NULL;
		}
		cout << endl << "이름을 입력해 주십시요 (공백 없이 16byte이하)" << endl;
		cin >> name;
		strcpy(player.name, name);
		cout << endl << endl << "입력하신 AI의 이름은 '" << player.name << "' 가(이) 맞습니까?" << endl;
		cout << "[1] 예" << endl << "[2] 아니오" << endl;
		switch (getNums(2)) {
		case 1: return *name; break;
		case 2: continue;
		}
	}
		
}


//감염여부 (미사용)
void isCorrupted(bool in) {
	
	if (in == true) {
		cout << "감염";
	}
	else {
		cout << "정상";
	}
}

//얻은 경험치(get)으로 레벨업 여부를 판단하고, 레벨이 올랐을 경우 스텟 포인트를 2개 얻음
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

//전투중 플레이어 혹은 적의 체력이 0이 되었을 때 전투 종료를 위한 값을 반환해주는 함수
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

//코드 테스트 중 코드의 마지막을 확인하기 위해 사용하는 함수
void CORDLINEEND() {
	cout << endl << "!!! END LINE !!!" << endl;
	getch();
	rewind(stdin);
}


//전투에서 플레이어와 적의 공격을 처리하는 함수
void bAttack(bool turn, bool hvAttack) {
	short PtEtemp = ((pSTR * 2) - (eDEF));
	short EtPtemp = ((eSTR * 2) - (pDEF));
	short temp2 = (pAP - 5);
	bool nEnough = false; //AP가 충분하거나 모자람을 나타내는 변수

	switch (turn) {

		//플레이어의 공격
	case true:
		if (temp2 >= 0 && hvAttack == true) { 
			cout << endl << pname << "가(이) " << ename << "을(를) 강타!" << endl;
			PtEtemp = (pSTR * 2);
			pAP = temp2;
			nEnough = false;
		}
		else {
			if (temp2 < 0 && hvAttack == true) {
				cout << "AP 가 " << abs(temp2) << " 만큼 부족합니다." << endl;
				nEnough = true;
			}
			cout << endl << pname << "가(이) " << ename << "을(를) 공격!" << endl;
			PtEtemp = ((pSTR * 2) - (eDEF));
		}

		if (((pSTR * 2) - (eDEF)) <= 0) {
			PtEtemp = 1;
		}
		eHP -= PtEtemp;
		if (eHP < 0) {
			PtEtemp += eHP;
			eHP = 0;
		}


		_sleep(1000);
		cout << endl << ename << "은(는) " << PtEtemp << "만큼의 데미지를 입었다!" << endl;
		cout << ename << " HP " << eHP << " / " << eMHP << "   AP " << eAP << " / " << eMAP << endl;
		_sleep(1000);
		if (ispDEFup == true) {
			pDEF -= DEFup;
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

		//적의 공격
	case false:
		if (isSMKfail == true) {
			turns = true;
			break;
		}
		cout << endl << ename << "가(이) " << pname << "을(를) 공격!" << endl;

		if (((eSTR * 2) - (pDEF)) <= 0) {
			EtPtemp = 1;
		}
		pHP -= EtPtemp;
		if (pHP < 0) {
			EtPtemp += pHP;
			pHP = 0;
		}

		_sleep(1000);
		cout << endl << pname << "은(는) " << EtPtemp << "만큼의 데미지를 입었다!" << endl;
		_sleep(1000);
		if (iseDEFup == true) {
			eDEF -= DEFup;
			iseDEFup = false;
		}
		if (pHP <= 0) {
			pdead = true;
		}
		turns = true;
		break;
	}
}

//연막탄
void SKLsmokeBomb(bool turn) {

	short temp = (pAP - 10);
	short temp2 = (eAGL - 3);
	
	if (temp < 0) {
		_sleep(500);
		cout << endl << "AP가 " << abs(temp) << " 만큼 부족합니다." << endl;
		_sleep(500);
		isSMKfail = true;
	}
	if (temp >= 0) {
		cout << endl << pname << " 은(는) " << ename << " 에게 연막탄을 투척했다!" << endl;
		_sleep(500);
		cout << endl << ename << " 의 시야를 봉쇄하였습니다. 1턴 동안 도주 확률이 증가합니다." << endl;
		_sleep(500);
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

//전투 중 플레이어와 적의 방어를 처리하는 함수
void bDefence(bool turn) {

	switch (turn) {
	case true:
		if (ispDEFup == true) {
			pDEF -= DEFup;
			ispDEFup = false;
		}
		cout << endl << pname << "은(는) 공격에 대비했다." << endl;
		_sleep(1000);
		pDEF += DEFup;
		ispDEFup = true;
		if (iseSMKed == true) {
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
		if (isSMKfail == true) {
			turns = true;
			break;
		}
		if (iseDEFup == true) {
			eDEF -= DEFup;
			iseDEFup = false;
		}
		cout << endl << ename << "은(는) 공격에 대비했다." << endl;
		_sleep(1000);
		eDEF += DEFup;
		iseDEFup = true;
		turns = true;
		break;
	}
}

//전투종료를 위한 도주 성공이나 실패 값을 반환해주는 함수
bool bRunaway(bool turn) {

	short temp = rand() % 100;
	bool temp2;

	if (pAGL > eAGL) {
		
		if (iseSMKed == true && temp < 90) {
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
		if (iseSMKed == false && temp < 74) {
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
		if (iseSMKed == true && temp < 74) {
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

		if (iseSMKed == false && temp < 54) {
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

//전투의 메인 함수
void Battle() {

	int pChoice = 1, eChoice = 1;
	bool Runaway = false;

	cout << endl << "! 교전 !" << endl;

	_sleep(500);

	cout << "[" << ename << "] HP " << eHP << " / " << eMHP << "   AP " << eAP << " / " << eMAP << endl;
	
	_sleep(1000);

	do {
		switch (turns) {
		case true:
			if (isBattleover() != 2 || Runaway != false) {
				break;
			}
			else {
				cout << endl << "[" << pname << "] HP " << pHP << " / " << pMHP << "   AP " << pAP << " / " << pMAP << endl;
				cout << "당신의 차례 입니다." << endl <<
					"[1] 공격" << endl << "[2] 강타 (AP 5 소모)" << endl << "[3] 연막탄 (AP 10 소모)" << endl << "[4] 방어" << endl << "[5] 도주" << endl;
				pChoice = getNums(5);
				switch (pChoice) {
				case 1: bAttack(turns, false); break;
				case 2: bAttack(turns, true); break;
				case 3: SKLsmokeBomb(turns); break;
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

	if (pdead == true) {
		gameOver();
	}

	if (edead == true) {
		getEXP(eEXP);
	}
	_sleep(1000);
}

//플레이어 사망
void gameOver() {
	
	cout << endl << "GAME OVER" << endl;
	_sleep(750);
	cout << "[1] 저장된 데이터를 불러온다." << endl <<
		"[2] 종료한다." << endl;
	switch (getNums(2)) {
	case 1:loadFile(); LfABase(true); break;
	case 2:exit(0); break;
	}

}

//탐색
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

//처음으로 베이스에 들어갔을 때
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

//플레이어 스테이터스 표시
void printpStatus() {
	cout << endl << "상태" << endl <<
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
}

//베이스
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
		case 3: printpStatus(); break;
		case 4: saveFile(); break;
		case 5: exit(0); break;
		}

	}

}