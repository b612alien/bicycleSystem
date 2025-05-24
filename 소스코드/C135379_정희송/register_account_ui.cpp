// register_account_ui.cpp

// 클래스 선언 포함
#include "register_account_ui.h"
#include "register_account.h"
#include "account.h"

// 헤더 선언
#include <fstream>
#include <string>

using namespace std;

#define MAX_STRING 32

/*
    함수 이름 : RegisterAccountUI::RegisterAccountUI
    기능      : control class 포인터를 받아 UI 객체를 초기화함
    전달 인자 : control (RegisterAccount*) - control class 포인터
    반환값    : 없음
*/
RegisterAccountUI::RegisterAccountUI(RegisterAccount* control)
    : control_(control) {}

/*
    함수 이름 : RegisterAccountUI::StartInterface
    기능      : 입력 파일에서 회원가입 정보를 읽고 계정을 생성함
    전달 인자 : in_fp (ifstream&) - 입력 파일
    반환값    : 없음
*/
void RegisterAccountUI::StartInterface(ifstream& in_fp) {
    char id[MAX_STRING], password[MAX_STRING], phone_number[MAX_STRING];
    in_fp >> id >> password >> phone_number; // 이름 비밀번호 휴대폰 번호를 파일로부터 읽음

    CreateNewAccount(id, password, phone_number);
}

/*
    함수 이름 : RegisterAccountUI::CreateNewAccount
    기능      : control class에 회원가입 요청을 전달함
    전달 인자 : ID (string) - 사용자 ID
                password (string) - 사용자 비밀번호
                phone_number (string) - 사용자 전화번호
    반환값    : 없음
*/
void RegisterAccountUI::CreateNewAccount(string ID, string password, string phone_number) {
    control_->AddNewAccount(ID, password, phone_number);
}

/*
    함수 이름 : RegisterAccountUI::ShowRegisterAccountInterface
    기능      : 회원가입 결과를 출력 파일에 출력함
    전달 인자 : out_fp (ofstream&) - 출력 파일
                registered_account (Account*) - 등록된 계정 객체 포인터
    반환값    : 없음
*/
void RegisterAccountUI::ShowRegisterAccountInterface(ofstream& out_fp, Account* registered_account) {
    out_fp << "1.1. 회원가입" << endl;
    out_fp << "> " << registered_account->GetID() << " " << registered_account->GetPassword() << " " << registered_account->GetPhoneNumber() << endl << endl;
}
