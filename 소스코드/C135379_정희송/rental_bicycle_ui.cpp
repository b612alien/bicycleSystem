// rental_bicycle_ui.cpp

// 클래스 선언 포함
#include "rental_bicycle_ui.h"
#include "rental_bicycle.h"
#include "bicycle.h"

// 헤더 선언
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#define MAX_STRING 32

/*
    함수 이름 : RentalBicycleUI::RentalBicycleUI
    기능      : control class 포인터를 받아 UI 객체를 초기화함
    전달 인자 : control (RentalBicycle*) - control class 포인터
    반환값    : 없음
*/
RentalBicycleUI::RentalBicycleUI(RentalBicycle* control)
    : control_(control) {}

/*
    함수 이름 : RentalBicycleUI::StartInterface
    기능      : 자전거 대여 인터페이스 시작, ID 입력 후 대여 요청
    전달 인자 : in_fp (ifstream&) - 입력 파일
    반환값    : 없음
*/
void RentalBicycleUI::StartInterface(ifstream& in_fp) {
    SubmitBicycleID(in_fp);            // 자전거 대여 요청
}

/*
    함수 이름 : RentalBicycleUI::SubmitBicycleID
    기능      : 입력 파일에서 자전거 ID를 읽고 대여 요청을 전달함
    전달 인자 : in_fp (ifstream&) - 입력 파일
    반환값    : 없음
*/
void RentalBicycleUI::SubmitBicycleID(ifstream& in_fp) {
    char id[MAX_STRING];
    in_fp >> id;  // 파일에서 자전거 ID 읽기
    control_->RentBicycleByID(id);
}

/*
    함수 이름 : RentalBicycleUI::ShowRentalBicycleInterface
    기능      : 대여 완료된 자전거 정보를 출력 파일에 출력함
    전달 인자 : out_fp (ofstream&) - 출력 파일
                rented_bicycle (Bicycle*) - 대여된 자전거 객체
    반환값    : 없음
*/
void RentalBicycleUI::ShowRentalBicycleInterface(ofstream& out_fp, Bicycle* rented_bicycle) {
    out_fp << "4.1. 자전거 대여" << endl;
    out_fp << "> " << rented_bicycle->GetBicycleDetails() << endl << endl;
}
