#include "SRPG.h"

void main() {
	system("mode con:cols=60 lines=30");
	while (true) { 
		cout << "\t�� ������ 'Consolas' ��Ʈ�� ����ȭ �Ǿ��ֽ��ϴ�." << endl << endl << endl << endl <<
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