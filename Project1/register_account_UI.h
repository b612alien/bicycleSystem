// register_account_UI.h
#pragma once
#include "register_account.h"

class RegisterAccountUI {
private:
    RegisterAccount* control;

public:
    RegisterAccountUI(RegisterAccount* control);
    void CreateNewAccount(ifstream& in_fp, ofstream& out_fp);
};
