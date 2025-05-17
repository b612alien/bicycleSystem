// register_account.cpp
#include "register_account.h"

void RegisterAccount::AddNewAccount(string id, string password, string phone) {
    Account* newAcc = new Account(id, password, phone);
}