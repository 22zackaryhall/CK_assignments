#include <iostream>

#define yts 31536000	// 1���� 31536000��
#define dts 86400		// 1���� 86400��
#define hts 3600		// 1�ð��� 3600��
#define mts 60		// 1���� 60��
				// �Է¹��� �ð����� ���� �Ҵ�Ǵ� ��ŭ�� ������ ���� �������.

using namespace std;

int main() {

	unsigned __int64 intime;	// ������ �Է¹��� �ʿ䰡 �����Ƿ� unsigned�� ���
	int ytime, rytime, dtime, rdtime, htime, rhtime, mtime, stime;
	bool reset;		// ����� ���� �� ó������ ���ƿ��� ���� �б⼱�ð�

start:
	intime, ytime, rytime, dtime, rdtime, htime, rhtime, mtime, stime = 0;
	reset = 0;

	cout << "<�� ������ �Է��Ͻø� ��,��,�� �� �����ϴ� ���α׷�>" << endl <<
		"������ �ð��� �� �� �Դϱ�? : ";
	cin >> intime;
	if (intime <= 0) {	// 0������ �ð��� �ùٸ��� �������� ����ó��
		cout << "�ùٸ��� ���� �ð��Դϴ�." << endl;
		cout << "�� �����⸦ ����� �մϴ�." << endl;
		_sleep(1500);
		system("cls");
		goto start;		// ȭ���� �����ϰ� ó������ ���ư�
		
	}
	cout << "�Էµ� �ð��� " << intime << " �� �Դϴ�." << endl;
	

	ytime = intime / yts;		// ��(��) =  �Է¹��� �ð��� ��������� yts���� �̿��Ͽ� ���� ��
	rytime = intime % yts;		// ������ ��(��) = ��(��) ���� ����� �� ���� ��
	dtime = rytime / dts;		// �� = ������ ��(��) ���� ��� dts�� ���� ��
	rdtime = rytime % dts;		// ������ �� = �� ���� ����� �� ���� ��
	htime = rdtime / hts;		// �� = ������ �� ���� ��� hts�� ���� ��
	rhtime = rdtime % hts;		// ������ �� = �� ���� ����� �� ���� ��
	mtime = rhtime / mts;		// �� = ������ �� ���� ��� mts�� ���� ��
	stime = rhtime % mts;		// �� = �� ���� ����� �� ���� ���� ��.

	cout << endl << "���� �ð��� ";

	if (ytime > 0) {		// if���� ����Ͽ� ����ϰ� 0���� ū ���� ��µǵ��� ��.
		cout << ytime << " �� ";
	}
	if (dtime > 0) {
		cout << dtime << " �� ";
	}
	if (htime > 0) {
		cout << htime << " �� ";
	}
	if (mtime > 0) {
		cout << mtime << " �� ";
	}
	if (stime > 0) {
		cout << stime << " �� ";
	}
	cout << "�Դϴ�." << endl;

	cout << "�ٽ� ����Ͻ÷��� 1 �� �Է��� �ֽʽÿ�." << endl;
	cin >> reset;		// ���α׷��� �������� �ʰ� �ٽ� ����ϱ� ���� �б� ���ð��� ����

	if (reset == 1) {		// �б� ���ð��� 1 �̶�� ������������ ���ư�.
		cout << "�� �����⸦ ����� �մϴ�." << endl;
		_sleep(1500);
		system("cls");
		goto start;
	}

	else {		// �б� ���ð��� 1 �� �ƴ϶�� ����ó���ϸ� ���α׷��� ������.
		cout << "�ùٸ��� ���� �Է��Դϴ�." << endl << "���α׷��� �����մϴ�..." << endl;
	}



	return 0;
}