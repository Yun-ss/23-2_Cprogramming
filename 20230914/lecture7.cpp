#include <stdio.h>

int main(void) {

	int score;

	printf("���� �Է� : ");
	scanf_s("%d", &score);
	if (score > 100||score<0) {
		printf("�߸� �Է��Ͽ����ϴ�.\n");
	}
	else if (score >= 90) {
		printf("A����(%d��) �Դϴ�.\n", score);
	}
	else if (score >= 80) {
		printf("B����(%d��) �Դϴ�.\n", score);
	}
	else if (score >= 70) {
		printf("C����(%d��) �Դϴ�.\n", score);
	}
	else if (score >= 60) {
		printf("D����(%d��) �Դϴ�.\n", score);
	}
	else {
		printf("F����(%d��) �Դϴ�.\n", score);
	}

	return 0;
}