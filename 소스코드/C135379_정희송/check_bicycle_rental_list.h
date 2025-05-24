// check_bicycle_rental_list.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class CheckBicycleRentalListUI;
class AccountList;
class Account;
class Bicycle;
class BicycleCollection;

// 대여한 자전거 목록을 확인할 수 있는 CheckBicycleRentalList 이름의 control class를 정의
class CheckBicycleRentalList {
private:
    AccountList* account_list_; // 계정 목록
    BicycleCollection* rented_bicycle_list_; // 대여한 자전거 목록

public:
    CheckBicycleRentalList(AccountList* account_list); // 생성자
    void GetInterface(CheckBicycleRentalListUI* ui, ifstream& in_fp, ofstream& out_fp); // 인터페이스 호출
    void CheckRentedBicycleList(); // 대여한 자전거 목록 확인하기
    BicycleCollection* GetRentedBicycleCollection(); // 대여한 자전거 목록 반환
};