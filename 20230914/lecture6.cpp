#include <stdio.h>

int main(void) {

	int input_num;

	printf("정수 입력 : ");
	scanf_s("%d", &input_num);
	if (input_num > 0) {
		printf("%d은(는) 양의 정수입니다.\n", input_num);
	}
	else if (input_num <0) {
		printf("%d은(는) 음의 정수입니다.\n", input_num);
	}
	else {
		printf("0입니다.\n");
	}

	return 0;
}