// 헤더 선언
#include <stdio.h>
#include <string.h>

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void join();
void program_exit();

// 변수 선언
ofstream out_fp;
ofstream in_fp;

// 헤더 추가
#include "account.h"
#include "bicycle.h"
#include "register_account.h"
#include "sign_in.h"

int main()
{
	// 파일 입출력을 위한 초기화
	in_fp.open(INPUT_FILE_NAME);
	out_fp.open(OUTPUT_FILE_NAME);

	doTask();
	...
	out_fp.close();
	in_fp.close();
	return 0;
}

void doTask()
{
	// level 메뉴 파싱을 위한 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	while (!is_program_exit)
	{
		// 2 입력파일에서 메뉴 숫자 개를 읽기
		in_fp >> menu_level_1 >> menu_level_2;

		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1)
		{
			case 1:
			{
				switch (menu_level_2)
				{
					case 1: // "1.1. “ 회원가입 메뉴 부분
					{
						RegisterAccount register_account_control;
						in_fp >> ID >> password >> phone_number;
						register_account_control.AddNewAccount();

						break;
					}
					case 2:
					{
						...
							break;
					}
				}
				...
			case 7:
				{
					switch (menu_level_2)
					{
					case 1: // "6.1. “ 종료 메뉴 부분
					{
						...
							is_program_exit = 1;
						break;;
					}
					}
				}
				...
			}
	}