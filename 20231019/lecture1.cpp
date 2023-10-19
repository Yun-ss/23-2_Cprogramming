#include <stdio.h>
#include <stdlib.h>

int main() {
	int* score;
	int num;
	int sum = 0;
	printf("학생수 입력 : ");
	scanf_s("%d", &num);

	score = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++) {
		printf("학생 # %d-%d 성적 입력 : ", num, i + 1);
		scanf_s("%d", (score + i));
		sum += *(score + i);
	}
	printf("총점 : %d\n", sum);
	for (int i = 0; i < num; i++) {
		printf("학생 # %d-%d 성적 출력 : %d \n", num, i + 1, *(score + i));
	}
	printf("평균 점수 : %.2f\n", (float)sum / num);

	free(score);
	score = NULL;
	return 0;
}