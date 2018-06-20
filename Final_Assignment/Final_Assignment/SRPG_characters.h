//�÷��̾�� �� �������� �⺻ ���� ����ü�� ����

typedef struct Player {

	char name[16];

	//������
	short MAX_HP = 100;
	short HP = 100;
	short MAX_AP = 20;
	short AP = 20;
	short MAX_Exp = 20;
	short Exp = 0;
	short Level = 1;

	//����
	short strength = 5;
	short agility = 3;
	short defence = 2;

	//�Ҽ� �� ����
	bool isUndead = false;
	bool dead = false;
	bool isCorrupted = false;	

}PLAYER;

typedef struct Enemy {

	char name[16];

	//������
	short MAX_HP = 20;
	short HP = 20;
	short MAX_AP = 10;
	short AP = 10;
	short Exp = 20;

	//����
	short strength = 2;
	short agility = 2;
	short defence = 1;

	//�Ҽ� �� ����
	bool isUndead = false;
	bool dead = false;
	bool isCorrupted = true;

}ENEMY;

extern struct Player player;
extern struct Enemy enemy;
extern struct attacker;
extern struct tt1;
extern struct tt2;