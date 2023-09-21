#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void) {
	double x,y;
	int inCicle = 0;
	int count=0;
	float phi;
	int percent=0;
	srand(time(NULL));
	for (int i = 1; i <= 1000000000; i++) {
		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand() / (double)RAND_MAX;
		count++;
		if ((pow(x, 2) + pow(y, 2)) <= 1) {
			inCicle++;
		}
		phi = 4*(float)inCicle / (float)count;	
		if (percent < (int)(i / 10000000)) {
			percent = (int)(i / 10000000);
			printf("%d%%진행중..	원주율 : %f", percent,phi);
			for (int j = 0; j < 20; j++) {
				if (j < (percent / 5)) {
					printf("■");
				}
				else {
					printf("□");
				}
			}
			printf("\n");
		}
	}
}
