#include <stdio.h>
#include <stdlib.h>

struct Student {
	int sno;
	char name[10];
	int score;
};
int main() {
	struct Student* students;
	int num;
	int sum = 0;
	printf("�л��� �Է� : ");
	scanf_s("%d", &num);

	students = (struct Student *)malloc(num * sizeof(struct Student));
	for (int i = 0; i < num; i++) {
		printf("�л� # %d-%d �й� �Է� : ", num, i + 1);
		scanf_s("%d", &(students[i].sno));
		printf("�л� # %d-%d �̸� �Է� : ", num, i + 1);
		scanf_s("%s", students[i].name,sizeof(students[i].name)/sizeof(char));
		printf("�л� # %d-%d ���� �Է� : ", num, i + 1);
		scanf_s("%d", &(students[i].score));
		sum += students[i].score;
	}
	printf("���� : %d\n", sum);
	for (int i = 0; i < num; i++) {
		printf("�л� # %d-%d ���� ��� : %d \n", num, i + 1, students[i].score);
	}
	printf("��� ���� : %.2f\n", (float)sum / num);

	free(students);
	students = NULL;
	return 0;
}