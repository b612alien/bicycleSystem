// register_account.cpp

// 클래스 선언 포함
#include "register_account.h"
#include "register_account_ui.h"
#include "account_list.h"

 /*
    함수 이름 : RegisterAccount::RegisterAccount
    기능      : 전달받은 AccountList 포인터를 멤버 변수에 저장함
    전달 인자 : account_list (AccountList*) - 계정 리스트 객체 포인터
    반환값    : 없음
*/
RegisterAccount::RegisterAccount(AccountList* account_list)
    :account_list_(account_list) {}

/*
    함수 이름 : RegisterAccount::GetInterface
    기능      : 사용자 인터페이스를 시작하고, 등록된 계정 정보를 출력함
    전달 인자 : ui (RegisterAccountUI*) - boundary class 포인터
                in_fp (ifstream&) - 입력 파일
                out_fp (ofstream&) - 출력 파일
    반환값    : 없음
*/
void RegisterAccount::GetInterface(RegisterAccountUI* ui, ifstream& in_fp, ofstream& out_fp) {
    ui->StartInterface(in_fp);
    Account* acc = account_list_->GetAccounts().back(); // 새로 등록된 계정 정보를 acc에 저장
    ui->ShowRegisterAccountInterface(out_fp, acc); // ui에 인자로 정보 전달하기
}

/*
    함수 이름 : RegisterAccount::AddNewAccount
    기능      : 새로운 계정을 AccountList에 추가
    전달 인자 : ID (string) - 사용자 ID
                password (string) - 사용자 비밀번호
                phone (string) - 사용자 전화번호
    반환값    : 없음
*/
void RegisterAccount::AddNewAccount(string ID, string password, string phone) {
    account_list_->AddNewAccount(ID, password, phone);
}
