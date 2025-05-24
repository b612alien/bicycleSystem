// bicycle_list.cpp

// 클래스 선언 포함
#include "bicycle_list.h"
#include "bicycle.h"

// 헤더 선언
#include <string>
#include <fstream>

using namespace std;

/*
    함수 이름 : BicycleList::BicycleList
    기능      : BicycleList 객체를 초기화함
    전달 인자 : 없음
    반환값    : 없음
*/
BicycleList::BicycleList() {}

/*
    함수 이름 : BicycleList::~BicycleList
    기능      : 리스트에 저장된 자전거 객체의 메모리를 해제하고 리스트를 비움
    전달 인자 : 없음
    반환값    : 없음
*/
BicycleList::~BicycleList() {
    for (int i = 0; i < bicycles_.size(); i++) {
        delete bicycles_[i];
    }
    bicycles_.clear();
}

/*
    함수 이름 : BicycleList::AddNewBicycle
    기능      : 새로운 자전거 객체를 생성하여 리스트에 추가함
    전달 인자 : id (string) - 자전거 ID
                product_name (string) - 자전거 제품명
    반환값    : 없음
*/
void BicycleList::AddNewBicycle(string id, string product_name) {
    Bicycle* new_bike = new Bicycle(id, product_name);
    bicycles_.push_back(new_bike);
}

/*
    함수 이름 : BicycleList::GetBicycles
    기능      : 전체 자전거 리스트를 반환함
    전달 인자 : 없음
    반환값    : const vector<Bicycle*>& - 자전거 포인터 리스트
*/
const vector<Bicycle*>& BicycleList::GetBicycles() const {
    return bicycles_;
}

/*
    함수 이름 : BicycleList::GetBicycleByID
    기능      : 주어진 ID와 일치하는 자전거 객체를 찾아 반환함
    전달 인자 : id (string) - 찾는 자전거 ID
    반환값    : Bicycle* - 해당 자전거 포인터, 없으면 nullptr
*/
Bicycle* BicycleList::GetBicycleByID(string id) {
    for (int i = 0; i < bicycles_.size(); i++) {
        Bicycle* bike = bicycles_[i];
        if (id == bike->GetBicycleID()) {
            return bike;
        }
    }
    return nullptr;
}
