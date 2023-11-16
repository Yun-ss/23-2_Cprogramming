#pragma once

/**
 * @brief 메인 메뉴를 출력합니다.
 */
void PrintMenu(void);

/**
 * @brief 로딩중이라는 표시를 콘솔에 출력합니다.
 * 
 * @param loadingTime: 로딩 시간
 */
void PrintLoading(const int);

/**
 * @brief 입력한 score에 따른 letter grade (e.g., A+)를 출력합니다.
 *
 * @param score: 첫 번째 정수
 */
void PrintLetterGrade(const int);

/**
 * @brief numerical grade 3개를 입력받아 평균 학점을 소숫점 둘째자리까지 (e.g., 3.73) 출력합니다.
 *
 * @param score1: 첫 번째 점수
 * @param score2: 두 번째 점수
 * @param score3: 세 번째 점수
 */
void PrintAverageNumericalGrade(const int, const int, const int);



/**
 * @brief 콘솔창의 텍스트 출력 색상을 변경합니다.
 * 
 * @param textColor: 색상에 대한 정수값
 */
void SetConsoleTextColor(const int);

/**
 * @brief 녹색으로 출력되는 printf 함수입니다.
 */
void printf_g(const char*);

/**
 * @brief 빨간색으로 출력되는 printf 함수입니다.
 */
void printf_r(const char*);

/**
 * @brief 입력 버퍼를 비웁니다.
 */
void ClearLineFromReadBuffer(void);