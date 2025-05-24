// sign_in_ui.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class SignIn;
class Account;

// 로그인하는 SignIn boundary class를 정의
class SignInUI {
private:
    SignIn* control_; // control class를 멤버 변수로 선언

public:
    SignInUI(SignIn* control); // control class 변수를 초기화하는 생성자
    void StartInterface(ifstream& in_fp); // 인터페이스 시작
    void TrySignIn(ifstream& in_fp); // 사용자 입력으로 로그인 요청을 control에 전달
    void ShowSignInInterface(ofstream& out_fp, Account* sign_in_account); // 로그인 성공한 화면을 보여주기
};
