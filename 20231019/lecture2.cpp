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
	printf("학생수 입력 : ");
	scanf_s("%d", &num);

	students = (struct Student *)malloc(num * sizeof(struct Student));
	for (int i = 0; i < num; i++) {
		printf("학생 # %d-%d 학번 입력 : ", num, i + 1);
		scanf_s("%d", &(students[i].sno));
		printf("학생 # %d-%d 이름 입력 : ", num, i + 1);
		scanf_s("%s", students[i].name,sizeof(students[i].name)/sizeof(char));
		printf("학생 # %d-%d 성적 입력 : ", num, i + 1);
		scanf_s("%d", &(students[i].score));
		sum += students[i].score;
	}
	printf("총점 : %d\n", sum);
	for (int i = 0; i < num; i++) {
		printf("학생 # %d-%d 성적 출력 : %d \n", num, i + 1, students[i].score);
	}
	printf("평균 점수 : %.2f\n", (float)sum / num);

	free(students);
	students = NULL;
	return 0;
}