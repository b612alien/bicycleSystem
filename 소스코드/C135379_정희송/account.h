// account.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class BicycleCollection;
class Bicycle;

// 계정 Account class를 정의
class Account {
private:
    string id_; // ID
    string password_; // 비밀번호
    string phone_number_; // 전화번호
    BicycleCollection* owned_bicycle_collection_; // 대여 자전거 목록 관리하는 class에 대한 포인터

public:
    Account(string id, string password, string phone); // 생성자 - 아이디, 비밀번호, 전화번호 초기화함
    ~Account(); // 소멸자
    string GetID(); // ID 반환
    string GetPassword(); // 비밀번호 반환
    string GetPhoneNumber(); // 전화번호 반환
    BicycleCollection* GetOwnedBicycleCollection(); // 대여 자전거 목록 포인터 반환
};
