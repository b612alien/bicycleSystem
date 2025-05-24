// bicycle_collection.h
#pragma once

// 헤더 선언
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 클래스 전방 선언
class Bicycle;

// 대여한 자전거 목록 관리 BicycleCollection class 정의
class BicycleCollection {
private:
	vector<Bicycle*> rented_bicycles_; // 대여한 자전거 목록

public:
	BicycleCollection(); // 생성자
	~BicycleCollection(); // 소멸자
	const vector<Bicycle*>& GetRentedBicycles() const; // 대여한 자전거 목록 반환하기
	void AddRentalBicycle(Bicycle* bike); // 대여 자전거 목록에 인자로 받은 자전거 추가하기
};