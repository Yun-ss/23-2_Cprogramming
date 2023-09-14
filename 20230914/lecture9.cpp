#include <stdio.h>

int main(void) {

	int i;
	int sum = 0;
	int val = 1;
	for (i = 0; i < 10; i++) {
		printf("i: %d		val: %d		sum: %d\n", i, val, sum);
		sum += val;
		val++;
	}
	/*
	for (i = 0; i < 10; i++) {
		printf("i: %d		sum: %d\n", i, sum);
		sum += (i+1);
	}
	*/
	printf("sum: %d", sum);

	return 0;
}