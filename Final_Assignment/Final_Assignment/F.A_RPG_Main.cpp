#include "F.A_RPG.h"

void main() {
	system("mode con:cols=60 lines=30");
	while (true) {
		int MChoice = 1;
		cout << endl << endl << endl << endl <<
			"\t ����������������������������������������������������������������������������������" << endl <<
			"\t ��    _/_/_/  _/_/_/    _/_/_/     _/_/_/��" << endl <<
			"\t ��  _/       _/    _/  _/    _/  _/      ��" << endl <<
			"\t ��   _/_/   _/_/_/    _/_/_/    _/  _/_/ ��" << endl <<
			"\t ��      _/ _/    _/  _/        _/    _/  ��" << endl <<
			"\t ��_/_/_/  _/    _/  _/          _/_/_/   ��" << endl <<
			"\t ����������������������������������������������������������������������������������" << endl <<
			"\t              ~The Simple RPG~" << endl << endl << endl << endl << endl << endl <<
			"\t               ����������������������������" << endl <<
			"\t                [1] ���ӽ���" << endl <<
			"\t                [2] �ҷ�����" << endl <<
			"\t                [3]  ũ����" << endl <<
			"\t                [4] ��������" << endl <<
			"\t               ����������������������������" << endl << endl <<
			"\t      Ű���忡�� ����Ű(1~4)�� �����ϼ���" << endl;
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