// sign_out_ui.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class SignOut;
class Account;

// 로그아웃하는 SignOut boundary class를 정의
class SignOutUI {
private:
    SignOut* control_; // control class 멤버 변수 선언

public:
    SignOutUI(SignOut* control); // control class 초기화하는 생성자
    void StartInterface(ifstream& in_fp); // 인터페이스 시작
    void ShowSignOutInterface(ofstream& out_fp, Account* account); // 로그아웃 성공 화면을 보임
};
