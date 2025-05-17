// register_account_UI.cpp
#include "register_account_UI.h"

RegisterAccountUI::RegisterAccountUI(RegisterAccount* control)
    : control(control) {}

void RegisterAccountUI::CreateNewAccount(ifstream& in_fp, ofstream& out_fp) {
    string id, password, phone;
    in_fp >> id >> password >> phone;

    control->AddNewAccount(id, password, phone);

    out_fp << "1.1. 회원가입" << endl;
    out_fp << "> " << id << " " << password << " " << phone << endl;
}
