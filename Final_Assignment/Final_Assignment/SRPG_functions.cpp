#include "SRPG.h"


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

void bAttack() {

	cout << player.name << "��(��) " << enemy.name << "��(��) ����!" << endl;
	enemy.HP -= ((player.strength * 2) - (enemy.defence));
	cout << enemy.name << "��(��) " << ((player.strength * 2) - (enemy.defence)) << "��ŭ�� �������� �Ծ���!" << endl;

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
	cout << "! ���� !" << endl << endl;
	while (enemy.HP > 0 || player.HP > 0 || battleEnd != true) {
		cout << " HP " << player.HP << " / " << player.MAX_HP << "   MP " << player.MP << " / " << player.MAX_MP << endl;
		cout << "����� ���� �Դϴ�." << endl <<
			"[1] ����   [2] ���   [3] ������   [4] ����" << endl;
		pChoice = getNums(4);
		switch (pChoice) {
		case 1: bAttack(); break;
		case 2: bDefence(); break;
		case 3: bItem(); break;
		case 4: bRunaway(); break;
		}
	}
}

