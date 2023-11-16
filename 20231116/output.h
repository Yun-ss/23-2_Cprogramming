#pragma once

/**
 * @brief ���� �޴��� ����մϴ�.
 */
void PrintMenu(void);

/**
 * @brief �ε����̶�� ǥ�ø� �ֿܼ� ����մϴ�.
 * 
 * @param loadingTime: �ε� �ð�
 */
void PrintLoading(const int);

/**
 * @brief �Է��� score�� ���� letter grade (e.g., A+)�� ����մϴ�.
 *
 * @param score: ù ��° ����
 */
void PrintLetterGrade(const int);

/**
 * @brief numerical grade 3���� �Է¹޾� ��� ������ �Ҽ��� ��°�ڸ����� (e.g., 3.73) ����մϴ�.
 *
 * @param score1: ù ��° ����
 * @param score2: �� ��° ����
 * @param score3: �� ��° ����
 */
void PrintAverageNumericalGrade(const int, const int, const int);



/**
 * @brief �ܼ�â�� �ؽ�Ʈ ��� ������ �����մϴ�.
 * 
 * @param textColor: ���� ���� ������
 */
void SetConsoleTextColor(const int);

/**
 * @brief ������� ��µǴ� printf �Լ��Դϴ�.
 */
void printf_g(const char*);

/**
 * @brief ���������� ��µǴ� printf �Լ��Դϴ�.
 */
void printf_r(const char*);

/**
 * @brief �Է� ���۸� ���ϴ�.
 */
void ClearLineFromReadBuffer(void);