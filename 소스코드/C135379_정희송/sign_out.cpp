// sign_out.cpp

// 클래스 선언 포함
#include "sign_out.h"
#include "sign_out_ui.h"
#include "account_list.h"
#include "account.h"

// 헤더 선언은 없음 (필요한 표준 라이브러리 없음)

 /*
    함수 이름 : SignOut::SignOut
    기능      : AccountList 포인터를 받아 control 객체를 초기화함
    전달 인자 : account_list (AccountList*) - 계정 리스트 포인터
    반환값    : 없음
*/
SignOut::SignOut(AccountList* account_list)
    :account_list_(account_list) {}

/*
    함수 이름 : SignOut::GetInterface
    기능      : 로그아웃 UI를 시작하고, 로그아웃 결과를 출력함
    전달 인자 : ui (SignOutUI*) - boundary class 포인터
                in_fp (ifstream&) - 입력 파일 스트림
                out_fp (ofstream&) - 출력 파일 스트림
    반환값    : 없음
*/
void SignOut::GetInterface(SignOutUI* ui, ifstream& in_fp, ofstream& out_fp) {
    ui->StartInterface(in_fp);
    ui->ShowSignOutInterface(out_fp, last_signed_out_account_);
}

/*
    함수 이름 : SignOut::SignOutAccount
    기능      : 현재 로그인된 계정을 로그아웃시키고 해당 계정을 저장함
    전달 인자 : 없음
    반환값    : 없음
*/
void SignOut::SignOutAccount() {
    last_signed_out_account_ = account_list_->GetSignedInAccount();
    account_list_->SignOut();
}
