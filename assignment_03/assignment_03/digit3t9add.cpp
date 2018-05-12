#include "Games.h"

static int NumGames = 0, NumWins = 0;
static double Score = 0;
extern double tElapsed;

static bool playdigit3t9addOnce()
{
	static int a = 0, b = 0;
	static long rMax = 0, rMin = 0, Digit = 0;
	switch (cChoice)
	{
	case 3: rMax = 999, rMin = 100; break;
	case 4: rMax = 9999, rMin = 1000; break;
	case 5: rMax = 99999, rMin = 10000; break;
	case 6: rMax = 999999, rMin = 100000; break;
	case 7: rMax = 9999999, rMin = 1000000; break;
	case 8: rMax = 99999999, rMin = 10000000; break;
	case 9: rMax = 999999999, rMin = 100000000; break;
	}
	a = (double)rand() / (RAND_MAX + 1)*(rMax - rMin) + rMin;
	b = (double)rand() / (RAND_MAX + 1)*(rMax - rMin) + rMin;

	int result;

	NumGames++;
	printf("[문제%2d]: %9d + %9d = ", NumGames, a, b);
	scanf("%d", &result);
	if (result == a + b) {
		NumWins++;
	}
	return (result == a + b);
}
double playdigit3t9add(int nPlay)
{
	NumGames = 0;	//게임 횟수
	NumWins = 0;	//정답 개수
	Score = 0;	//최종 점수
	tElapsed = 0;	//모든 문제를 푸는 데 걸린 시간
	clock_t t0 = clock();	//게임이 시작된 시각을 기록
	for (int i = 0; i < nPlay; i++) {
		if (playdigit3t9addOnce() == false) {
			printf("\t틀렸습니다.\n");	//오답일 경우 출력
		}
		else {
			printf("\t정답입니다.\n");	//정답일 경우 출력
		}
	}
	static double tTemp = 0;
	switch (cChoice)	//자리수 별로 시간을 다르게 부여
	{
	case 3: tTemp = 5.0; break;
	case 4: tTemp = 5.0; break;	
	case 5: tTemp = 10.0; break;
	case 6: tTemp = 10.0; break;
	case 7: tTemp = 20.0; break;
	case 8: tTemp = 20.0; break;
	case 9: tTemp = 20.0; break;
	}

	clock_t t1 = clock();	//게임이 끝난 시각을 기록
	tElapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;	//위의 두 시각으로 경과시간 계산(초)
	Score = (NumGames > NumWins) ? 0.0
		: 100 * (tTemp * NumGames - tElapsed) / (tTemp * NumGames);
	return Score;
}