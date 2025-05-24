// bicycle_list.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class Bicycle;

// 전체 자전거 목록 BicycleList class를 정의
class BicycleList {
private:
    vector<Bicycle*> bicycles_; // 등록된 전체 자전거 목록

public:
    BicycleList(); // 생성자
    ~BicycleList(); // 소멸자
    void AddNewBicycle(string id, string product_name); // 새로운 자전거 등록
    const vector<Bicycle*>& GetBicycles() const; // 모든 자전거 목록 반환하기
    Bicycle* GetBicycleByID(string id); // ID로 목록에서 자전거 찾기
};
