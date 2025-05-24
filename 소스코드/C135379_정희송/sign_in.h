// sign_in.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class SignInUI;
class AccountList;
class Account;

// 로그인하는 SignIn control class를 정의
class SignIn {
private:
    AccountList* account_list_; // 계정 목록

public:
    SignIn(AccountList* account_list); // 계정 목록을 초기화하는 생성자
    void GetInterface(SignInUI* ui, ifstream& in_fp, ofstream& out_fp); // 인터페이스 호출
    void SignInAccount(string ID, string password); // ID와 password를 전달받아 계정 목록에서 계정 정보를 확인하고 로그인 처리를 함
};