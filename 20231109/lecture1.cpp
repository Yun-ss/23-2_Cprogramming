#include <stdio.h>

float Div(int n1, int n2) {
	float result=0;
	if (n2 != 0) {
		result = ((float)n1 / n2);
	}
	else {
		printf("0���δ� ������ �����ϴ�.");
		return 0;
	}
	return result;
}


int main() {
	int n1, n2;
	float result;
	printf("���� 2���� �Է��ϼ��� :");
	scanf_s("%d %d", &n1, &n2);
	result = Div(n1, n2);
	printf("%f",result);
	return 0;
}