#include <stdio.h>

void swap(int* num1, int* num2) {
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
int main() {
	int num1 = 54;
	int num2 = 2;
	printf("num1: %d, num2: %d\n", num1, num2);
	swap(&num1, &num2);
	printf("num1: %d, num2: %d\n", num1, num2);
	return 0;
}