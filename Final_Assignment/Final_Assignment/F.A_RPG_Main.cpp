#include "F.A_RPG.h"

void main() {
	system("mode con:cols=60 lines=30");
	while (true) {
		int MChoice = 1;
		cout << endl << endl << endl << endl <<
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
			"\t      키보드에서 숫자키(1~4)로 선택하세요" << endl;
		MChoice = getch();

		switch (MChoice)
		{
		case 1:
		case 2:
		case 3:
		default:
			exit(0);
			break;
		}
	}
}