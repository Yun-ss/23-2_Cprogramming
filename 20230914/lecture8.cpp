#include <stdio.h>

int main(void) {

	int score, scoreDiv;

	printf("점수 입력 : ");
	scanf_s("%d", &score);
	scoreDiv = score / 10;
	switch (scoreDiv) {
		case 10:
		case 9:
			printf("A학점(%d점) 입니다.\n", score);
			break;
		case 8:
			printf("B학점(%d점) 입니다.\n", score);
			break;
		case 7:
			printf("C학점(%d점) 입니다.\n", score);
			break;
		case 6:
			printf("D학점(%d점) 입니다.\n", score);
			break;
		default:
			if (scoreDiv > 10 || scoreDiv < 0) {
				printf("잘못 입력하였습니다.\n");
			}
			else {
				printf("F학점(%d점) 입니다.\n", score);
			}
			break;
	}

	return 0;
}