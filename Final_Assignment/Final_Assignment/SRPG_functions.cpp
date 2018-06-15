#include "SRPG.h"


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

void bAttack() {

	cout << player.name << "이(가) " << enemy.name << "을(를) 공격!" << endl;
	enemy.HP -= ((player.strength * 2) - (enemy.defence));
	cout << enemy.name << "은(는) " << ((player.strength * 2) - (enemy.defence)) << "만큼의 데미지를 입었다!" << endl;

}

void bDefence() {



}

void bItem() {



}

void bRunaway() {



}

void Battle() {

	int pChoice = 1, eChoice = 1;
	bool battleEnd = false;

	system("cls");
	cout << "! 교전 !" << endl << endl;
	while (enemy.HP > 0 || player.HP > 0 || battleEnd != true) {
		cout << " HP " << player.HP << " / " << player.MAX_HP << "   MP " << player.MP << " / " << player.MAX_MP << endl;
		cout << "당신의 차례 입니다." << endl <<
			"[1] 공격   [2] 방어   [3] 아이템   [4] 도망" << endl;
		pChoice = getNums(4);
		switch (pChoice) {
		case 1: bAttack(); break;
		case 2: bDefence(); break;
		case 3: bItem(); break;
		case 4: bRunaway(); break;
		}
	}
}

