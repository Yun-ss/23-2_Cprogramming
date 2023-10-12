#include <stdio.h>

int main() {
	int num = 100;
	int* ptr = &num;

	printf("%d\n", ptr);
	printf("%d\n", *ptr);

	int num1 = 100, num2 = 100;
	int* pnum;
	pnum = &num1;
	(*pnum) += 30;
	pnum = &num2;
	(*pnum) -= 30;

	printf("%d\n", num1);
	printf("%d\n", num2);
	return 0;
}