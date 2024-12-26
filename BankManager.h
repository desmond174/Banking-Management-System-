#pragma once
#ifndef BANKMANAGER_H
#define BANKMANAGER_H
#include"UserAccount.h"

//class declaration

class BankManager : private UserAccount {
private:
    string username;
    string password;
public:
    BankManager(const string& username, const string& password);
    bool login(const string& usernameInput, const string& passwordInput);
    void viewAllUserAccountSummaries();

};

#endif

