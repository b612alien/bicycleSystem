// register_bicycle_ui.cpp

// 클래스 선언 포함
#include "register_bicycle_ui.h"
#include "register_bicycle.h"
#include "bicycle.h"

// 헤더 선언
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#define MAX_STRING 32

/*
    함수 이름 : RegisterBicycleUI::RegisterBicycleUI
    기능      : control class 포인터를 받아 UI 객체를 초기화함
    전달 인자 : control (RegisterBicycle*) - control class 포인터
    반환값    : 없음
*/
RegisterBicycleUI::RegisterBicycleUI(RegisterBicycle* control)
    : control_(control) {}

/*
    함수 이름 : RegisterBicycleUI::StartInterface
    기능      : 자전거 등록을 위한 입력을 처리함
    전달 인자 : in_fp (ifstream&) - 입력 파일
    반환값    : 없음
*/
void RegisterBicycleUI::StartInterface(ifstream& in_fp) {
    CreateNewBicycle(in_fp);
}

/*
    함수 이름 : RegisterBicycleUI::CreateNewBicycle
    기능      : 파일에서 자전거 정보를 읽고 자전거 등록을 요청함
    전달 인자 : in_fp (ifstream&) - 입력 파일
    반환값    : 없음
*/
void RegisterBicycleUI::CreateNewBicycle(ifstream& in_fp) {
    char id[MAX_STRING], product_name[MAX_STRING];
    in_fp >> id >> product_name;  // 파일에서 자전거 ID와 제품명 읽음
    control_->AddNewBicycle(id, product_name);
}

/*
    함수 이름 : RegisterBicycleUI::ShowRegisterBicycleInterface
    기능      : 자전거 등록 결과를 출력 파일에 출력함
    전달 인자 : out_fp (ofstream&) - 출력 파일
                registered_bicycle (Bicycle*) - 등록된 자전거 객체
    반환값    : 없음
*/
void RegisterBicycleUI::ShowRegisterBicycleInterface(ofstream& out_fp, Bicycle* registered_bicycle) {
    out_fp << "3.1. 자전거 등록" << endl;
    out_fp << "> " << registered_bicycle->GetBicycleDetails() << endl << endl;
}
