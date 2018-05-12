#include <iostream>

using namespace std;

int main() {

	short innumber, cD1, cD2, cD3, rcD3, cD4, rcD4;
	bool restart;

start:
	innumber, cD1, cD2, cD3, rcD3, cD4, rcD4 = 0;
	restart = 0;
	
	cout << "<10000보다 작은 수를 입력받아서 자릿수를 나누는 프로그램>" << endl <<
		"ex) 9536입력 -> 천의 자리 9, 백의 자리 5, 십의 자리 3, 일의 자리 6" << endl <<
		"1~9999사이의 숫자를 입력하십시요 : ";

	cin >> innumber;

	if ((innumber < 10000) && (innumber > 0)) {		//입력이 10000보다 작고 0보다 클때 계산 시작
		cout << "입력받은 수는 " << innumber << " 입니다." << endl;

		cD4 = innumber / 1000;	// 천의 자리수를 얻기 위해 입력 값에 1000을 나눔
		rcD4 = innumber % 1000;
		cD3 = rcD4 / 100; // 백의 자리수를 얻기 위해 남은 값에 100을 나눔
		rcD3 = rcD4 % 100;
		cD2 = rcD3 / 10;	// 십의 자리수를 얻기 위해 남은 값에 10을 나눔
		cD1 = rcD3 % 10;	// 십을 자리수를 얻은 후 남은 값은 1의 자리수임 

		cout << "천의 자리수 : " << cD4 << endl <<
			"백의 자리수 : " << cD3 << endl <<
			"십의 자리수 : " << cD2 << endl <<
			"일의 자리수 : " << cD1 << endl;
	}
	else {		//입력이 1~9999 사이의 수가 아닐 때 오류처리
		cout << "올바르지 않은 입력입니다." << endl <<
			"처음으로 돌아갑니다." << endl;
		_sleep(1500);
		system("cls");
		goto start;
	}

	cout << "자리수 정렬기를 재시작 하시려면 1을 입력해 주십시요." << endl;
	cin >> restart;
	
	if (restart == 1) {
		cout << "자리수 정렬기를 재시작 합니다." << endl;
		_sleep(1500);
		system("cls");
		goto start;
	}
	else {
		cout << "잘못된 입력입니다." << endl <<
			"프로그램을 종료합니다." << endl;
	}


	return 0;
}