// register_account.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class RegisterAccountUI;
class AccountList;
class Account;

// 계정을 등록할 수 있는 RegisterAccount 이름의 control class를 정의
class RegisterAccount {
private:
    AccountList* account_list_; // 계정 목록

public:
    RegisterAccount(AccountList* account_list); // 생성자
    void GetInterface(RegisterAccountUI* ui, ifstream& in_fp, ofstream& out_fp); // 인터페이스 호출
    void AddNewAccount(string id, string password, string phone); // 새로운 계정 추가하기
};