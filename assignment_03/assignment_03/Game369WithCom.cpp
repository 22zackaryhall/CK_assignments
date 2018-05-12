#include "Games.h"

bool is369(int aa);		// 3,6,9�϶�
int digit_num(int aa);	// �ڸ���
int count369(int aa);	// 3,6,9�� ��ΰ�
int asts(int aa);	// * �� ����
static int i = 1, in = 0, j = 0, iAstIn = 0, ast = 0, AstC = 1, tns = 0;
char astIn;	//�÷��̾��� ���϶� 3,6,9 ��� *�� �Է�

int Game369WC() {
	while (true) {
		system("cls");

		cout << "[��ǻ�Ϳ� �ϴ� 369����]" << endl <<
			"�غ� �ǽø� ����(Enter)Ű�� ��������!" << endl <<
			"1���� �����մϴ�! 3,6,9�� ���ԵǸ� ������ŭ * �� �Է��ϼ���!" << endl <<
			"Ʋ���� ������ �����ϴ�!" << endl;
		getchar();
		static int turns = 0;	//������ �� ī��Ʈ
		int Missed = 0;	//Ʋ�ȴ��� �Ǵ��ϱ� ���� ����

		while (true) {

			tns = count369(i);
			turns++;

			if (tns == 0) {	// 3,6,9�� ���� ���� ��
				if (turns % 2 == 0) {	// ���� ¦���� ��� COM�� ����
					printf("[%3dȸ]COM\t: %d\n", turns, i);
				}
				else {	//���� Ȧ���� ��� �÷��̾ ����
					printf("[%3dȸ]YOU\t: ", turns);
					scanf("%d", &in);
					if (in != i) {	//���� Ʋ���� ��� ���� ��
						Missed++;
						break;
					}
					else {
					}
				}
			}
			else if (tns >= 1) {	// 3,6,9�� �� ��
				if (turns % 2 == 0) {
					printf("[%3dȸ]COM\t: ", turns);
					for (j = 0; j < tns; j++) {
						cout << "*";
						AstC++;
					}
					cout << "\n";
				}
				else {
					printf("[%3dȸ]YOU\t: ", turns);
					cin >> astIn;
					if (iAstIn == '*') {
						iAstIn = ((astIn - '0') / 42);
					//*�� ASCII���� 42�� ���
					}
					else {
						iAstIn = ((astIn - '0')*2 / 42);
					}

					ast = ('*' - '0');

					if (iAstIn != asts(tns)) {
						Missed++;
						break;
					}
					else {
					}
					iAstIn = 0;

				}

			}
			i++;
		}
		int choice = 0;
		printf("\nƲ�Ƚ��ϴ�.\n");
		printf("�� %dȸ ����Ǿ����ϴ�.\n\n", turns);
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
		turns = 0, i = 1, in = 0, j = 0, iAstIn = 0, ast = 0, AstC = 1;
	}
	return 0;
}

bool is369(int aa) {

	bool isr369 = false;

	if ((aa != 0) && (aa % 3 == 0)) {
		isr369 = true;
	}


	return isr369;
}

int digit_num(int aa) {

	int num = 0;

	while (aa != 0) {
		num++;
		aa /= 10;
	}

	return num;
}

int count369(int aa) {

	int tmp = aa;
	int num = 0;
	int digit = digit_num(aa);

	for (int i = 0; i < digit; i++) {
		if (is369(tmp % 10)) {
			num++;
		}
		tmp /= 10;
	}


	return num;

}

int asts(int aa) {
	
	int Asts = 0;

		Asts += (('*' - '0') * aa / 42);

	return Asts;
}