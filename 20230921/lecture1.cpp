#include <stdio.h>
int isPrime(int num);
int main(void) {
	int num;
	printf("���� �Է�:");
	scanf_s("%d", &num);
	if (isPrime(num)) {
		printf("�ش� ���� �Ҽ� �Դϴ�.");
	}
	else {
		printf("�ش� ���� �Ҽ��� �ƴմϴ�.");
	}
	return 0;
}
int isPrime(int num) {
	int tmp;
	for (int i = 2; i < num; i++) {
		tmp = num % i;
		if(tmp==0||num==1){
			return 0;
		}
	}
	return 1;
}