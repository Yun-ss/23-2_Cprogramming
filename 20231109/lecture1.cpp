#include <stdio.h>

float Div(int n1, int n2) {
	float result=0;
	if (n2 != 0) {
		result = ((float)n1 / n2);
	}
	else {
		printf("0으로는 나눌수 없습니다.");
		return 0;
	}
	return result;
}


int main() {
	int n1, n2;
	float result;
	printf("정수 2개를 입력하세요 :");
	scanf_s("%d %d", &n1, &n2);
	result = Div(n1, n2);
	printf("%f",result);
	return 0;
}