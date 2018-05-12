#include <iostream>
#include <cmath>		//제곱계산을 쉽게 끝내기 위해 수학함수를 불러옴.
#define Pi 3.141592		//원주율을 상수로 정의.

using namespace std;

int main() {

	float radius, rsquare, diameter, circumference, Area;

start:		//프로그램 내에서 메인으로 돌아올 때의 시작점

	radius, rsquare, diameter, circumference, Area = 0;

	cout << "<원의 둘레와 면적을 구하는 프로그램>" << endl << endl;
	cout << "원의 반지름을 입력하여 주세요 : ";
	cin >> radius;

	if (radius <= 0) {		//입력받은 반지름의 값이 0과 같거나 작을때 오류처리.
		cout << "1 이상의 수를 입력하여 주십시요." << endl;
		_sleep(1500);		//안내를 화면에 출력 후 1500ms를 지연시켜서 확인시킴.
		system("cls");		//처음으로 돌아가기 전 콘솔의 글을 정리하여 깔끔하게 함.
		goto start;		//처음으로 돌아감
	}

	else (radius > 0); {		//입력받은 반지름의 값이 0보다 크면 계산시작
		cout << "입력받은 원의 반지름은 '" << radius << "' 입니다." << endl;

		rsquare = pow(radius, 2);		// 반지름의 2제곱을 수학함수(pow)로 계산
		diameter = radius * 2.0;		// 지름 = 반지름 * 2
		circumference = diameter * Pi;	// 둘레 = 지름 * 원주율
		Area = Pi * rsquare;			// 면적 = 원주율 * 반지름의 2제곱

		cout << "원의 지름: " << diameter << endl <<
			"원의 둘레: " << circumference<< endl <<
			"원의 면적: " << Area << endl;				//계산이 끝난 값들을 화면에 출력
	}


	return 0;
}