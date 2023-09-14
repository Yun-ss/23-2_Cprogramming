#include <stdio.h>

int main(void) {

	int yearDecision,inputYear;
	
	printf("윤년이면 1, 평년이면 0 출력\n");
	printf("연도 입력 : ");
	scanf_s("%d", &inputYear);
	if ((inputYear % 400) == 0) {
		yearDecision = 1;
	}
	else if ((inputYear % 4)!=0) {
		yearDecision = 0;
	}
	else if ((inputYear % 100) == 0) {
		yearDecision = 0;
	}
	else {
		yearDecision = 1;
	}


	printf("입력한 %d년은 %d에 해당합니다.\n", inputYear,yearDecision);

	return 0;
}