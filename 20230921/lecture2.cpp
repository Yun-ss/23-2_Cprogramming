#include <stdio.h>
void calculator(int selector, int num1,int num2);
void add(int num1, int num2);
void sub(int num1, int num2);
void mul(int num1, int num2);
void div(int num1, int num2);

int main(void) {
	int sel, num1, num2;
	printf("숫자 입력:");
	scanf_s("%d", &num1);
	printf("1.더하기 2.빼기 3.곱하기 4.나누기:");
	scanf_s("%d", &sel);
	printf("숫자 입력:");
	scanf_s("%d", &num2);
	calculator(sel, num1, num2);
	return 0;
}
void calculator(int selector, int num1, int num2) {
	switch (selector) {
	case 1:
		add(num1, num2);
		return;
	case 2:
		sub(num1, num2);
		return;
	case 3:
		mul(num1, num2);
		return;
	case 4:
		div(num1, num2);
		return;
	default:
		printf("error!");
		return;
	}
}
void add(int num1, int num2) {
	printf("%d",(num1 + num2));
	return;
}
void sub(int num1, int num2) {
	printf("%d", (num1 - num2));
	return;
}
void mul(int num1, int num2) {
	printf("%d", (num1 * num2));
	return;
}
void div(int num1, int num2) {
	if (num2 != 0) {
		printf("%f", ((float)num1 / num2));
	}
	return;
}