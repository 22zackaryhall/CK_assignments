#include <iostream>
#include <conio.h>

#define Enter 13	//EnterŰ�� ASCII���� 13�� ����� ����

using namespace std;

int main() {
	
	int digitcount, ecount, input, ainput, min, max, tcount, i, score;
	char output = 0;
	digitcount = 0; ecount = 0; input = 0; ainput = 0;
	min = 0; max = 0; tcount = 0; i = 0; score = 0;

	cout << "<Up and Down ���� ������ �����Դϴ�.>" << endl <<
		"����� ������ �Դϴ�." << endl <<
		"������ �� ������ �Է��ϰ� ����(Enter)�� ��������." << endl <<
		"������ �� ������ �Է��Ͽ� �ּ���(0~9999 ������ ��) : ";

	while (true) {		//���� �� ������ �����ڰ� ���� ���� �ݺ���
		char input1 = getch();		//ù ��° ��
		if (input1 >= '0' && input1 <= '9') {
			cout << "*";
			digitcount++;		//�ڸ����� Ȯ���ϱ� ���� ��

			if (digitcount == 1) {
				char input2 = getch();		//�� ��° ��
				if (input2 >= '0' && input2 <= '9') {
					cout << "*";
					digitcount++;

					if (digitcount == 2) {
						char input3 = getch();		//�� ��° ��
						if (input3 >= '0' && input3 <= '9') {
							cout << "*";
							digitcount++;

							if (digitcount == 3) {
								char input4 = getch();		//�� ��° ��
								if (input4 >= '0' && input4 <= '9') {
									cout << "*";
									digitcount++;

									if (digitcount >= 4) {		//�� ��° ���� �Է��ϸ� ���̻��� �Է��� ���� ����
										input = (input1 - '0') * 1000 + (input2 - '0') * 100 + (input3 - '0') * 10 + (input4 -'0');
										//������ 4�ڸ��� �� ��� ������ ASCII �� ���� ���ڷ� ��ȯ
										break;
									}
								}
								else if (input4 == Enter) {
									input = (input1 - '0') * 100 + (input2 - '0') * 10 + (input3 - '0');
									//������ 3�ڸ��� �� ��� ������ ASCII �� ���� ���ڷ� ��ȯ
									break;
								}
								else { ecount++; break; }
								//ecount�� �Է¿� ������ �־����� �Ǻ��ϱ� ���� ����
							}
						}
						else if (input3 == Enter) {
							input = (input1 - '0') * 10 + (input2 - '0');
							//������ 2�ڸ��� �� ��� ������ ASCII �� ���� ���ڷ� ��ȯ
							break;
						}
						else { ecount++; break; }
					}
				}
				else if (input2 == Enter) {
					input = (input1 - '0');
					//������ 1�ڸ��� �� ��� ������ ASCII �� ���� ���ڷ� ��ȯ
					break;
				}
				else { ecount++; break; }
			}
		}
		else if (input1 == Enter) {
			ecount++; break;
		}

	}

	if (ecount > 0) {	//�ùٸ��� ���� �Է����� ecount�� 1�̻��� ��� ��������
		cout << endl << "�ùٸ��� ���� �Է��Դϴ�." << endl;
		return 0;
	}
	else {	//�Է��� ������ �ùٸ� ��� ���̸Ӱ� ���� ���ϵ��� ȭ�� ����
		system("cls");
		cout << "<Up and Down ���� ������ �����Դϴ�.>" << endl << endl <<
		"������ " << digitcount << " �ڸ� �����̸�, " << endl;
	}

	switch (digitcount) {	//�ڸ����� ���� �Է� �õ�Ƚ���� �ִ��� �ٸ��� �Ҵ�
	case 1: tcount = 5; max = 9; break;
	case 2: tcount = 10; max = 99; break;
	case 3: tcount = 20; max = 999; break;
	case 4: tcount = 25; max = 9999; break;
	}

	cout << " '" << min << "' ���� '" << max << "' ������ ���� �Դϴ�!" << endl <<
		"������ �Է��� ��ȸ�� ������ �ڸ����� ���߾� �� '" << tcount << "' ȸ �־����ϴ�!" << endl <<
		"������ ������, ������ ���߾� ������!" << endl << endl;

	for (i = 0; i <= tcount - 1; i++) {	//���̸Ӱ� �ִ� �õ� Ƚ�� �ȿ��� �Է��ϵ��� ���

WrongValue:		//���� �־��� ������ ��� ���� �Է��Ͽ��� ��� Ƚ���� ������ ä ���Է� ���
		printf("[%d/%d] %d ~ %d ������ �� : ", i + 1, tcount, min, max);

		cin >> ainput;		//���̸Ӱ� �Է��� ���� ainput�� ����

		if (ainput == input) {	//������ ���߾��� ��� for �������� ���.
			printf("�����Դϴ�!\n�����ڰ� ���� ���� '%d' �����ϴ�!\n", input);
			break;
		}
		else if (ainput > input) {	//�Է°��� ������ �ƴҰ�� ���亸�� ������ ������ �˻�

			if (ainput < min || ainput > max) {
				printf("%d ~ %d ������ ���� �ƴϳ׿�!\n\n", min, max);
				goto WrongValue;	//�־��� ������ ����� ��� Ƚ�� ī��Ʈ ���� �Է±�ȸ����
			}
			else {
				if (i < tcount-1) {	//���亸�� ū ���� �Է��Ͽ��� ���
					cout << "���亸�� ū �� �Դϴ�. �� ���� ���� ������ô�" << endl << endl;
				}
				else {	//�־��� ��ȸ�� ��� �����Ͽ��� ���
					cout << "�־��� ��ȸ�� ���̻� ���׿�..." << endl << endl;
				}
				max = ainput;	//�Է¹��� ���� ���亸�� Ŭ ��� max���� ainput���� ����
			}
		}
		else {

			if (ainput < min || ainput > max) {
				printf("%d ~ %d ������ ���� �ƴϳ׿�!\n\n", min, max);
				goto WrongValue;	//�־��� ������ ����� ��� Ƚ�� ī��Ʈ ���� �Է±�ȸ����
			}
			else {
				if (i < tcount-1) {	//���亸�� ���� ���� �Է��Ͽ��� ���
					cout << "���亸�� ���� �� �Դϴ�. �� ū ���� ������ô�" << endl << endl;
				}
				else {	//�־��� ��ȸ�� ��� �����Ͽ��� ���
					cout << "�־��� ��ȸ�� ���̻� ���׿�..." << endl << endl;
				}
				min = ainput;	//�Է¹��� ���� ���亸�� ���� ��� min���� ainput���� ����
			}
		}
	}

	score = 100 - (i * (100 / tcount));	//����� Ƚ���� �ڸ������̿��Ͽ� 0~100������ ������ ��

	cout.precision(0);
		cout << endl << "[���] �� '" << tcount << "' ��ŭ�� �־��� Ƚ������ '" << i <<
			"' ȸ Ʋ�����Ƿ�, �������� ������ '" << score << "' �� �Դϴ�." << endl;

	return 0;
}