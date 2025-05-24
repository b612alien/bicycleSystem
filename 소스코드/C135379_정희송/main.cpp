// main.cpp

// 헤더 선언
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();

// 변수 선언
ofstream out_fp;
ifstream in_fp;

// 헤더 추가
#include "account.h"
#include "account_list.h"

#include "bicycle.h"
#include "bicycle_list.h"

#include "register_account.h"
#include "register_account_ui.h"

#include "sign_in.h"
#include "sign_in_ui.h"

#include "sign_out.h"
#include "sign_out_ui.h"

#include "register_bicycle.h"
#include "register_bicycle_ui.h"

#include "rental_bicycle.h"
#include "rental_bicycle_ui.h"

#include "check_bicycle_rental_list.h"
#include "check_bicycle_rental_list_ui.h"

#include "terminate_service.h"
#include "terminate_service_ui.h"

int main()
{
	// 파일 입출력을 위한 초기화
	in_fp.open(INPUT_FILE_NAME);
	out_fp.open(OUTPUT_FILE_NAME);

	// 메뉴 함수 시작
	doTask();

	out_fp.close();
	in_fp.close();
	return 0;
}

/*
	메뉴 함수 
*/
void doTask()
{
	// level 메뉴 파싱을 위한 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	// 클래스 선언
	AccountList account_list;
	BicycleList bicycle_list;

	RegisterAccount register_account_control(&account_list);
	RegisterAccountUI register_account_ui(&register_account_control);
	
	SignIn sign_in_control(&account_list);
	SignInUI sign_in_ui(&sign_in_control);

	SignOut sign_out_control(&account_list);
	SignOutUI sign_out_ui(&sign_out_control);

	RegisterBicycle register_bicycle_control(&bicycle_list);
	RegisterBicycleUI register_bicycle_ui(&register_bicycle_control);

	RentalBicycle rental_bicycle_control(&bicycle_list, &account_list);
	RentalBicycleUI rental_bicycle_ui(&rental_bicycle_control);

	CheckBicycleRentalList check_bicycle_rental_list_control(&account_list);
	CheckBicycleRentalListUI check_bicycle_rental_list_ui(&check_bicycle_rental_list_control);

	TerminateService terminate_service_control;
	TerminateServiceUI terminate_service_ui(&terminate_service_control);

	// 메뉴 실행
	while (!is_program_exit)
	{
		cout << "읽은 메뉴: " << menu_level_1 << " " << menu_level_2 << endl;

		// 2 입력파일에서 메뉴 숫자 2개를 읽기
		in_fp >> menu_level_1 >> menu_level_2;

		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1)
		{
		case 1:
		{
			switch (menu_level_2)
			{
			case 1: // "1.1. " 회원가입 메뉴 부분
			{
				register_account_control.GetInterface(&register_account_ui, in_fp, out_fp); // 회원가입 UI 클래스를 통해 화면 인터페이스 불러오기
				break;
			}
			}
			break;
		}
		case 2:
		{
			switch (menu_level_2)
			{
			case 1: // "2.1. " 로그인 메뉴 부분
			{
				sign_in_control.GetInterface(&sign_in_ui, in_fp, out_fp);
				break;
			}
			case 2: // "2.2. " 로그아웃 메뉴 부분
			{
				sign_out_control.GetInterface(&sign_out_ui, in_fp, out_fp);
				break;
			}
			}
			break;
		}
		case 3:
		{
			switch (menu_level_2)
			{
			case 1: // "3.1. " 자전거 정보 등록 메뉴 부분
			{
				register_bicycle_control.GetInterface(&register_bicycle_ui, in_fp, out_fp);
				break;
			}
			}
			break;
		}
		case 4:
		{
			switch (menu_level_2)
			{
			case 1: // "4.1. " 자전거 대여 메뉴 부분
			{
				rental_bicycle_control.GetInterface(&rental_bicycle_ui, in_fp, out_fp);
				break;
			}
			}
			break;
		}
		case 5:
		{
			switch (menu_level_2)
			{
			case 1: // "5.1. " 자전거 대여 정보 조회 메뉴 부분
			{
				check_bicycle_rental_list_control.GetInterface(&check_bicycle_rental_list_ui, in_fp, out_fp);
				break;
			}
			break;
			}
		}
		case 6:
		{
			switch (menu_level_2)
			{
			case 1: // "6.1. " 종료 메뉴 부분
			{
				is_program_exit = 1;
				terminate_service_control.GetInterface(&terminate_service_ui, in_fp, out_fp);
				break;
			}
			}
			break;
		}
		}
	}
}
