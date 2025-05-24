// account_list.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class Account;

// 계정 목록 AccountList class를 정의
class AccountList {
private:
    vector<Account*> accounts_; // 계정 목록을 Account 타입으로 정의
    Account* signed_in_account_; // 로그인된 계정

public:
    AccountList(); // 생성자
    ~AccountList(); // 소멸자

    void SignIn(string id); // 받은 id를 가지고 대조 후 계정을 signed_in_account_에 넣어 로그인된 계정으로 설정
    void SignOut(); // signed_in_account_ 비워서 로그아웃 처리

    void AddNewAccount(string id, string password, string phone); // AccountList에 새로운 계정 등록
    vector<Account*> GetAccounts(); // 계정 목록 반환하기
    Account* GetSignedInAccount(); // 로그인된 계정을 반환하기
};
