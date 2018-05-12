#include <iostream>

#define yts 31536000	// 1년은 31536000초
#define dts 86400		// 1일은 86400초
#define hts 3600		// 1시간은 3600초
#define mts 60		// 1분은 60초
				// 입력받은 시간에서 각자 할당되는 만큼을 나누기 위한 상수선언.

using namespace std;

int main() {

	unsigned __int64 intime;	// 음수는 입력받을 필요가 없으므로 unsigned를 사용
	int ytime, rytime, dtime, rdtime, htime, rhtime, mtime, stime;
	bool reset;		// 계산이 끝난 후 처음으로 돌아오기 위한 분기선택값

start:
	intime, ytime, rytime, dtime, rdtime, htime, rhtime, mtime, stime = 0;
	reset = 0;

	cout << "<초 단위를 입력하시면 시,분,초 로 정리하는 프로그램>" << endl <<
		"정리할 시간은 몇 초 입니까? : ";
	cin >> intime;
	if (intime <= 0) {	// 0이하의 시간은 올바르지 않음으로 오류처리
		cout << "올바르지 않은 시간입니다." << endl;
		cout << "초 정리기를 재시작 합니다." << endl;
		_sleep(1500);
		system("cls");
		goto start;		// 화면을 정리하고 처음으로 돌아감
		
	}
	cout << "입력된 시간은 " << intime << " 초 입니다." << endl;
	

	ytime = intime / yts;		// 연(년) =  입력받은 시간을 상수선언한 yts값을 이용하여 나눈 값
	rytime = intime % yts;		// 나머지 연(년) = 연(년) 값을 계산한 후 남은 값
	dtime = rytime / dts;		// 일 = 나머지 연(년) 값에 상수 dts를 나눈 값
	rdtime = rytime % dts;		// 나머지 일 = 일 값을 계산한 후 남은 값
	htime = rdtime / hts;		// 시 = 나머지 일 값을 상수 hts로 나눈 값
	rhtime = rdtime % hts;		// 나머지 시 = 시 값을 계산한 후 남은 값
	mtime = rhtime / mts;		// 분 = 나머지 시 값을 상수 mts로 나눈 값
	stime = rhtime % mts;		// 초 = 분 값을 계산한 후 남은 값은 초.

	cout << endl << "계산된 시간은 ";

	if (ytime > 0) {		// if문을 사용하여 깔끔하게 0보다 큰 값만 출력되도록 함.
		cout << ytime << " 년 ";
	}
	if (dtime > 0) {
		cout << dtime << " 일 ";
	}
	if (htime > 0) {
		cout << htime << " 시 ";
	}
	if (mtime > 0) {
		cout << mtime << " 분 ";
	}
	if (stime > 0) {
		cout << stime << " 초 ";
	}
	cout << "입니다." << endl;

	cout << "다시 계산하시려면 1 을 입력해 주십시요." << endl;
	cin >> reset;		// 프로그램을 종료하지 않고 다시 사용하기 위해 분기 선택값을 받음

	if (reset == 1) {		// 분기 선택값이 1 이라면 시작지점으로 돌아감.
		cout << "초 정리기를 재시작 합니다." << endl;
		_sleep(1500);
		system("cls");
		goto start;
	}

	else {		// 분기 선택값이 1 이 아니라면 오류처리하며 프로그램을 정지함.
		cout << "올바르지 않은 입력입니다." << endl << "프로그램을 종료합니다..." << endl;
	}



	return 0;
}