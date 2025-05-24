// bicycle_collection.cpp

// 클래스 선언 포함
#include "bicycle_collection.h"
#include "bicycle.h"

// 헤더 선언
#include <string>
#include <stdexcept>

using namespace std;

/*
    함수 이름 : BicycleCollection::BicycleCollection
    기능      : BicycleCollection 객체를 초기화함
    전달 인자 : 없음
    반환값    : 없음
*/
BicycleCollection::BicycleCollection() {}

/*
    함수 이름 : BicycleCollection::~BicycleCollection
    기능      : 자전거 대여 목록을 비움
    전달 인자 : 없음
    반환값    : 없음
*/
BicycleCollection::~BicycleCollection() {
    rented_bicycles_.clear();
}

/*
    함수 이름 : BicycleCollection::GetRentedBicycles
    기능      : 대여한 자전거 리스트를 반환함
    전달 인자 : 없음
    반환값    : const vector<Bicycle*>& - 자전거 포인터 리스트
*/
const vector<Bicycle*>& BicycleCollection::GetRentedBicycles() const {
    return rented_bicycles_;
}

/*
    함수 이름 : BicycleCollection::AddRentalBicycle
    기능      : 자전거를 대여 목록에 추가함
    전달 인자 : bike (Bicycle*) - 대여된 자전거 객체 포인터
    반환값    : 없음
*/
void BicycleCollection::AddRentalBicycle(Bicycle* bike) {
    rented_bicycles_.push_back(bike);
}
