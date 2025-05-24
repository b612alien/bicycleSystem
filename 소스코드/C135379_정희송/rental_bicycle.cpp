// rental_bicycle.cpp

// 클래스 선언 포함
#include "rental_bicycle.h"
#include "rental_bicycle_ui.h"
#include "bicycle_list.h"
#include "bicycle.h"
#include "bicycle_collection.h"
#include "account_list.h"
#include "account.h"

// 헤더 선언
#include <fstream>
#include <string>

using namespace std;

/*
    함수 이름 : RentalBicycle::RentalBicycle
    기능      : 전달받은 자전거 리스트와 계정 리스트 포인터를 멤버 변수에 저장함
    전달 인자 : bicycle_list (BicycleList*) - 전체 자전거 리스트 포인터
                account_list (AccountList*) - 계정 리스트 포인터
    반환값    : 없음
*/
RentalBicycle::RentalBicycle(BicycleList* bicycle_list, AccountList* account_list)
    :bicycle_list_(bicycle_list), account_list_(account_list) {}

/*
    함수 이름 : RentalBicycle::GetInterface
    기능      : 사용자 인터페이스를 시작하고 대여된 자전거 정보를 출력함
    전달 인자 : ui (RentalBicycleUI*) - boundary class 포인터
                in_fp (ifstream&) - 입력 파일
                out_fp (ofstream&) - 출력 파일
    반환값    : 없음
*/
void RentalBicycle::GetInterface(RentalBicycleUI* ui, ifstream& in_fp, ofstream& out_fp) {
    ui->StartInterface(in_fp);
    Bicycle* bike = account_list_->GetSignedInAccount()->GetOwnedBicycleCollection()->GetRentedBicycles().back();
    ui->ShowRentalBicycleInterface(out_fp, bike);
}

/*
    함수 이름 : RentalBicycle::RentBicycleByID
    기능      : id에 해당하는 자전거를 검색하여 로그인한 계정의 자전거 목록에 추가함
    전달 인자 : id (string) - 대여할 자전거 id
    반환값    : 없음
*/
void RentalBicycle::RentBicycleByID(string id) {
    Bicycle* bike = bicycle_list_->GetBicycleByID(id);
    Account* acc = account_list_->GetSignedInAccount();
    acc->GetOwnedBicycleCollection()->AddRentalBicycle(bike);
}
