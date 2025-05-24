// check_bicycle_rental_list_ui.cpp

// 클래스 선언 포함
#include "check_bicycle_rental_list_ui.h"
#include "check_bicycle_rental_list.h"
#include "bicycle_collection.h"
#include "bicycle.h"
#include "account.h"

// 헤더 선언
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_STRING 32

/*
    함수 이름 : CheckBicycleRentalListUI::CheckBicycleRentalListUI
    기능      : control class 포인터를 받아 UI 객체를 초기화함
    전달 인자 : control (CheckBicycleRentalList*) - control class 포인터
    반환값    : 없음
*/
CheckBicycleRentalListUI::CheckBicycleRentalListUI(CheckBicycleRentalList* control)
    : control_(control) {}

/*
    함수 이름 : CheckBicycleRentalListUI::StartInterface
    기능      : 자전거 대여 목록 조회를 시작함
    전달 인자 : in_fp (ifstream&) - 입력 파일
    반환값    : 없음
*/
void CheckBicycleRentalListUI::StartInterface(ifstream& in_fp) {
    CheckRentedBicycleList();
}

/*
    함수 이름 : CheckBicycleRentalListUI::CheckRentedBicycleList
    기능      : control class의 대여 목록 조회 함수를 호출함
    전달 인자 : 없음
    반환값    : 없음
*/
void CheckBicycleRentalListUI::CheckRentedBicycleList() {
    control_->CheckRentedBicycleList();
}

/*
    함수 이름 : CheckBicycleRentalListUI::ShowRentedBicycleInterface
    기능      : 출력 파일을 이용해 대여한 자전거 목록을 화면에 출력함
    전달 인자 : out_fp (ofstream&) - 출력 파일
                rented_bicycle_list (BicycleCollection*) - 대여 자전거 목록 포인터
    반환값    : 없음
*/
void CheckBicycleRentalListUI::ShowRentedBicycleInterface(ofstream& out_fp, BicycleCollection* rented_bicycle_list) {
    out_fp << "5.1. 자전거 대여 리스트" << endl;

    vector<Bicycle*> bikes = rented_bicycle_list->GetRentedBicycles(); // 정렬만 위해 로컬 벡터에 복사

    sort(bikes.begin(), bikes.end(), [](Bicycle* a, Bicycle* b) { // ID순으로 오름차순 정렬
        return a->GetBicycleID() < b->GetBicycleID();
        });

    for (Bicycle* bike : bikes) { // 포맷에 맞춰 출력
        out_fp << "> " << bike->GetBicycleDetails() << endl;
    }

    out_fp << endl;
}
