// terminate_service.cpp

// 클래스 선언 포함
#include "terminate_service.h"
#include "terminate_service_ui.h"

/*
    함수 이름 : TerminateService::TerminateService
    기능      : 종료 서비스 클래스의 기본 생성자
    전달 인자 : 없음
    반환값    : 없음
*/
TerminateService::TerminateService() {}

/*
    함수 이름 : TerminateService::GetInterface
    기능      : 서비스 종료 UI를 시작함
    전달 인자 : ui (TerminateServiceUI*) - boundary class 포인터
                in_fp (ifstream&) - 입력 파일 스트림
                out_fp (ofstream&) - 출력 파일 스트림
    반환값    : 없음
*/
void TerminateService::GetInterface(TerminateServiceUI* ui, ifstream& in_fp, ofstream& out_fp) {
    ui->StartInterface(out_fp);
}
