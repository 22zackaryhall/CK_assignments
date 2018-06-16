#include "SRPG.h"

void main() {
	system("mode con:cols=60 lines=30");
	while (true) { 
		cout << "\t이 게임은 'Consolas' 폰트에 최적화 되어있습니다." << endl << endl << endl << endl <<
			"\t ┌───────────────────────────────────────┐" << endl <<
			"\t │    _/_/_/  _/_/_/    _/_/_/     _/_/_/│" << endl <<
			"\t │  _/       _/    _/  _/    _/  _/      │" << endl <<
			"\t │   _/_/   _/_/_/    _/_/_/    _/  _/_/ │" << endl <<
			"\t │      _/ _/    _/  _/        _/    _/  │" << endl <<
			"\t │_/_/_/  _/    _/  _/          _/_/_/   │" << endl <<
			"\t └───────────────────────────────────────┘" << endl <<
			"\t              ~The Simple RPG~" << endl << endl << endl << endl << endl << endl <<
			"\t               ┼────────────┼" << endl <<
			"\t                [1] 게임시작" << endl <<
			"\t                [2] 불러오기" << endl <<
			"\t                [3]  크레딧" << endl <<
			"\t                [4] 게임종료" << endl <<
			"\t               ┼────────────┼" << endl << endl <<
			"\t";
		switch (getNums(4))
		{
		case 1: SRPG_page1(); break;
		case 2:  break;
		case 3: SRPG_Credits(); break;
		default:
			exit(0);
			break;
		}
	}
}