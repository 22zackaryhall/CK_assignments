#include "Games.h"

void Gugu() {
	srand((unsigned)time(NULL));	//���� ���������� �ð��� �̿��� �õ�� ����
	extern int cChoice;	//cChoice�� �ҷ��ͼ� ���
	int choice = 0;
	while (true) {
		int nPlay = 10;	//�ִ� ���� Ƚ��
		switch (cChoice)
		{
		case 1: printf("[���ǵ� ������]\n"); break;
		case 2: printf("[�� �ڸ� �� ����]\n"); break;
		case 3: printf("[%d �ڸ��� ����]\n", cChoice); break;
		case 4: printf("[%d �ڸ��� ����]\n", cChoice); break;
		case 5: printf("[%d �ڸ��� ����]\n", cChoice); break;
		case 6: printf("[%d �ڸ��� ����]\n", cChoice); break;
		case 7: printf("[%d �ڸ��� ����]\n", cChoice); break;
		case 8: printf("[%d �ڸ��� ����]\n", cChoice); break;
		case 9: printf("[%d �ڸ��� ����]\n", cChoice); break;
		}
		cout << "����� ����ɷ��� ������� �Դϱ�?" << endl <<
			"������ �� 10�� ����˴ϴ�." << endl <<
			"�غ� �ǽø� ����(Enter)Ű�� ��������!" << endl;
		getchar();
		getchar();
		system("cls");
		double score = 0;
		if (cChoice == 1 || cChoice == 2) {	//1~2�� �������� ��� ����
			score = playSpeedGugu(nPlay);
		}
		else if (cChoice >= 3 && cChoice <= 9) {	//3~9�� �������� ��� ����
			score = playdigit3t9add(nPlay);
		}
		printf("\n���� = %4.1f��(�� %4.1f��)\n\n", score, tElapsed);
		cout << "�ٽ� �ϰڽ��ϱ�?" << endl <<
			"[1] ��" << endl <<
			"[2] ��������" << endl <<
			"[3] ������ ����" << endl;
		cin >> choice;
		
		if (choice == 2) {
			system("cls");
			break;
		}
		else if (choice == 3) {
			exit(0);
		}
		else {
			system("cls");
		}

	}

}