// register_bicycle.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class RegisterBicycleUI;
class BicycleList;
class Bicycle;

// 자전거를 등록할 수 있는 RegisterBicycle 이름의 control class를 정의
class RegisterBicycle {
private:
    BicycleList* bicycle_list_; // 자전거 목록

public:
    RegisterBicycle(BicycleList* bicycle_list); // 생성자
    void GetInterface(RegisterBicycleUI* ui, ifstream& in_fp, ofstream& out_fp); // 인터페이스 호출
    void AddNewBicycle(string id, string product_name); // 새로운 자전거 추가하기
};