#pragma once

#define NAME_LEN 10
#define PHONE_LEN 15
#define ID_LEN 10 

/**
 * @brief �л��� ������ ��Ÿ���ϴ�.
 *
 * �� ����ü�� �л� ����(��: �̸�, �޴�����ȣ, �й�, c��� ����, �������� ����, ��Ʈ��ũ ����)�� �����ϱ� ���� ���˴ϴ�. 
 *
 * @struct StudentInfo
 */
typedef struct _stuInfo {
	char name[NAME_LEN]; // �л��� Ǯ����
	char phoneNum[PHONE_LEN]; // �л��� ��ȭ��ȣ
	char ID[ID_LEN]; // �л��� �й�
	int cScore; // c��� ���� (0~100)
	int securityScore; // �������� ���� (0~100)
	int networkScore; // ��Ʈ��ũ ���� (0~100)
}StudentInfo;

/**
 * @brief �л� ������ �Է¹ް� �����մϴ�.
 */
void InputStudentInfo(void);

/**
 * @brief ��� �л� ������ ����մϴ�.
 */
void PrintAllStudentInfo(void);

/**
 * @brief ��� �л� ������ ���Ͽ� �����մϴ�.
 */
void StoreAllStudentInfo(void);

/**
 * @brief ��� �л� ������ �ҷ��ɴϴ�.
 */
void LoadAllStudentInfo(void);

/**
 * @brief �л� ������ �����մϴ�.
 */
void ChangeStudentInfo(void);

/**
 * @brief �л� ������ �����մϴ�.
 */
void DeleteStudentInfo(void);

/**
 * @brief �����Ҵ�� �޸𸮸� �����մϴ�.
 */
void FreeStructMemory(void);

/**
 * @brief ID(�й�)�� ���� �ش� �л��� �迭 �ε����� ��ȯ�մϴ�.
 *
 * @param ID: �л��� �й�
 * @return �й��� �ش��ϴ� �л��� �迭 �ε���, �������� ���� �� -1
 */
int GetStudentIdxByID(const char*);

/**
 * @brief ID(�й�)�� ���� ��ϵ� �л����� Ȯ���մϴ�.
 *
 * @param ID: �л��� �й�
 * @return �̹� ��ϵǾ� ���� ��� 1, �ƴ� ��� 0
 */
int IsRegistID(const char*);
