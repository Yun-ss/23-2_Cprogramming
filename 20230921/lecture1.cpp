#include <stdio.h>
int isPrime(int num);
int main(void) {
	int num;
	printf("정수 입력:");
	scanf_s("%d", &num);
	if (isPrime(num)) {
		printf("해당 수는 소수 입니다.");
	}
	else {
		printf("해당 수는 소수가 아닙니다.");
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