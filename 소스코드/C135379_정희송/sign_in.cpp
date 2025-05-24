// sign_in.cpp

// 클래스 선언 포함
#include "sign_in.h"
#include "sign_in_ui.h"
#include "account_list.h"
#include "account.h"

// 헤더 선언
#include <fstream>
#include <string>

using namespace std;

/*
    함수 이름 : SignIn::SignIn
    기능      : 전달받은 AccountList 포인터를 멤버 변수에 저장함
    전달 인자 : acc_list (AccountList*) - 계정 리스트 포인터
    반환값    : 없음
*/
SignIn::SignIn(AccountList* acc_list)
    :account_list_(acc_list) {}

/*
    함수 이름 : SignIn::GetInterface
    기능      : 로그인 UI 인터페이스를 시작하고 결과를 출력함
    전달 인자 : ui (SignInUI*) - boundary class 포인터
                in_fp (ifstream&) - 입력 파일
                out_fp (ofstream&) - 출력 파일
    반환값    : 없음
*/
void SignIn::GetInterface(SignInUI* ui, ifstream& in_fp, ofstream& out_fp) {
    ui->StartInterface(in_fp);
    Account* acc = account_list_->GetSignedInAccount(); // 로그인된 계정 정보를 acc에 저장
    ui->ShowSignInInterface(out_fp, acc); // ui에 인자로 정보 전달하기
}

/*
    함수 이름 : SignIn::SignInAccount
    기능      : ID에 해당하는 계정을 찾아 로그인 상태로 설정함
    전달 인자 : id (string) - 사용자 ID
                password (string) - 사용자 비밀번호
    반환값    : 없음
*/
void SignIn::SignInAccount(string id, string password) {
    account_list_->SignIn(id);
}
