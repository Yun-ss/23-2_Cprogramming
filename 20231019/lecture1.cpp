#include <stdio.h>
#include <stdlib.h>

int main() {
	int* score;
	int num;
	int sum = 0;
	printf("�л��� �Է� : ");
	scanf_s("%d", &num);

	score = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++) {
		printf("�л� # %d-%d ���� �Է� : ", num, i + 1);
		scanf_s("%d", (score + i));
		sum += *(score + i);
	}
	printf("���� : %d\n", sum);
	for (int i = 0; i < num; i++) {
		printf("�л� # %d-%d ���� ��� : %d \n", num, i + 1, *(score + i));
	}
	printf("��� ���� : %.2f\n", (float)sum / num);

	free(score);
	score = NULL;
	return 0;
}