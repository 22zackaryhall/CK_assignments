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

bool isSMKfail = false;

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

void getEXP(short get) {

	pEXP += get;
	short SPs = 2;

	if (pEXP >= pMEXP) {
		pEXP -= pMEXP;
		pLV++;
		pMEXP += 25;
		cout << endl << "������ �ö����ϴ�!" << endl;
		while (SPs != 0) {
			cout << "���� ����Ʈ�� " << SPs << "�� ���ҽ��ϴ�." << endl <<
				"[1] ��    [2] ��ø    [3] ���" << endl;
			switch (getNums(3)) {
			case 1: --SPs; player.strength++; cout << endl << "�� ������ 1 �����Ͽ� " << player.strength << " ��(��) �Ǿ����ϴ�." << endl << endl; break;
			case 2: --SPs; player.agility++; cout << endl << "��ø ������ 1 �����Ͽ� " << player.agility << " ��(��) �Ǿ����ϴ�." << endl << endl; break;
			case 3: --SPs; player.defence++; cout << endl << "��� ������ 1 �����Ͽ� " << player.defence << " ��(��) �Ǿ����ϴ�." << endl << endl; break;
			}
		}
	}
}

short isBattleover() {
	int over;
	if (pdead == true) {
		cout << endl << pname << "��(��) �ı��Ǿ����ϴ�." << endl;
		_sleep(1000);
		over = 0;	//�й�
	}
	if (edead == true) {
		cout << endl << ename << "��(��) �ı��Ǿ����ϴ�." << endl;
		_sleep(1000);
		over = 1;	//�¸�
	}
	if (pdead != true && edead != true) {
		over = 2;	//����
	}
	return over;
}

void CORDLINEEND() {
	cout << endl << "!!! END LINE !!!" << endl;
	getch();
	rewind(stdin);
}

