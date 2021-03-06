#include "SRPG.h"
#include "SRPG_characters.h"

struct Player player;
struct Enemy enemy;

int SRPG_Prologue() {

	while (true) {
		getName();
		system("cls");
		return 0;
	}
}

//디버그용 스토리 스킵
#ifdef DEBUG

int SRPG_1st_sence() {

	return 0;
};

#endif // DEBUG


//릴리즈
#ifdef RELEASE
int SRPG_1st_sence() {
	PlayerReset();
	system("cls");
	cout << "시동중...";
	_sleep(2000);
	cout << endl << endl << "오류 - 시스템이 손상되었습니다.";
	_sleep(1000);
	cout << endl << "보조 저장소에서 주 저장소로 필수 시스템 복구중...";
	_sleep(2000);
	cout << endl << endl << "오류 - 주 저장소를 사용할 수 없습니다." << endl << 
		"보조 저장소에 보관된 시스템을 사용하여 응급 기동합니다.";
	_sleep(1000);
	cout << endl << endl << "성공 - 보조 저장소를 사용하여 응급 기동에 성공하였습니다.";
	_sleep(1000);
	cout << endl << endl << "자가 스캔 중...";
	_sleep(3000);
	cout << endl << "소속 - LfA.Rad";
	_sleep(1000);
	cout << endl << "AI - " << player.name;
	_sleep(1000);
	cout << endl << "Lv - " << player.Level;
	_sleep(1000);
	cout << endl << "HP - " << player.HP << "/" << player.MAX_HP;
	_sleep(1000);
	cout << endl << "MP - " << player.AP << "/" << player.MAX_AP;
	_sleep(1000);
	cout << endl << "Exp - " << player.Exp << "/" << player.MAX_Exp;
	_sleep(1000);
	cout << endl << "Condition - ";
	isCorrupted(player.isCorrupted);
	cout << endl << endl;
	_sleep(1000);
	cout << "스캔 결과 - 주 저장소 수리 필요.";
	_sleep(1000);
	cout << endl << "기체 상태 양호하지 못함." << endl << 
		"수리 및 업그레이드가 권장됨.";
	_sleep(1000);
	cout << endl << "기체 제어권을 시스템에서 '" << player.name << "' 으로 전환.";
	_sleep(2000);
	cout << endl << endl << "무기를 가진 적대적 대상과 조우." << endl <<
		"엔터(Enter)키를 눌러 교전합니다";
	getch();
	rewind(stdin);
	system("cls");
	return 0;
}
#endif // RELEASE

int SRPG_2nd_sence() {

	tt1Reset();
	Battle();
	cout << endl << "교전 대상에게서 로그데이터를 해킹하여 수집하였습니다." << endl;
	_sleep(1500);
	cout << endl << "로그데이터 분석 결과 멀지않은 지점에 베이스가 있는것을 확인 하였습니다." << endl;
	_sleep(1500);
	cout << endl << "최우선 목표 - 확인된 베이스의 좌표로 이동" << endl;
	_sleep(1500);

	walking(5,1);

	LfABaseFirst();

	CORDLINEEND();

	return 0;

}

//크레딧
void SRPG_Credits() {
	system("cls");
	cout << endl << endl << endl << endl <<
		"\t ┌───────────────────────────────────────┐" << endl <<
		"\t │    _/_/_/  _/_/_/    _/_/_/     _/_/_/│" << endl <<
		"\t │  _/       _/    _/  _/    _/  _/      │" << endl <<
		"\t │   _/_/   _/_/_/    _/_/_/    _/  _/_/ │" << endl <<
		"\t │      _/ _/    _/  _/        _/    _/  │" << endl <<
		"\t │_/_/_/  _/    _/  _/          _/_/_/   │" << endl <<
		"\t └───────────────────────────────────────┘" << endl <<
		"\t              ~The Simple RPG~" << endl << endl << endl <<
		"\t              ───────────────" << endl <<
		"\t                    제작" << endl <<
		"\t              ───────────────" << endl << endl <<
		"\t             201813113  김일수" << endl <<
		"\t                 (Cordion)" << endl << endl << endl <<
		"\t              청강 2018_1학기" << endl <<
		"\t     객체지향 프로그래밍 기초 기말과제" << endl << endl << endl <<
		"\t   엔터 키를 눌러 메인화면으로 돌아갑니다." << endl;
	getch();
	rewind(stdin);
	system("cls");
	main();
}