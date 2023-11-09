#include <stdio.h>

float Div(int n1, int n2) {
	float result;
	if (n2 != 0) {
		result = ((float)n1 / n2);
	}
	return result;
}

int main() {
	int numarr[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0;j < 5; j++) {
			numarr[i][j] = (i * 5) + j+1;
			printf("%d	", numarr[i][j]);
		}
		printf("\n");
	}
	printf("Change row & column\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d	", numarr[j][i]);
		}
		printf("\n");
	}
	return 0;
}