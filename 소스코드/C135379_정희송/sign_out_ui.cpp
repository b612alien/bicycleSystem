// sign_out_ui.cpp

// 클래스 선언 포함
#include "sign_out_ui.h"
#include "sign_out.h"
#include "account.h"

// 헤더 선언
#include <fstream>

using namespace std;

/*
    함수 이름 : SignOutUI::SignOutUI
    기능      : 제어 클래스 포인터를 전달받아 UI 객체를 초기화함
    전달 인자 : control (SignOut*) - 제어 클래스 포인터
    반환값    : 없음
*/
SignOutUI::SignOutUI(SignOut* control)
    : control_(control) {}

/*
    함수 이름 : SignOutUI::StartInterface
    기능      : 로그아웃 처리를 수행함
    전달 인자 : in_fp (ifstream&) - 입력 파일
    반환값    : 없음
*/
void SignOutUI::StartInterface(ifstream& in_fp) {
    control_->SignOutAccount();
}

/*
    함수 이름 : SignOutUI::ShowSignOutInterface
    기능      : 로그아웃 결과를 출력 파일에 출력함
    전달 인자 : out_fp (ofstream&) - 출력 파일
                account (Account*) - 로그아웃된 계정 객체
    반환값    : 없음
*/
void SignOutUI::ShowSignOutInterface(ofstream& out_fp, Account* account) {
    out_fp << "2.2. 로그아웃" << endl;
    out_fp << "> " << account->GetID() << endl << endl;
}
