#include <iostream>

using namespace std;

int main() {
	int choice, lvalue, rvalue, error, result;
	char Oper;
	while (true) {
		choice = 0; lvalue = 0; rvalue = 0; Oper = 0; error = 0; result = 0;

		cout << "두 수의 사칙연산을 수행해주는 간이 계산기입니다." << endl <<
			"무슨 사칙 연산을 사용하시겠습니까?" << endl <<
			"[1] 더하기 ( + )" << endl << "[2] 빼기 ( - )" << endl <<
			"[3] 곱하기 ( * )" << endl << "[4] 나누기 ( / )" << endl;
		cin >> choice;

		switch (choice) {	//  선택한 값으로 무슨 연산을 수행할지 선택
		case 1: Oper = '+'; break;	//Oper값에 연산자 + 를 대입
		case 2: Oper = '-'; break;	//Oper값에 연산자 - 를 대입
		case 3: Oper = '*'; break;	//Oper값에 연산자 * 를 대입
		case 4: Oper = '/'; break;	//Oper값에 연산자 / 를 대입
		default: error += 1; break;	//올바르지 않은 입력일 때 error값에 1을 더함
		}
		if (error > 0) {	//error값이 1이상일 경우 에러를 출력하며 처음으로 돌아 감
			cout << "ERROR!" << endl;
			_sleep(1000);
			system("cls");
			continue;
		}

		cout << "선택한 연산자는 '" << Oper << "' 입니다." << endl <<
			"해당 연산을 수행할 두 수를 입력하여 주세요." << endl <<
				"첫 번째 수 : ";
			cin >> lvalue;		//연산자의 왼쪽에 위치할 수

			cout << "두 번째 수 : ";
			cin >> rvalue;		//연산자의 오른쪽에 위치할 수

		switch (choice) {	//앞서 선택한 값에 따라 무슨 연산을 수행할 지 선택
		case 1: result = lvalue + rvalue; break;
		case 2: result = lvalue - rvalue; break;
		case 3: result = lvalue * rvalue; break;
		case 4: result = lvalue / rvalue; break;
			// 선택된 연산자에 따라 계산한 후 result 값에 대입
		}

	rechoice:
		cout << "[결과] " << lvalue << " " << Oper << " " << rvalue << " = " << result << endl << endl <<
			"처음으로 돌아가서 계산기를 재사용 합니까?" << endl <<
			"[1] 예" << endl << "[2] 아니요" << endl;
		cin >> choice;
		// 결과를 출력 후 계산기를 다시 사용할지 종료할지 선택
		
		if (choice == 1) {
			system("cls");
			continue;	//계산기를 다시 사용하기 위해 콘솔을 정리하고 처음으로 돌아 감
		}
		else if (choice == 2) {
			break;	//계산기를 종료함
		}
		else {	//1,2이외의 값을 입력했을 경우 오류로 처리하며 콘솔을 정리하고 선택창으로 돌아 감
			cout << "올바르지 않은 입력입니다." << endl;
			_sleep(1000);
			system("cls");
			goto rechoice;
		}

		}
	return 0;
}