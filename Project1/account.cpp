// account.cpp
#include "account.h"
#include "string"
using namespace std;

// 생성자
Account::Account(string id, string password, string phone)
    : id_(id), password_(password), phone_number_(phone) {}

string Account::GetID() { return id_; }
string Account::GetPassword() { return password_; }
string Account::GetPhone() { return phone_number_; }

// 로그인
bool Account::IsVerified(string id, string password) {
    return (id_ == id && password_ == password);
}