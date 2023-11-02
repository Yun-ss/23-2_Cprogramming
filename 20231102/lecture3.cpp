#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int countStrike(int answer[], int input[],int length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (answer[i] == input[i]) {
			count++;
		}
	}
	return count;
}

int countBall(int answer[], int input[], int length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (i == j) {
				continue;
			}
			else if (answer[i] == input[j]) {
				count++;
			}
		}
	}
	return count;
}

int main() {
	srand(time(NULL));
	int answer[3] = {0,0,0};
	int input[3];
	int count=0;
	int tmp;
	int i = 0;
	while (i < 3) {
		int isOnly=1;
		tmp = rand() % 9 + 1;
		for (int j = 0; j <= i; j++) {
			if (answer[j] == tmp) {
				isOnly = 0;
			}
		}
		if (isOnly) {
			answer[i] = tmp;
			i++;
		}
		else {
			continue;
		}
	}

	printf("���� �߱� ���ӿ� ���� ���� ȯ���մϴ�!\n\n");
	while (count <  3) {
		printf("�� �ڸ� ���ڸ� �Է����ּ��� :");
		scanf_s("%d %d %d", &input[0], &input[1], &input[2]);		
		printf("%d ��Ʈ����ũ, %d ��\n", countStrike(answer, input, 3), countBall(answer, input, 3));
		count = countStrike(answer, input, 3);
	}

	printf("\n�����մϴ�! ������ ���߼̽��ϴ�!\n");
	return 0;
}