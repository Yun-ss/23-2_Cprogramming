#pragma once

#define NAME_LEN 10
#define PHONE_LEN 15
#define ID_LEN 10 

/**
 * @brief 학생의 정보를 나타냅니다.
 *
 * 이 구조체는 학생 정보(예: 이름, 휴대폰번호, 학번, c언어 성적, 정보보안 성적, 네트워크 성적)를 저장하기 위해 사용됩니다. 
 *
 * @struct StudentInfo
 */
typedef struct _stuInfo {
	char name[NAME_LEN]; // 학생의 풀네임
	char phoneNum[PHONE_LEN]; // 학생의 전화번호
	char ID[ID_LEN]; // 학생의 학번
	int cScore; // c언어 성적 (0~100)
	int securityScore; // 정보보안 성적 (0~100)
	int networkScore; // 네트워크 성적 (0~100)
}StudentInfo;

/**
 * @brief 학생 정보를 입력받고 저장합니다.
 */
void InputStudentInfo(void);

/**
 * @brief 모든 학생 정보를 출력합니다.
 */
void PrintAllStudentInfo(void);

/**
 * @brief 모든 학생 정보를 파일에 저장합니다.
 */
void StoreAllStudentInfo(void);

/**
 * @brief 모든 학생 정보를 불러옵니다.
 */
void LoadAllStudentInfo(void);

/**
 * @brief 학생 정보를 변경합니다.
 */
void ChangeStudentInfo(void);

/**
 * @brief 학생 정보를 삭제합니다.
 */
void DeleteStudentInfo(void);

/**
 * @brief 동적할당된 메모리를 해제합니다.
 */
void FreeStructMemory(void);

/**
 * @brief ID(학번)를 통해 해당 학생의 배열 인덱스를 반환합니다.
 *
 * @param ID: 학생의 학번
 * @return 학번에 해당하는 학생의 배열 인덱스, 존재하지 않을 시 -1
 */
int GetStudentIdxByID(const char*);

/**
 * @brief ID(학번)를 통해 등록된 학생인지 확인합니다.
 *
 * @param ID: 학생의 학번
 * @return 이미 등록되어 있을 경우 1, 아닐 경우 0
 */
int IsRegistID(const char*);
