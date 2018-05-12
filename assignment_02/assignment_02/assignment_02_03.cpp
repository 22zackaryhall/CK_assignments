#include <iostream>

using namespace std;

int main() {

	int choice, Height, width, length;

START:
	choice = 0; Height = 0; width = 0; length = 0;


	cout << "'*' 를 이용하여 도형을 만드는 프로그램입니다." << endl <<
		"4가지 형태 중 한 가지를 선택해 주세요" << endl <<
		"[1] 삼각형	[2] 역삼각형" << endl <<
		"[3] 마름모	[4] 사각형" << endl << endl <<
		"선택 : ";
	cin >> choice;	//어떤 도형식을 사용할 지 선택한 값을 choice값에 대입
	cout << endl;
	switch (choice) {	//앞서 선택한 도형식중 무엇을 사용하는지 알림
	case 1: cout << "선택한 도형은 삼각형 입니다." << endl; break;
	case 2: cout << "선택한 도형은 역삼각형 입니다." << endl; break;
	case 3: cout << "선택한 도형은 마름모 입니다." << endl; break;
	case 4: cout << "선택한 도형은 사각형 입니다." << endl; break;
	default: cout << "주어진 수(1~4) 를 입력해주세요!" << endl; //1~4이외의 값을 입력하였을 경우 콘솔을 정리하고 선택으로 돌아 감
		_sleep(1000);
		system("cls");
		goto START;
	}
	
	switch (choice) {	//앞서 선택한 도형식을 실행
	case 1:
		cout << "삼각형의 높이를 설정해 주십시오." << endl <<
			"높이 : ";
		cin >> Height;	//입력 받은 높이를 Height값에 대입
		for (int i = 1; i <= Height; i++) {	//Height값 따라 실행횟수를 제한
			for (int b = 0; b < Height - i; b++) {	//Height-1 만큼 공백을 출력
				cout << " ";
			}
			for (int ast = 0; ast < i; ast++) {	//i값 만큼  '* '을 출력
				cout << "* ";
			}
			cout << endl;

		}
		break;

	case 2:
		cout << "역삼각형의 높이를 설정해 주십시오." << endl <<
			"높이 : ";
		cin >> Height;
		for (int i = 0; i <= Height; i++) {
			for (int b = 0; b <= i; b++) {	//i값 만큼 공백을 출력
				cout << " ";
			}
			for (int ast = 0; ast < Height - i; ast++) {	//Height - i값 만큼  '* '을 출력
				cout << "* ";
			}
			cout << endl;
		}
		break;

	case 3:
		cout << "마름모의 높이를 설정해 주십시오." << endl <<
			"높이 : ";
		cin >> Height;
		for (int i = 1; i <= Height; i++) {
			for (int b = 0; b <= Height - i; b++) {	//Height - i 만큼 공백을 출력
				cout << " ";
			}
			for (int ast = 0; ast < i; ast++) {	//i값 만큼  '* '을 출력
				cout << "* ";
			}
			cout << endl;
		}	//삼각형 식이 끝난 후 역삼각형 식을 실행
		for (int i = 1; i <= Height; i++) {
			for (int b = 0; b <= i; b++) {	//i값 만큼 공백을 출력
				cout << " ";
			}
			for (int ast = 0; ast < Height - i; ast++) {	//Height - i값 만큼  '* '을 출력
				cout << "* ";
			}
			cout << endl;
		}
		break;

	case 4:
		cout << "사각형의 가로와 세로를 설정해 주십시오." << endl <<
			"가로 : ";
		cin >> width;	//입력 받은 가로 값을 width값에 대입

		cout << "세로 : ";
		cin >> length;	//입력 받은 세로 값을 length값에 대입

		for (int i = 1; i <= length; i++) {	//length값 만큼 반복
			for (int ast = 1; ast <= width; ast++) { // width값 많음 '* '을 출력
				cout << "* ";
			}
			cout << endl;
		}
		cout << endl;
		break;
	}

	cout << endl << "처음으로 돌아가서 다른 도형도 보시겠습니까?" << endl <<
		"[1]	예	[2]	아니요" << endl;
	cin >> choice;	//처음으로 돌아갈지 종료할지 선택

	if (choice == 1) {	//콘솔을 정리하고 처음으로 돌아 감
		_sleep(500);
		system("cls");
		goto START;
	}
	else
	{
		//프로그램을 종료함
	}

	return 0;
}