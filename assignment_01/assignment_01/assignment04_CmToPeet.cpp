#include <iostream>
#include <cmath>		// double값의 나머지를 구하기 위해 수학함수를 사용

using namespace std;


int main() {

	double cm, feet, inch, rinch, fti;
	int manswer, ianswer01, ianswer02;
Main:
	cm, feet, inch, rinch, fti = 0;
	manswer, ianswer01, ianswer02 = 0;

	system("cls");
	cout << "<cm <=> feet,inch 변환 프로그램>" << endl <<
		"[무슨 변환법을 사용하시겠습니까?]" << endl <<
		"[1] cm \t\t=> feet,inch" << endl <<
		"[2] feet,inch\t=> cm" << endl;
	cin >> manswer;		// 앞서 출력된 변환법 둘 중 하나의 번호를 입력하면 manswer 값에 저장

	if (manswer == 1) {	// manswer값에 1을 입력받으면 cm -> feet, inch 변환으로 진입
	CMtFI:
		rinch, feet, inch = 0;

		system("cls");
		cout << "[cm => feet,inch 변환]" << endl <<
			"변환할 cm : ";
		cin >> cm;
		rinch = cm / 2.54;	// 2.54cm = 1inch 이므로 cm를 2.54로 나누면 rinch값이 됨
		feet = rinch / 12;	// 12inch는 1feet이므로 rinch값에 12를 나누면 feet값이 나옴
		inch = fmod(rinch, 12.00);	// feet를 계산한 후 남은 값은 inch 이므로 rinch값과 12의 나머지를 구하면 inch값이 나옴
		
		
		cout.precision(2);	// 소수점 1자리수까지 표현
		cout << (int)feet << " feet " << inch << " inch 입니다." << endl << endl <<
			"[1] 다시 변환하기" << endl <<
			"[2] 메인으로 돌아가기" << endl;

		rinch = 0;

		cin >> ianswer01;	// 변환을 다시 시작할지 처음으로 돌아갈지 선택한 값이 ianswer01에 저장
		if (ianswer01 == 1) {
			ianswer01 = 0;
			goto CMtFI;	// ianswer01에 1이 입력되면 cm -> feet, inch 변환 시작지점으로 감
		}
		else {
			goto Main; // ianswer01에 1이 아닌 값이 입력되면 처음 화면으로 돌아감
		}
		
	}
	else if (manswer == 2){	// manswer 값에 2를 입력받았을 경우 feet, inch -> cm 변환으로 진입
	FItCM:
		feet, inch, cm = 0;

		system("cls");
		cout << "[feet,inch => cm 변환]" << endl <<
			"변환할 feet : ";
		cin >> feet;
		cout << "변환할 inch : ";
		cin >> inch;

		cm = feet * 30.48 + inch * 2.54;	//1feet는 30.48cm와 같고 1inch는 2.54cm와 같음

		cout << endl << cm << "cm 입니다." << endl <<
			"[1] 다시 변환하기" << endl <<
			"[2] 메인으로 돌아가기" << endl;

		cin >> ianswer02;	// 변환을 다시 시작할지 처음으로 돌아갈지 선택한 값이 ianswer02에 저장
		if (ianswer02 == 1) {
			ianswer02 = 0;
			goto FItCM;	// ianswer02에 1이 입력되면 feet, inch -> cm 변환 시작지점으로 감
		}
		else {
			goto Main;	// ianswer02에 1이 아닌 값이 입력되면 처음 화면으로 돌아감
		}

	}
	else {	// manswer 값에 1과 2 이외의 값을 입력받으면 오류처리 후 처음으로 돌아감
		cout << "올바른 선택이 아닙니다." << endl;
		_sleep(1500);
		goto Main;
	}


	return 0;
}