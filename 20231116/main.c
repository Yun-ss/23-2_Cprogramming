#include "common.h"
#include "output.h"
#include "student_management.h"

enum { EXIT = 0, INPUT_DATA, OUTPUT_DATA, STORE_DATA, CHANGE_DATA, DELETE_DATA };

int main(void)
{
	int select;

	LoadAllStudentInfo();
	while (1)
	{
		PrintMenu();
		printf(" ���� >>> "); scanf_s("%d", &select); ClearLineFromReadBuffer();

		switch (select)
		{
		case EXIT:
			FreeStructMemory();
			printf_g(" ���α׷��� �����մϴ�.\n");
			return 0;
		case INPUT_DATA:
			InputStudentInfo();
			break;
		case OUTPUT_DATA:
			PrintAllStudentInfo();
			break;
		case STORE_DATA:
			StoreAllStudentInfo();
			break;
		case CHANGE_DATA:
			ChangeStudentInfo();
			break;
		case DELETE_DATA:
			DeleteStudentInfo();
			break;
		default:
			printf_r(" �߸� �Է��Ͽ����ϴ�. �ٽ� �Է��� �ּ���.\n"); PrintLoading(1);
			continue;
		}
	}
	return 0;
}
