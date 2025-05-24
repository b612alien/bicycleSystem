// rental_bicycle.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class RentalBicycleUI;
class BicycleList;
class Bicycle;
class Account;
class AccountList;

// 자전거를 대여할 수 있는 RentalBicycle 이름의 control class를 정의
class RentalBicycle {
private:
    BicycleList* bicycle_list_; // 자전거 목록
    AccountList* account_list_; // 계정 목록

public:
    RentalBicycle(BicycleList* bicycle_list, AccountList* account_list); // 생성자
    void GetInterface(RentalBicycleUI* ui, ifstream& in_fp, ofstream& out_fp); // 인터페이스 호출
    void RentBicycleByID(string id); // ID를 통해 자전거 대여 가능
};