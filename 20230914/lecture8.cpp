#include <stdio.h>

int main(void) {

	int score, scoreDiv;

	printf("���� �Է� : ");
	scanf_s("%d", &score);
	scoreDiv = score / 10;
	switch (scoreDiv) {
		case 10:
		case 9:
			printf("A����(%d��) �Դϴ�.\n", score);
			break;
		case 8:
			printf("B����(%d��) �Դϴ�.\n", score);
			break;
		case 7:
			printf("C����(%d��) �Դϴ�.\n", score);
			break;
		case 6:
			printf("D����(%d��) �Դϴ�.\n", score);
			break;
		default:
			if (scoreDiv > 10 || scoreDiv < 0) {
				printf("�߸� �Է��Ͽ����ϴ�.\n");
			}
			else {
				printf("F����(%d��) �Դϴ�.\n", score);
			}
			break;
	}

	return 0;
}