// sign_out.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class SignOutUI;
class AccountList;
class Account;

// 로그아웃하는 SignOut control class를 정의
class SignOut {
private:
    AccountList* account_list_; // 계정 목록
    Account* last_signed_out_account_; // 마지막으로 로그인 되어있던 계정

public:
    SignOut(AccountList* account_list); // 계정 목록을 초기화하는 생성자
    void GetInterface(SignOutUI* ui, ifstream& in_fp, ofstream& out_fp); // 인터페이스 호출
    void SignOutAccount(); // 계정 목록에서 로그인되어있는 계정을 로그아웃 처리하기
};