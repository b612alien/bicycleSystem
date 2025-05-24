// sign_in_ui.cpp

// 클래스 선언 포함
#include "sign_in_ui.h"
#include "sign_in.h"
#include "account_list.h"
#include "account.h"

// 헤더 선언
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#define MAX_STRING 32

/*
    함수 이름 : SignInUI::SignInUI
    기능      : control class 포인터를 받아 UI 객체를 초기화함
    전달 인자 : control (SignIn*) - 제어 클래스 포인터
    반환값    : 없음
*/
SignInUI::SignInUI(SignIn* control)
    : control_(control) {}

/*
    함수 이름 : SignInUI::StartInterface
    기능      : 로그인 과정을 시작하고 로그인 정보를 입력받음
    전달 인자 : in_fp (ifstream&) - 입력 파일
    반환값    : 없음
*/
void SignInUI::StartInterface(ifstream& in_fp) {
    TrySignIn(in_fp); // 로그인 시도
}

/*
    함수 이름 : SignInUI::TrySignIn
    기능      : 입력 파일에서 ID와 비밀번호를 읽어 로그인 요청을 전달함
    전달 인자 : in_fp (ifstream&) - 입력 파일
    반환값    : 없음
*/
void SignInUI::TrySignIn(ifstream& in_fp) {
    char id[MAX_STRING], password[MAX_STRING];
    in_fp >> id >> password;  // 파일로부터 ID와 비밀번호 입력 받음

    control_->SignInAccount(id, password);
}

/*
    함수 이름 : SignInUI::ShowSignInInterface
    기능      : 로그인 성공 정보를 출력에 출력함
    전달 인자 : out_fp (ofstream&) - 출력 파일
                sign_in_account (Account*) - 로그인된 계정 객체
    반환값    : 없음
*/
void SignInUI::ShowSignInInterface(ofstream& out_fp, Account* sign_in_account) {
    out_fp << "2.1. 로그인" << endl;
    out_fp << "> " << sign_in_account->GetID() << " " << sign_in_account->GetPassword() << endl << endl;
}
