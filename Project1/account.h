// account.h
#pragma once
#include <string>
using namespace std;

class Account {
private:
    string id_;
    string password_;
    string phone_number_;

public:
    Account(string id, string password, string phone);
    string GetID();
    string GetPassword();
    string GetPhone();

    bool IsVerified(string id, string password);
};
