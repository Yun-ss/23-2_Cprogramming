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
		printf_r(" �޸� �Ҵ翡 �����Ͽ����ϴ�\n");
		PrintLoading(1);
	}
	else {
		printf_g("����������  ��  ��  ��  ��  ��������������\n");
		printf_g("      ��    �� :");
		scanf_s("%s", studentId,10);
		if (IsRegistID(studentId)) {
			printf_r(" �̹� ��ϵ� �й��Դϴ�. ó������ �ٽ� �õ��� �ּ���.\n");
			PrintLoading(3);		
		}
		else {
			strcpy(students[numStudents]->ID, studentId);
			printf_g("      ��    �� :");
			scanf_s("%s", students[numStudents]->name,10);
			printf_g("      ��ȭ��ȣ :");
			scanf_s("%s", students[numStudents]->phoneNum,15);
			printf_g("����������  ��  ��  ��  ��  ��������������\n");
			printf_g("      C  �� �� :");
			scanf_s("%d", &students[numStudents]->cScore);
			printf_g("      �������� :");
			scanf_s("%d", &students[numStudents]->securityScore);
			printf_g("      ��Ʈ��ũ :");
			scanf_s("%d", &students[numStudents]->networkScore);
			printf_g("������������������������������������������������������������\n");
			numStudents++;
			printf_g(" �Է¿� �����߽��ϴ�. ���θ޴��� ���ư��ϴ�.\n");	
			PrintLoading(3);
		}
	}
	
}

void PrintAllStudentInfo(void)
{
	system("cls");
	int i=0;
	if (numStudents == 0) {
		printf_r(" ����� �л������� �����ϴ�.\n");
		PrintLoading(2);
	}
	else {
		for (i = 0;i < numStudents;i++) {
			printf_g("������������������������������������������������������������\n");
			printf_g("      ��    �� :");
			printf("%s\n", students[i]->ID);
			printf_g("      ��    �� :");
			printf("%s\n", students[i]->name);
			printf_g("      ��ȭ��ȣ :");
			printf("%s\n", students[i]->phoneNum);
			printf_g("      C  �� �� :");
			printf("%d", students[i]->cScore);
			PrintLetterGrade(students[i]->cScore);
			printf_g("      �������� :");
			printf("%d", students[i]->securityScore);
			PrintLetterGrade(students[i]->securityScore);
			printf_g("      ��Ʈ��ũ :");
			printf("%d", students[i]->networkScore);
			PrintLetterGrade(students[i]->networkScore);
			printf_g("\n      ������� :");
			PrintAverageNumericalGrade(students[i]->cScore, students[i]->securityScore, students[i]->networkScore);
			printf_g("������������������������������������������������������������\n");
		}
		printf_g(" ����Ϸ��� �ƹ�Ű�� �����ʽÿ�..\n\n"); _getch();
	}
	
}

void StoreAllStudentInfo(void)
{
	printf_g(" �л������� �����ϰ� �ֽ��ϴ�..\n\n");
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
			printf_g("������������������������������������������������������������������������\n");
			printf_g("   ���� ������� �������� �ʾ�   \n");
			printf_g("      �ʱ���¿��� �����մϴ�      \n");
			printf_g("������������������������������������������������������������������������\n");
			printf(" ����Ϸ��� �ƹ� Ű�� �����ʽÿ�..."); _getch();
		}
	}
}

void ChangeStudentInfo(void)
{
	char studentID[10];
	int select;
	system("cls");
	printf_g("������ �л��� �й��� �Է��ϼ���.\n");
	printf_g("������������������������������������������������������������\n");
	printf_g("    ��    �� : ");
	scanf_s("%s", studentID, 10); ClearLineFromReadBuffer();
	printf_g("������������������������������������������������������������\n\n");
	if (IsRegistID(studentID)) {
		printf_g("������������������������������������������������������������\n");
		printf_g(" 1. �̸� ����\n");
		printf_g(" 2. ��ȭ��ȣ ����\n");
		printf_g(" 3. ���� ����\n");
		printf_g("������������������������������������������������������������\n");
		printf(" ���� >>> "); scanf_s("%d", &select); ClearLineFromReadBuffer();
		switch (select) {
			case 1:
				printf(" ������ �̸� �Է� : ");
				scanf_s("%s", students[GetStudentIdxByID(studentID)]->name, 10);
				break;
			case 2:
				printf(" ������ ��ȭ��ȣ �Է� : ");
				scanf_s("%s", students[GetStudentIdxByID(studentID)]->phoneNum, 15);
				break;
			case 3:
				printf(" ������ ���� �Է� ");
				printf(" C  �� �� :");
				scanf_s("%d", &students[GetStudentIdxByID(studentID)]->cScore);
				printf(" �������� :");
				scanf_s("%d", &students[GetStudentIdxByID(studentID)]->securityScore);
				printf(" ��Ʈ��ũ :");
				scanf_s("%d", &students[GetStudentIdxByID(studentID)]->networkScore);
				break;
		}
		printf_g(" ���� ����! ���θ޴��� ���ư��ϴ�.\n");
		PrintLoading(3);
	}
	else {
		printf_r(" �������� �ʴ� �й��Դϴ�.\n");
		PrintLoading(2);	
	}
}

void DeleteStudentInfo(void)
{
	char studentID[10];

	system("cls");
	printf_g("������ �л��� �й��� �Է��ϼ���.\n");
	printf_g("������������������������������������������������������������\n");
	printf_g("    ��    �� : ");
	scanf_s("%s", studentID, 10); ClearLineFromReadBuffer();
	printf_g("������������������������������������������������������������\n\n");
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
		printf_g("������ �����߽��ϴ�.\n");
		PrintLoading(3);
	}
	else {
		printf_r(" �������� �ʴ� �й��Դϴ�. ���θ޴��� ���ư��ϴ�.\n");
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

