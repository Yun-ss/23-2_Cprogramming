#include "common.h"
#include "output.h"
#include "student_management.h"

#define MAX_STUDENT 100

static StudentInfo* students[MAX_STUDENT];
static int numStudents = 0;

#define DATA_BACKUP_FILE "student_info.dat"

void InputStudentInfo(void)
{
	char studentId[10];
	system("cls");
	if ((students[numStudents] = (StudentInfo*)malloc(sizeof(StudentInfo))) == NULL) {
		printf_r(" 메모리 할당에 실패하였습니다\n");
		PrintLoading(1);
	}
	else {
		printf_g("━━━━━  정  보  입  력  ━━━━━━━\n");
		printf_g("      학    번 :");
		scanf_s("%s", studentId,10);
		if (IsRegistID(studentId)) {
			printf_r(" 이미 등록된 학번입니다. 처음부터 다시 시도해 주세요.\n");
			PrintLoading(3);		
		}
		else {
			strcpy(students[numStudents]->ID, studentId);
			printf_g("      이    름 :");
			scanf_s("%s", students[numStudents]->name,10);
			printf_g("      전화번호 :");
			scanf_s("%s", students[numStudents]->phoneNum,15);
			printf_g("━━━━━  성  적  입  력  ━━━━━━━\n");
			printf_g("      C  언 어 :");
			scanf_s("%d", &students[numStudents]->cScore);
			printf_g("      정보보안 :");
			scanf_s("%d", &students[numStudents]->securityScore);
			printf_g("      네트워크 :");
			scanf_s("%d", &students[numStudents]->networkScore);
			printf_g("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			numStudents++;
			printf_g(" 입력에 성공했습니다. 메인메뉴로 돌아갑니다.\n");	
			PrintLoading(3);
		}
	}
	
}

void PrintAllStudentInfo(void)
{
	system("cls");
	int i=0;
	if (numStudents == 0) {
		printf_r(" 출력할 학생정보가 없습니다.\n");
		PrintLoading(2);
	}
	else {
		for (i = 0;i < numStudents;i++) {
			printf_g("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			printf_g("      학    번 :");
			printf("%s\n", students[i]->ID);
			printf_g("      이    름 :");
			printf("%s\n", students[i]->name);
			printf_g("      전화번호 :");
			printf("%s\n", students[i]->phoneNum);
			printf_g("      C  언 어 :");
			printf("%d", students[i]->cScore);
			PrintLetterGrade(students[i]->cScore);
			printf_g("      정보보안 :");
			printf("%d", students[i]->securityScore);
			PrintLetterGrade(students[i]->securityScore);
			printf_g("      네트워크 :");
			printf("%d", students[i]->networkScore);
			PrintLetterGrade(students[i]->networkScore);
			printf_g("\n      평균평점 :");
			PrintAverageNumericalGrade(students[i]->cScore, students[i]->securityScore, students[i]->networkScore);
			printf_g("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		}
		printf_g(" 계속하려면 아무키나 누르십시오..\n\n"); _getch();
	}
	
}

void StoreAllStudentInfo(void)
{
	printf_g(" 학생정보를 저장하고 있습니다..\n\n");
	FILE* fp;
	fopen_s(&fp, DATA_BACKUP_FILE, "wt");
	if (NULL!=fp) {
		for (int i = 0; i < numStudents;i++) {
			fprintf(fp, "%s %s %s %d %d %d\n", students[i]->ID, students[i]->name, students[i]->phoneNum, 
				students[i]->cScore, students[i]->securityScore, students[i]->networkScore);
		}
		fclose(fp);
	}
	PrintLoading(3);
}

void LoadAllStudentInfo(void)
{

	system("cls");
	FILE* fp;
	fopen_s(&fp, DATA_BACKUP_FILE, "rt");
	StudentInfo* pstudent;
	if (NULL != fp) {
		while (numStudents< MAX_STUDENT) {
			pstudent = (StudentInfo*)malloc(sizeof(StudentInfo));
			if (fscanf_s(fp, "%s %s %s %d %d %d\n",
				pstudent->ID, 10, pstudent->name, 10, pstudent->phoneNum, 15,
				&(pstudent->cScore), &(pstudent->securityScore), &(pstudent->networkScore)) != EOF) {
				students[numStudents] = pstudent;
				numStudents++;
				pstudent = NULL;
			}
			else {
				free(pstudent);
				pstudent = NULL;
				break;
			}
		}
		fclose(fp);
		if (numStudents == 0) {
			puts("");
			printf_g("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			printf_g("   이전 사용기록이 남아있지 않아   \n");
			printf_g("      초기상태에서 시작합니다      \n");
			printf_g("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
			printf(" 계속하려면 아무 키나 누르십시오..."); _getch();
		}
	}
}

void ChangeStudentInfo(void)
{
	char studentID[10];
	int select;
	system("cls");
	printf_g("갱신할 학생의 학번을 입력하세요.\n");
	printf_g("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf_g("    학    번 : ");
	scanf_s("%s", studentID, 10); ClearLineFromReadBuffer();
	printf_g("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
	if (IsRegistID(studentID)) {
		printf_g("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf_g(" 1. 이름 변경\n");
		printf_g(" 2. 전화번호 변경\n");
		printf_g(" 3. 성적 변경\n");
		printf_g("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf(" 선택 >>> "); scanf_s("%d", &select); ClearLineFromReadBuffer();
		switch (select) {
			case 1:
				printf(" 변경할 이름 입력 : ");
				scanf_s("%s", students[GetStudentIdxByID(studentID)]->name, 10);
				break;
			case 2:
				printf(" 변경할 전화번호 입력 : ");
				scanf_s("%s", students[GetStudentIdxByID(studentID)]->phoneNum, 15);
				break;
			case 3:
				printf(" 변경할 성적 입력 ");
				printf(" C  언 어 :");
				scanf_s("%d", &students[GetStudentIdxByID(studentID)]->cScore);
				printf(" 정보보안 :");
				scanf_s("%d", &students[GetStudentIdxByID(studentID)]->securityScore);
				printf(" 네트워크 :");
				scanf_s("%d", &students[GetStudentIdxByID(studentID)]->networkScore);
				break;
		}
		printf_g(" 변경 성공! 메인메뉴로 돌아갑니다.\n");
		PrintLoading(3);
	}
	else {
		printf_r(" 존재하지 않는 학번입니다.\n");
		PrintLoading(2);	
	}
}

void DeleteStudentInfo(void)
{
	char studentID[10];

	system("cls");
	printf_g("삭제할 학생의 학번을 입력하세요.\n");
	printf_g("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf_g("    학    번 : ");
	scanf_s("%s", studentID, 10); ClearLineFromReadBuffer();
	printf_g("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
	if (IsRegistID(studentID)) {
		if (GetStudentIdxByID(studentID) == (numStudents - 1)) {
			free(students[GetStudentIdxByID(studentID)]);
			students[GetStudentIdxByID(studentID)] = NULL;
			numStudents--;
		}
		else {
			StudentInfo* pDelete = students[GetStudentIdxByID(studentID)];
			for (int i = GetStudentIdxByID(studentID);i < numStudents-1;i++) {
				students[i] = students[i+1];
			}
			free(pDelete);
			pDelete = NULL;
			numStudents--;
		}
		printf_g("삭제에 성공했습니다.\n");
		PrintLoading(3);
	}
	else {
		printf_r(" 존재하지 않는 학번입니다. 메인메뉴로 돌아갑니다.\n");
		PrintLoading(2);
	}
}

void FreeStructMemory(void)
{
	int i;

	for (i = 0; i < numStudents; i++)
		free(students[i]);

	return;
}

int GetStudentIdxByID(const char* ID)
{
	int i;

	for (i = 0; i < numStudents; i++)
	{
		if (!strcmp(students[i]->ID, ID))
			return i;
	}
	return -1;
}

int IsRegistID(const char* ID)
{
	if (GetStudentIdxByID(ID) != -1)
		return 1;

	return 0;
}

