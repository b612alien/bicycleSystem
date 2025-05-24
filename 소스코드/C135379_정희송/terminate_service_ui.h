// terminate_service_ui.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class TerminateService;

// 로그아웃하는 SignOut boundary class를 정의
class TerminateServiceUI {
private:
    TerminateService* control_; // control class 멤버 변수 선언

public:
    TerminateServiceUI(TerminateService* control); // control class 초기화하는 생성자
    void StartInterface(ofstream& out_fp); // 인터페이스 시작
    void ShowTerminateServiceInterface(ofstream& out_fp); // 종료 시 메세지를 보임
};
