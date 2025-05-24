// account_list.cpp

// 클래스 선언 포함
#include "account_list.h"
#include "account.h"

/*
    함수 이름 : AccountList::AccountList
    기능      : AccountList 객체를 초기화하고, admin 계정을 기본으로 추가함
    전달 인자 : 없음
    반환값    : 없음
*/
AccountList::AccountList() {
    Account* admin = new Account("admin", "admin", "");
    accounts_.push_back(admin);
}

/*
    함수 이름 : AccountList::~AccountList
    기능      : accounts_에 저장된 모든 Account 객체의 메모리를 해제하고 리스트를 비움
    전달 인자 : 없음
    반환값    : 없음
*/
AccountList::~AccountList() {
    for (int i = 0; i < accounts_.size(); i++) {
        delete accounts_[i];
    }
    accounts_.clear();
}

/*
    함수 이름 : AccountList::SignIn
    기능      : id를 받아 대조 후 signed_in_account_에 저장
    전달 인자 : id (String) - string으로 id 전달
    반환값    : 없음
*/
void AccountList::SignIn(string id) {
    for (int i = 0; i < accounts_.size(); i++) {
        Account* acc = accounts_[i];
        if (id == acc->GetID()) {
            signed_in_account_ = acc;
        }
    }
}

/*
    함수 이름 : AccountList::SignOut
    기능      : 로그인 계정을 초기화하여 로그아웃 상태로 만듦
    전달 인자 : 없음
    반환값    : 없음
*/
void AccountList::SignOut() {
    signed_in_account_ = nullptr;
}

/*
    함수 이름 : AccountList::AddNewAccount
    기능      : 전달받은 정보로 새로운 Account 객체를 생성하여 리스트에 추가함
    전달 인자 : id (string) - 계정 ID
                password (string) - 계정 비밀번호
                phone (string) - 계정 전화번호
    반환값    : 없음
*/
void AccountList::AddNewAccount(string id, string password, string phone) {
    Account* new_acc = new Account(id, password, phone);
    accounts_.push_back(new_acc);
}

/*
    함수 이름 : AccountList::GetAccounts
    기능      : 등록된 모든 Account 객체 리스트를 반환함
    전달 인자 : 없음
    반환값    : vector<Account*> - 계정 리스트
*/
vector<Account*> AccountList::GetAccounts() {
    return accounts_;
}

/*
    함수 이름 : AccountList::GetSignedInAccount
    기능      : 현재 로그인된 계정 객체를 반환함
    전달 인자 : 없음
    반환값    : Account* - 로그인된 계정 포인터
*/
Account* AccountList::GetSignedInAccount() {
    return signed_in_account_;
}
