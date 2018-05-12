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
	printf("[����%2d]: %9d + %9d = ", NumGames, a, b);
	scanf("%d", &result);
	if (result == a + b) {
		NumWins++;
	}
	return (result == a + b);
}
double playdigit3t9add(int nPlay)
{
	NumGames = 0;	//���� Ƚ��
	NumWins = 0;	//���� ����
	Score = 0;	//���� ����
	tElapsed = 0;	//��� ������ Ǫ�� �� �ɸ� �ð�
	clock_t t0 = clock();	//������ ���۵� �ð��� ���
	for (int i = 0; i < nPlay; i++) {
		if (playdigit3t9addOnce() == false) {
			printf("\tƲ�Ƚ��ϴ�.\n");	//������ ��� ���
		}
		else {
			printf("\t�����Դϴ�.\n");	//������ ��� ���
		}
	}
	static double tTemp = 0;
	switch (cChoice)	//�ڸ��� ���� �ð��� �ٸ��� �ο�
	{
	case 3: tTemp = 5.0; break;
	case 4: tTemp = 5.0; break;	
	case 5: tTemp = 10.0; break;
	case 6: tTemp = 10.0; break;
	case 7: tTemp = 20.0; break;
	case 8: tTemp = 20.0; break;
	case 9: tTemp = 20.0; break;
	}

	clock_t t1 = clock();	//������ ���� �ð��� ���
	tElapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;	//���� �� �ð����� ����ð� ���(��)
	Score = (NumGames > NumWins) ? 0.0
		: 100 * (tTemp * NumGames - tElapsed) / (tTemp * NumGames);
	return Score;
}