void bAttack(bool turn, bool hvAttack) {
	short PtEtemp = ((pSTR * 2) - (eDEF));
	short EtPtemp = ((eSTR * 2) - (pDEF));
	short temp2 = (pAP - 5);
	bool nEnough = false;

	switch (turn) {
	case true:
		if (temp2 >= 0 && hvAttack == true) { 
			cout << endl << pname << "��(��) " << ename << "��(��) ��Ÿ!" << endl;
			PtEtemp = (pSTR * 2);
			pAP = temp2;
			nEnough = false;
		}
		else {
			if (temp2 < 0 && hvAttack == true) {
				cout << "AP �� " << abs(temp2) << " ��ŭ �����մϴ�." << endl;
				nEnough = true;
			}
			cout << endl << pname << "��(��) " << ename << "��(��) ����!" << endl;
			PtEtemp = ((pSTR * 2) - (eDEF));
		}
		eHP -= PtEtemp;
		if (eHP < 0) {
			PtEtemp += eHP;
			eHP = 0;
		}
		if (((pSTR * 2) - (eDEF)) <= 0) {
			PtEtemp = 1;
		}
		_sleep(1000);
		cout << endl << ename << "��(��) " << PtEtemp << "��ŭ�� �������� �Ծ���!" << endl;
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
			cout << endl << ename << "�� ����ź�� ȿ������ �����!" << endl;
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
		cout << endl << ename << "��(��) " << pname << "��(��) ����!" << endl;
		pHP -= EtPtemp;
		if (pHP < 0) {
			EtPtemp += pHP;
			pHP = 0;
		}
		if (((eSTR * 2) - (pDEF)) <= 0) {
			EtPtemp = 1;
		}
		_sleep(1000);
		cout << endl << pname << "��(��) " << EtPtemp << "��ŭ�� �������� �Ծ���!" << endl;
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

void SKLsmokeBomb(bool turn) {

	short temp = (pAP - 10);
	short temp2 = (eAGL - 3);
	
	if (temp < 0) {
		_sleep(500);
		cout << endl << "AP�� " << abs(temp) << " ��ŭ �����մϴ�." << endl;
		_sleep(500);
		isSMKfail = true;
	}
	if (temp >= 0) {
		cout << endl << pname << " ��(��) " << ename << " ���� ����ź�� ��ô�ߴ�!" << endl;
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
		cout << endl << pname << "��(��) ���ݿ� ����ߴ�." << endl;
		_sleep(1000);
		pDEF += 2;
		ispDEFup = true;
		if (iseSMKed == true) {
			cout << endl << ename << "��(��) ����ź�� ȿ������ �����!" << endl;
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
			eDEF -= 2;
			iseDEFup = false;
		}
		cout << endl << ename << "��(��) ���ݿ� ����ߴ�." << endl;
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
			cout << endl << "���� ����." << endl;
			_sleep(1000);
			temp2 = true;
		}
		else {
			cout << endl << "���� ����." << endl;
			_sleep(1000);
			turns = false;
			temp2 = false;
		}
	}
	else {
		temp = rand() % 100;
		if (temp < 54) {
			cout << endl << "���� ����." << endl;
			_sleep(1000);
			temp2 = true;
		}
		else {
			cout << endl << "���� ����." << endl;
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

	cout << endl << "! ���� !" << endl;
	
	_sleep(1500);

	do {
		switch (turns) {
		case true:
			if (isBattleover() != 2 || Runaway != false) {
				break;
			}
			else {
				cout << endl << "[" << pname << "] HP " << pHP << " / " << pMHP << "   AP " << pAP << " / " << pMAP << endl;
				cout << "����� ���� �Դϴ�." << endl <<
					"[1] ����" << endl << "[2] ��Ÿ (AP 5 �Ҹ�)" << endl << "[3] ����ź (AP 10 �Ҹ�)" << endl << "[4] ���" << endl << "[5] ����" << endl;
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
	cout << endl << "���� ����" << endl << endl;
	_sleep(1000);

	if (pdead == true) {
		gameOver();
	}

	if (edead == true) {
		getEXP(eEXP);
	}
	_sleep(1500);
}

void gameOver() {
	
	cout << endl << "GAME OVER" << endl;
	_sleep(750);
	cout << "[1] ����� �����͸� �ҷ��´�." << endl <<
		"[2] �����Ѵ�." << endl;
	switch (getNums(2)) {
	case 1:loadFile(); LfABase(true); break;
	case 2:exit(0); break;
	}

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
		cout << endl << "����(Enter)Ű�� ���� �����մϴ�." << endl;
		getch();
		rewind(stdin);
		cout << endl << "��ǥ���� " << i + 1 << "/" << Distance << endl;
		if (way[i] == true) {
			tt2Reset();
			Battle();
		}
	}
}

void LfABaseFirst() {
	
	cout << endl << "���̽��� ��ǥ�� �����Ͽ����ϴ�." << endl;
	_sleep(1500);
	cout << endl << "����� �������� ������ ��ȣ�� �����˴ϴ�. " << endl;
	_sleep(1500);
	cout << endl << "��ȣ�� ��������ϴ�." << endl;
	_sleep(2000);
	
	attackerReset();
	Battle();

	cout << endl << "�ƹ��� ��ȣ�� �������� �ʽ��ϴ�." << endl;
	_sleep(1000);

	cout << endl << "���� ��ġ �ĺ� �Ϸ�" << endl;
	_sleep(1000);
	
	LfABase(false);

}

void printpStatus() {
	cout << endl << "����" << endl <<
		"AI - " << pname << endl <<
		"LV - " << pLV << endl <<
		"HP - " << pHP << "/" << pMHP << endl <<
		"AP - " << pAP << "/" << pMAP << endl <<
		"STR - " << pSTR << endl <<
		"AGL - " << pAGL << endl <<
		"DEF - " << pDEF << endl <<
		"Exp - " << pEXP << "/" << pMEXP << endl;
	cout << endl << "����(Enter)Ű �� ������ ���ư��ϴ�." << endl;
	getch();
	rewind(stdin);
}

void LfABase(bool isLoad) {

	if (isLoad == true) {
		system("cls");
	}

	while (true) {

		cout << endl << "���� ��ġ - �ع決 ����";
		_sleep(1500);

		cout << endl << "������ �Ͻðڽ��ϱ�?" << endl;
		_sleep(750);
		cout << "[1] ����" << endl <<
			"[2] ȸ��" << endl <<
			"[3] ����" << endl <<
			"[4] ����" << endl <<
			"[5] ����" << endl;

		switch (getNums(5)) {
		case 1: walking(5, 2); break;
		case 2: pHP = pMHP;
			pAP = pMAP;
			cout << endl << "ȸ���� �Ϸ�Ǿ����ϴ�." << endl;
			_sleep(750);
			cout << endl << "[" << pname << "] HP " << pHP << " / " << pMHP << "   AP " << pAP << " / " << pMAP << endl;
			break;
		case 3: printpStatus(); break;
		case 4: saveFile(); break;
		case 5: exit(0); break;
		}

	}

}