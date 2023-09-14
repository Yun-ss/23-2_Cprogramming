#include <stdio.h>

int main(void) {

	int i, j;
	i = 1;
	while (i <= 5) {
		j = 1;
		while (j <= 5) {
			if (i == j) {
				if (j % 2 == 1) {
					printf("| O |");
				}
				else {
					printf("| X |");
				}
			}
			else {
				printf("   ");
			}
			j++;
		}
		if(i<5)	printf("\n-----------------\n");
		i++;
	}


	return 0;
}