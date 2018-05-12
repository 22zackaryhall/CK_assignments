#include <iostream>
#include <conio.h>

#define Enter 13	//Enter키의 ASCII값인 13을 상수로 선언

using namespace std;

int main() {
	
	int digitcount, ecount, input, ainput, min, max, tcount, i, score;
	char output = 0;
	digitcount = 0; ecount = 0; input = 0; ainput = 0;
	min = 0; max = 0; tcount = 0; i = 0; score = 0;

	cout << "<Up and Down 숫자 맞히기 게임입니다.>" << endl <<
		"당신은 출제자 입니다." << endl <<
		"정답이 될 정수를 입력하고 엔터(Enter)를 누르세요." << endl <<
		"정답이 될 정수를 입력하여 주세요(0~9999 사이의 값) : ";

	while (true) {		//답이 될 정수를 출제자가 적기 위한 반복문
		char input1 = getch();		//첫 번째 값
		if (input1 >= '0' && input1 <= '9') {
			cout << "*";
			digitcount++;		//자릿수를 확인하기 위한 값

			if (digitcount == 1) {
				char input2 = getch();		//두 번째 값
				if (input2 >= '0' && input2 <= '9') {
					cout << "*";
					digitcount++;

					if (digitcount == 2) {
						char input3 = getch();		//세 번째 값
						if (input3 >= '0' && input3 <= '9') {
							cout << "*";
							digitcount++;

							if (digitcount == 3) {
								char input4 = getch();		//네 번째 값
								if (input4 >= '0' && input4 <= '9') {
									cout << "*";
									digitcount++;

									if (digitcount >= 4) {		//네 번째 값을 입력하면 더이상의 입력을 강제 종료
										input = (input1 - '0') * 1000 + (input2 - '0') * 100 + (input3 - '0') * 10 + (input4 -'0');
										//정답이 4자리일 때 경우 정답을 ASCII 값 에서 숫자로 변환
										break;
									}
								}
								else if (input4 == Enter) {
									input = (input1 - '0') * 100 + (input2 - '0') * 10 + (input3 - '0');
									//정답이 3자리일 때 경우 정답을 ASCII 값 에서 숫자로 변환
									break;
								}
								else { ecount++; break; }
								//ecount는 입력에 에러가 있었는지 판별하기 위한 변수
							}
						}
						else if (input3 == Enter) {
							input = (input1 - '0') * 10 + (input2 - '0');
							//정답이 2자리일 때 경우 정답을 ASCII 값 에서 숫자로 변환
							break;
						}
						else { ecount++; break; }
					}
				}
				else if (input2 == Enter) {
					input = (input1 - '0');
					//정답이 1자리일 때 경우 정답을 ASCII 값 에서 숫자로 변환
					break;
				}
				else { ecount++; break; }
			}
		}
		else if (input1 == Enter) {
			ecount++; break;
		}

	}

	if (ecount > 0) {	//올바르지 않은 입력으로 ecount가 1이상인 경우 강제종료
		cout << endl << "올바르지 않은 입력입니다." << endl;
		return 0;
	}
	else {	//입력한 정답이 올바를 경우 게이머가 보기 편하도록 화면 정리
		system("cls");
		cout << "<Up and Down 숫자 맞히기 게임입니다.>" << endl << endl <<
		"정답은 " << digitcount << " 자리 숫자이며, " << endl;
	}

	switch (digitcount) {	//자리수에 따라서 입력 시도횟수와 최댓값을 다르게 할당
	case 1: tcount = 5; max = 9; break;
	case 2: tcount = 10; max = 99; break;
	case 3: tcount = 20; max = 999; break;
	case 4: tcount = 25; max = 9999; break;
	}

	cout << " '" << min << "' 부터 '" << max << "' 사이의 정수 입니다!" << endl <<
		"정답을 입력할 기회는 정답의 자릿수에 맞추어 총 '" << tcount << "' 회 주어집니다!" << endl <<
		"참여자 여러분, 정답을 맞추어 보세요!" << endl << endl;

	for (i = 0; i <= tcount - 1; i++) {	//게이머가 최대 시도 횟수 안에서 입력하도록 허용

WrongValue:		//만약 주어진 값에서 벗어난 값을 입력하였을 경우 횟수를 보존한 채 재입력 허용
		printf("[%d/%d] %d ~ %d 사이의 값 : ", i + 1, tcount, min, max);

		cin >> ainput;		//게이머가 입력한 수를 ainput에 저장

		if (ainput == input) {	//정답을 맞추었을 경우 for 루프에서 벗어남.
			printf("정답입니다!\n출제자가 정한 답은 '%d' 였습니다!\n", input);
			break;
		}
		else if (ainput > input) {	//입력값이 정답이 아닐경우 정답보다 높은지 낮은지 검사

			if (ainput < min || ainput > max) {
				printf("%d ~ %d 사이의 값이 아니네요!\n\n", min, max);
				goto WrongValue;	//주어진 값에서 벗어났을 경우 횟수 카운트 없이 입력기회제공
			}
			else {
				if (i < tcount-1) {	//정답보다 큰 값을 입력하였을 경우
					cout << "정답보다 큰 값 입니다. 더 낮은 수를 노려봅시다" << endl << endl;
				}
				else {	//주어진 기회를 모두 소진하였을 경우
					cout << "주어진 기회가 더이상 없네요..." << endl << endl;
				}
				max = ainput;	//입력받은 값이 정답보다 클 경우 max값에 ainput값을 대입
			}
		}
		else {

			if (ainput < min || ainput > max) {
				printf("%d ~ %d 사이의 값이 아니네요!\n\n", min, max);
				goto WrongValue;	//주어진 값에서 벗어났을 경우 횟수 카운트 없이 입력기회제공
			}
			else {
				if (i < tcount-1) {	//정답보다 적은 값을 입력하였을 경우
					cout << "정답보다 적은 값 입니다. 더 큰 수를 노려봅시다" << endl << endl;
				}
				else {	//주어진 기회를 모두 소진하였을 경우
					cout << "주어진 기회가 더이상 없네요..." << endl << endl;
				}
				min = ainput;	//입력받은 값이 정답보다 적을 경우 min값에 ainput값을 대입
			}
		}
	}

	score = 100 - (i * (100 / tcount));	//사용한 횟수와 자릿수를이용하여 0~100점까지 점수를 냄

	cout.precision(0);
		cout << endl << "[결과] 총 '" << tcount << "' 만큼의 주어진 횟수에서 '" << i <<
			"' 회 틀렸으므로, 최종적인 점수는 '" << score << "' 점 입니다." << endl;

	return 0;
}