typedef struct LifeEntity {

}LifeEntity;
	struct Player {

		char name[16];

		//게이지
		short MAX_HP = 100;
		short HP = 100;
		short MAX_MP = 20;
		short MP = 20;
		short MAX_Exp = 20;
		short Exp = 0;

		//스텟
		short strength = 5;
		short agility = 3;
		short defence = 2;

		//소속 및 상태
		bool isUndead = false;
		bool dead = false;
		bool isCorrupted = false;
	};

	typedef struct Enemy {

		char name[16];

		//게이지
		short MAX_HP = 20;
		short HP = 20;
		short MAX_MP = 10;
		short MP = 10;
		short MAX_Exp = 20;
		short Exp = 0;

		//스텟
		short strength = 2;
		short agility = 2;
		short defence = 1;

		//소속 및 상태
		bool isUndead = false;
		bool dead = false;
		bool isCorrupted = true;
	}ENEMY;
	
	extern struct Player player; //전역구조체 선언 (extern : 컴파일러에게 해당 메모리는 외부파일에서도 접근할수 있게 허용시킴)
	static ENEMY enemy;