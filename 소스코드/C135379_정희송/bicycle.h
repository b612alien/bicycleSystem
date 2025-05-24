// bicycle.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 자전거 Bicycle class를 정의
class Bicycle {
private:
    string id_; // 자전거 ID
    string product_name_; // 자전거 제품명

public:
    Bicycle(string id, string product_name); // 생성자
    string GetBicycleID(); // 자전거 id 반환하기
    string GetBicycleDetails(); // 자전거 id와 제품명 차례로 반환하기
};
