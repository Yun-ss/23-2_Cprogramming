#include <stdio.h>

int main(void) {

	int score;

	printf("점수 입력 : ");
	scanf_s("%d", &score);
	if (score > 100||score<0) {
		printf("잘못 입력하였습니다.\n");
	}
	else if (score >= 90) {
		printf("A학점(%d점) 입니다.\n", score);
	}
	else if (score >= 80) {
		printf("B학점(%d점) 입니다.\n", score);
	}
	else if (score >= 70) {
		printf("C학점(%d점) 입니다.\n", score);
	}
	else if (score >= 60) {
		printf("D학점(%d점) 입니다.\n", score);
	}
	else {
		printf("F학점(%d점) 입니다.\n", score);
	}

	return 0;
}