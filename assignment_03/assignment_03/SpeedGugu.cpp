#include "Games.h"

static int NumGames = 0, NumWins = 0;	//������ ������ ����� ī��Ʈ
static double Score = 0;	//����
double tElapsed;	//����ð� ����

static bool playGugu()
{
	static int a = 0, b = 0;

	switch (cChoice)
	{
	case 1:	//�� �ڸ� �� ����
		a = rand() % 8 + 2;
		b = rand() % 8 + 2;
		break;
	case 2:	//�� �ڸ� �� ����
		a = rand() % 98 + 2;
		b = rand() % 98 + 2;
		break;

	}

	int result;

	NumGames++;	//���° �������� ī��Ʈ
	printf("[����%2d]: %2d x %2d = ", NumGames, a, b);
	scanf("%d", &result);
	if (result == a * b) {
		NumWins++;
	}
	return (result == a * b);
}
double playSpeedGugu(int nPlay)
{
	NumGames = 0;	//���� Ƚ��
	NumWins = 0;	//���� ����
	Score = 0;	//���� ����
	tElapsed = 0;	//��� ������ Ǫ�� �� �ɸ� �ð�
	clock_t t0 = clock();	//������ ���۵� �ð��� ���
	for (int i = 0; i < nPlay; i++) {
		if (playGugu() == false) {
			printf("\tƲ�Ƚ��ϴ�.\n");	//������ ��� ���
		}
		else {
			printf("\t�����Դϴ�.\n");	//������ ��� ���
		}
	}
	static double tTemp = 0;
	switch (cChoice)	//�ڸ��� ���� �ð��� �ٸ��� �ο�
	{
	case 1: tTemp = 5.0; break;	//���ǵ� �����ܿ�
	case 2: tTemp = 10.0; break;	//�� �ڸ� �� ������
	}

	clock_t t1 = clock();	//������ ���� �ð��� ���
	tElapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;	//���� �� �ð����� ����ð� ���(��)
	Score = (NumGames > NumWins) ? 0.0
		: 100 * (tTemp * NumGames - tElapsed) / (tTemp * NumGames);
	return Score;
}