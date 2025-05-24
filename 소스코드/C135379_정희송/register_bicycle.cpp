// register_bicycle.cpp

// 클래스 선언 포함
#include "register_bicycle.h"
#include "register_bicycle_ui.h"
#include "bicycle_list.h"

// 헤더 선언
#include <fstream>
#include <string>

using namespace std;

/*
    함수 이름 : RegisterBicycle::RegisterBicycle
    기능      : 전달받은 BicycleList 포인터를 멤버 변수에 저장함
    전달 인자 : bicycle_list (BicycleList*) - 자전거 리스트 객체 포인터
    반환값    : 없음
*/
RegisterBicycle::RegisterBicycle(BicycleList* bicycle_list)
    :bicycle_list_(bicycle_list) {}

/*
    함수 이름 : RegisterBicycle::GetInterface
    기능      : 사용자 인터페이스를 시작하고, 등록된 자전거 정보를 출력함
    전달 인자 : ui (RegisterBicycleUI*) - boundary class 포인터
                in_fp (ifstream&) - 입력 파일
                out_fp (ofstream&) - 출력 파일
    반환값    : 없음
*/
void RegisterBicycle::GetInterface(RegisterBicycleUI* ui, ifstream& in_fp, ofstream& out_fp) {
    ui->StartInterface(in_fp);
    Bicycle* bike = bicycle_list_->GetBicycles().back(); // bicycle_list_에 마지막으로 등록된 자전거 정보 가져오기
    ui->ShowRegisterBicycleInterface(out_fp, bike); // ui에 인자로 등록된 자전거 정보 전달
}

/*
    함수 이름 : RegisterBicycle::AddNewBicycle
    기능      : 새로운 자전거 객체를 자전거 리스트에 추가
    전달 인자 : id (string) - 자전거 ID
                product_name (string) - 자전거 제품명
    반환값    : 없음
*/
void RegisterBicycle::AddNewBicycle(string id, string product_name) {
    bicycle_list_->AddNewBicycle(id, product_name);
}
