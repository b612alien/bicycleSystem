// bicycle.cpp

// 클래스 선언 포함
#include "bicycle.h"

// 헤더 선언
#include <string>
#include <stdexcept>

using namespace std;

/*
    함수 이름 : Bicycle::Bicycle
    기능      : 전달받은 자전거 ID와 제품명으로 Bicycle 객체를 초기화함
                ID 또는 제품명이 비어 있을 경우 예외를 발생시킴
    전달 인자 : id (string) - 자전거 ID
                product_name (string) - 자전거 제품명
    반환값    : 없음
*/
Bicycle::Bicycle(string id, string product_name)
    : id_(id), product_name_(product_name) {

    if (id == "" || product_name_ == "") {
        throw runtime_error("ID와 제품명을 비워둘 수 없습니다.");
    }
}

/*
    함수 이름 : Bicycle::GetBicycleDetails
    기능      : 자전거 ID와 제품명을 공백으로 구분하여 반환함
    전달 인자 : 없음
    반환값    : string - ID + " " + 제품명 형식의 문자열
*/
string Bicycle::GetBicycleDetails() {
    return id_ + " " + product_name_;
}

/*
    함수 이름 : Bicycle::GetBicycleID
    기능      : 자전거 ID를 반환함
    전달 인자 : 없음
    반환값    : string - 자전거 ID
*/
string Bicycle::GetBicycleID() {
    return id_;
}
