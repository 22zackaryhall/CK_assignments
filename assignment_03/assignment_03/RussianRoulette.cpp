#include "Games.h"

int RussianRoullete() {
	//nPlayer == ���� ������ ��  //nBullets == ������ źȯ ��  //nCylinder == �ִ� ��ź��
	static int nPlayer = 0, nBullets = 0, nCylinder = 0;
	system("cls");
	cout << "[���þ� �귿]" << endl << endl;
	printf("���� �ο� (��: 3) ==> ");
	scanf("%d", &nPlayer);
	printf("źâ�� �ִ� ��ź�� (��: 6) == > ");
	scanf("%d", &nCylinder);
	while (true) {	//�ִ� ��ź�� ��� �Ѿ� ������ ���������� �� �ݺ�
		printf("������ �Ѿ� ������? (��: 2) == > ");
		scanf("%d", &nBullets);
		if (nCylinder < nBullets) {	//�Ѿ��� �ִ� ��ź���� �Ѿ ���
			printf("�ִ� ��ź��%d���� ���� �Ѿ�(%d)�� ������ ���� �����ϴ�!\n", nCylinder, nBullets);
		}
		else if (nCylinder >= nBullets) {	//�Ѿ��� �ִ� ��ź������ ���� ���
			system("cls");
			printf("���� �ο��� %d�� �̸� �ִ� ��ź���� %d, �����Ǿ��ִ� �Ѿ��� %d�� �Դϴ�.\n", nPlayer, nCylinder, nBullets);

			break;
		}
	}
	srand((unsigned)time(NULL));	//�ð����̿��� �õ�� ������ ���������� ����
	
	cout << "���� �غ�Ǿ����ϴ�. ����(Enter)Ű�� ������ �����մϴ�." << endl;
	getchar();

	printf("�Ǹ����� ���Ƚ��ϴ�. �����մϴ�.\n");

	static int DeathCount = 0;	//���� �μ�
	static int nTurn = 0;	//���° �߻�
	while (true) {
		int pos = rand() % nCylinder;
		printf("[%dȸ]\t�Ǹ����� ���Ƚ��ϴ�.\n",nTurn + 1);
		printf("\t����(Enter)Ű�� ������ �ݹߵ˴ϴ�.\n");
		getchar();
		if (pos < nBullets) {
			printf("\t(��!) �����ڰ� ����߽��ϴ�.\n\n");
			DeathCount++;
			if (DeathCount >= nBullets) {	//����ڰ� �Ѿ� �������� ũ�ų� ���� ���
				break;
			}
		}
		else {
			printf("\t(ƽ)��ҽ��ϴ�.\n\n");
		}
		nTurn++;
	}

	printf("\n -----> %d���� �����ڰ� ����Ͽ����ϴ�.\n", DeathCount);
	cout << "�������� ���ư��ðڽ��ϱ�?" << endl <<
		"[1] ��\n[2] �ƴϿ�\n";
	static int choice = 0;
	cin >> choice;

	switch (choice) {
	case 1: system("cls"); break;	//�ܼ��� �����ϰ� �� �Լ����� ��������
	case 2: exit(0);	//���α׷��� ����
	}


	return 0;

}