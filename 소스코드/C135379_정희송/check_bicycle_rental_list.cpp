// check_bicycle_rental_list.cpp

// 클래스 선언 포함
#include "check_bicycle_rental_list_ui.h"
#include "check_bicycle_rental_list.h"
#include "account_list.h"
#include "account.h"
#include "bicycle.h"
#include "bicycle_collection.h"

// 헤더 선언
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
    함수 이름 : CheckBicycleRentalList::CheckBicycleRentalList
    기능      : 전달받은 AccountList 포인터를 멤버 변수에 저장함
    전달 인자 : account_list (AccountList*) - 계정 리스트 객체 포인터
    반환값    : 없음
*/
CheckBicycleRentalList::CheckBicycleRentalList(AccountList* account_list)
    : account_list_(account_list) {}

/*
    함수 이름 : CheckBicycleRentalList::GetInterface
    기능      : 사용자 인터페이스를 시작하고, 대여 자전거 목록 출력 인터페이스를 호출함
    전달 인자 : ui (CheckBicycleRentalListUI*) - boundary class 포인터
                in_fp (ifstream&) - 입력 파일
                out_fp (ofstream&) - 출력 파일
    반환값    : 없음
*/
void CheckBicycleRentalList::GetInterface(CheckBicycleRentalListUI* ui, ifstream& in_fp, ofstream& out_fp) {
    ui->StartInterface(in_fp);
    ui->ShowRentedBicycleInterface(out_fp, rented_bicycle_list_);
}

/*
    함수 이름 : CheckBicycleRentalList::CheckRentedBicycleList
    기능      : 로그인된 계정의 자전거 대여 목록을 조회하여 저장함
    전달 인자 : 없음
    반환값    : 없음
*/
void CheckBicycleRentalList::CheckRentedBicycleList() {
    Account* acc = account_list_->GetSignedInAccount();
    rented_bicycle_list_ = acc->GetOwnedBicycleCollection();
}

/*
    함수 이름 : CheckBicycleRentalList::GetRentedBicycleCollection
    기능      : 현재 저장된 대여 자전거 목록을 반환함
    전달 인자 : 없음
    반환값    : BicycleCollection* - 대여 자전거 목록 포인터
*/
BicycleCollection* CheckBicycleRentalList::GetRentedBicycleCollection() {
    return rented_bicycle_list_;
}
