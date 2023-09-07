#include <stdio.h>

int main() {
	int n;
	int i, j, k;
	scanf_s("%d", &n);
	printf("%d층 피라미드\n",n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n-i; j++) {
			printf(" ");
		}
		for (k = 1; k <= (2 * i - 1); k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
