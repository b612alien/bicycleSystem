// check_bicycle_rental_list_ui.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class CheckBicycleRentalList;
class BicycleCollection;

// 대여한 자전거 목록을 확인할 수 있는 CheckBicycleRentalListUI boundary class를 정의
class CheckBicycleRentalListUI {
private:
    CheckBicycleRentalList* control_; // control class 멤버 변수 선언

public:
    CheckBicycleRentalListUI(CheckBicycleRentalList* control); // 생성자
    void StartInterface(ifstream& in_fp); // 인터페이스 시작
    void CheckRentedBicycleList(); // 대여한 자전거 목록 확인하기
    void ShowRentedBicycleInterface(ofstream& out_fp, BicycleCollection* bicycle_collection); // 인터페이스에 대여한 자전거 목록 보여주기
};
