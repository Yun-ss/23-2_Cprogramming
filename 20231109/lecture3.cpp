#include <stdio.h>

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int n1, n2;
	printf("���� 2���� �Է��ϼ��� :");
	scanf_s("%d %d", &n1, &n2);
	Swap(&n1, &n2);
	printf("%d %d", n1, n2);
	return 0;
}