// register_bicycle_ui.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class RegisterBicycle;
class Bicycle;

// 자전거를 등록할 수 있는 RegisterBicycleUI boundary class를 정의
class RegisterBicycleUI {
private:
    RegisterBicycle* control_; // control class 멤버 변수 선언

public:
    RegisterBicycleUI(RegisterBicycle* control); // 생성자
    void StartInterface(ifstream& in_fp); // 인터페이스 시작
    void CreateNewBicycle(ifstream& in_fp); // 새로운 자전거 추가하기
    void ShowRegisterBicycleInterface(ofstream& out_fp, Bicycle* registered_bicycle); // 인터페이스에 새로 등록된 자전거 정보 보여주기
};
