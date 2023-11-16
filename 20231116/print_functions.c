#include "common.h"
#include "output.h"
#include "student_management.h"


void PrintMenu(void)
{
	system("cls");
	printf_g("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf_g(" 1. 정보 입력\n");
	printf_g(" 2. 정보 출력\n");
	printf_g(" 3. 정보 저장\n");
	printf_g(" 4. 정보 갱신\n");
	printf_g(" 5. 정보 삭제\n");
	printf_g(" 0. 프로그램 종료\n");
	printf_g("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}

void PrintLoading(const int loadingTime)
{
	int i;

	printf("로딩중");
	for (i = 0; i < loadingTime; i++) {
		Sleep(1000);
		printf(".");
	}
	system("cls");
}

void PrintLetterGrade(const int score)
{
	if (score >= 95 && score <= 100) {
		printf("  A+\n");
	}
	else if (score >= 90) {
		printf("  A\n");
	}
	else if (score >= 85) {
		printf("  B+\n");
	}
	else if (score >= 80) {
		printf("  B\n");
	}
	else if (score >= 75) {
		printf("  C+\n");
	}
	else if (score >= 70) {
		printf("  C\n");
	}
	else if (score >= 65) {
		printf("  D+\n");
	}
	else if (score >= 60) {
		printf("  D\n");
	}
	else if (score < 60) {
		printf("  F\n");
	}
}

void PrintAverageNumericalGrade(const int score1, const int score2, const int score3)
{
	int score[3] = { score1 ,score2 ,score3 };
	float grade[3] = { 0 };
	float sum = 0.0;
	for (int i = 0;i < 3;i++) {
		if (score[i] >= 95 && score[i] <= 100) {
			grade[i] = 4.5;
		}
		else if (score[i] >= 90) {
			grade[i] = 4.0;
		}
		else if (score[i] >= 85) {
			grade[i] = 3.5;
		}
		else if (score[i] >= 80) {
			grade[i] = 3.0;
		}
		else if (score[i] >= 75) {
			grade[i] = 2.5;
		}
		else if (score[i] >= 70) {
			grade[i] = 2.0;
		}
		else if (score[i] >= 65) {
			grade[i] = 1.5;
		}
		else if (score[i] >= 60) {
			grade[i] = 1.0;
		}
		else if (score[i] < 60) {
			grade[i] = 0.0;
		}
		sum+=grade[i];
	}
	printf(" %.2f\n", sum / 3);
}

void SetConsoleTextColor(const int textColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
}

void printf_g(const char* text)
{
	SetConsoleTextColor(10);
	printf("%s", text);
	SetConsoleTextColor(7);
}

void printf_r(const char* text)
{
	SetConsoleTextColor(12);
	printf("%s", text);
	SetConsoleTextColor(7);
}

void ClearLineFromReadBuffer()
{
	while (getchar() != '\n');
}