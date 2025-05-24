// register_account_ui.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class RegisterAccount;
class Account;

// 계정을 등록할 수 있는 RegisterAccountUI boundary class를 정의
class RegisterAccountUI {
private:
    RegisterAccount* control_; // control class 멤버 변수 선언

public:
    RegisterAccountUI(RegisterAccount* control); // 생성자
    void StartInterface(ifstream& in_fp); // 회원가입 정보 입력받을 수 있는 인터페이스 시작
    void CreateNewAccount(string id, string password, string phone_number); // 새 계정 생성하기
    void ShowRegisterAccountInterface(ofstream& out_fp, Account* registered_account); // 인터페이스에 새로 등록된 계정 정보 보여주기
};
