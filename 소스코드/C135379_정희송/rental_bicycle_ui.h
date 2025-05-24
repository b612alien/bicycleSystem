// rental_bicycle_ui.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class RentalBicycle;
class Bicycle;

// 자전거를 대여할 수 있는 RentalBicycleUI boundary class를 정의
class RentalBicycleUI {
private:
    RentalBicycle* control_; // control class 멤버 변수 선언

public:
    RentalBicycleUI(RentalBicycle* control); // 생성자
    void StartInterface(ifstream& in_fp); // 인터페이스 시작
    void SubmitBicycleID(ifstream& in_fp); // 자전거 ID 입력받아서 control class로 전달
    void ShowRentalBicycleInterface(ofstream& out_fp, Bicycle* rented_bicycle); // 대여 완료 화면 보여주기
};
