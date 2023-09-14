#include <stdio.h>

int main(void) {

	int i,j;
	int mul = 0;
	for (i = 2; i < 10; i++) {
		if (i == 5) continue;
		for (j = 1; j < 10; j++) {
			mul = i * j;
			printf("%d * %d = %d\n",i,j, mul);
		}
		printf("\n");
	}
	

	return 0;
}