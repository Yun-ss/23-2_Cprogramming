#include <stdio.h>

int main(void) {

	int i, j;
	int mul = 0;
	i = 2;
	while( i < 10) {
		if (i == 5) i++;
		j = 1;
		while ( j < 10) {
			mul = i * j;
			printf("%d * %d = %d\n", i, j, mul);
			j++;
		}	
		printf("\n");
		i++;
	}


	return 0;
}