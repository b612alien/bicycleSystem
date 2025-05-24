// terminate_service_ui.cpp

// 클래스 선언 포함
#include "terminate_service_ui.h"
#include "terminate_service.h"

// 헤더 선언
#include <fstream>

using namespace std;

/*
    함수 이름 : TerminateServiceUI::TerminateServiceUI
    기능      : 종료 서비스 UI 객체를 초기화함
    전달 인자 : control (TerminateService*) - control class 포인터
    반환값    : 없음
*/
TerminateServiceUI::TerminateServiceUI(TerminateService* control)
    : control_(control) {}

/*
    함수 이름 : TerminateServiceUI::StartInterface
    기능      : UI 실행을 시작하고 종료 메시지를 출력함
    전달 인자 : out_fp (ofstream&) - 출력 파일
    반환값    : 없음
*/
void TerminateServiceUI::StartInterface(ofstream& out_fp) {
    ShowTerminateServiceInterface(out_fp);
}

/*
    함수 이름 : TerminateServiceUI::ShowTerminateServiceInterface
    기능      : 종료 메시지를 출력 파일에 출력함
    전달 인자 : out_fp (ofstream&) - 출력 파일
    반환값    : 없음
*/
void TerminateServiceUI::ShowTerminateServiceInterface(ofstream& out_fp) {
    out_fp << "6.1. 종료";
}
