#include <stdio.h>

int main(void) {

	int yearDecision,inputYear;
	
	printf("�����̸� 1, ����̸� 0 ���\n");
	printf("���� �Է� : ");
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


	printf("�Է��� %d���� %d�� �ش��մϴ�.\n", inputYear,yearDecision);

	return 0;
}