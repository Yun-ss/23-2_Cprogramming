#include <stdio.h>

int main() {
	int score[5] = { 87,92,89,98,78 };
	int cnt;
	int* p_score = score;
	printf("score[5] = { 87,92,89,98,78 }\n");
	for (cnt = 0; cnt < 5; cnt++) {
		printf("score[%d] =[%d]\n",cnt,score[cnt]);
	}
	for (cnt = 0; cnt < 5; cnt++) {
		printf("score[%d] =[%d]\n", cnt, *p_score);
		p_score++;
	}
	return 0;
}