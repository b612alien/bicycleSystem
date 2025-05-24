// account.cpp

// 클래스 선언 포함
#include "account.h"
#include "bicycle_collection.h"

// 헤더 선언
#include <string>
#include <stdexcept>

using namespace std;

/*
    함수 이름 : Account::Account
    기능      : 전달받은 ID, 비밀번호, 전화번호로 Account 객체를 초기화함
                ID 또는 비밀번호가 비어 있으면 예외를 발생시킴
    전달 인자 : id (string) - 사용자 ID
                password (string) - 사용자 비밀번호
                phone (string) - 사용자 전화번호
    반환값    : 없음
*/
Account::Account(string id, string password, string phone)
    : id_(id), password_(password), phone_number_(phone) {
    if (id == "" || password == "") {
        throw runtime_error("ID와 비밀번호를 비워둘 수 없습니다.");
    }
}

/*
    함수 이름 : Account::~Account
    기능      : 소유한 BicycleCollection 객체가 존재할 경우 메모리를 해제함
    전달 인자 : 없음
    반환값    : 없음
*/
Account::~Account() {
    if (owned_bicycle_collection_ != nullptr) {
        delete owned_bicycle_collection_;
        owned_bicycle_collection_ = nullptr;
    }
}

/*
    함수 이름 : Account::GetID
    기능      : 계정 ID를 반환함
    전달 인자 : 없음
    반환값    : string - 계정 ID
*/
string Account::GetID() {
    return id_;
}

/*
    함수 이름 : Account::GetPassword
    기능      : 계정 비밀번호를 반환함
    전달 인자 : 없음
    반환값    : string - 계정 비밀번호
*/
string Account::GetPassword() {
    return password_;
}

/*
    함수 이름 : Account::GetPhoneNumber
    기능      : 계정 전화번호를 반환함
    전달 인자 : 없음
    반환값    : string - 계정 전화번호
*/
string Account::GetPhoneNumber() {
    return phone_number_;
}

/*
    함수 이름 : Account::GetOwnedBicycleCollection
    기능      : 계정이 소유한 BicycleCollection 객체를 반환함
                객체가 없을 경우 동적으로 생성함
    전달 인자 : 없음
    반환값    : BicycleCollection* - 소유한 자전거 목록 포인터
*/
BicycleCollection* Account::GetOwnedBicycleCollection() {
    if (owned_bicycle_collection_ == nullptr) {
        owned_bicycle_collection_ = new BicycleCollection();
    }
    return owned_bicycle_collection_;
}
