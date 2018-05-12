#include "Games.h"

static int NumGames = 0, NumWins = 0;	//문제의 개수와 정답수 카운트
static double Score = 0;	//점수
double tElapsed;	//경과시간 변수

static bool playGugu()
{
	static int a = 0, b = 0;

	switch (cChoice)
	{
	case 1:	//한 자리 수 곱셈
		a = rand() % 8 + 2;
		b = rand() % 8 + 2;
		break;
	case 2:	//두 자리 수 곱셈
		a = rand() % 98 + 2;
		b = rand() % 98 + 2;
		break;

	}

	int result;

	NumGames++;	//몇번째 문제인지 카운트
	printf("[문제%2d]: %2d x %2d = ", NumGames, a, b);
	scanf("%d", &result);
	if (result == a * b) {
		NumWins++;
	}
	return (result == a * b);
}
double playSpeedGugu(int nPlay)
{
	NumGames = 0;	//게임 횟수
	NumWins = 0;	//정답 개수
	Score = 0;	//최종 점수
	tElapsed = 0;	//모든 문제를 푸는 데 걸린 시간
	clock_t t0 = clock();	//게임이 시작된 시각을 기록
	for (int i = 0; i < nPlay; i++) {
		if (playGugu() == false) {
			printf("\t틀렸습니다.\n");	//오답일 경우 출력
		}
		else {
			printf("\t정답입니다.\n");	//정답일 경우 출력
		}
	}
	static double tTemp = 0;
	switch (cChoice)	//자리수 별로 시간을 다르게 부여
	{
	case 1: tTemp = 5.0; break;	//스피드 구구단용
	case 2: tTemp = 10.0; break;	//두 자리 수 곱셈용
	}

	clock_t t1 = clock();	//게임이 끝난 시각을 기록
	tElapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;	//위의 두 시각으로 경과시간 계산(초)
	Score = (NumGames > NumWins) ? 0.0
		: 100 * (tTemp * NumGames - tElapsed) / (tTemp * NumGames);
	return Score;
}