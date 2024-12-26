#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include"BankManager.h"


    BankManager::BankManager(const string& username, const string& password)
        : username(username), password(password) {
        ofstream managersFile("managers.txt");
        if (managersFile.is_open())
        {
            managersFile << "Desmond" << endl;
            managersFile << "1234321" << endl;
            managersFile << endl << endl << endl;
            managersFile << "andeac24" << endl;
            managersFile << "uwgb123" << endl;
            managersFile << endl << endl << endl;
            managersFile << "desmond11" << endl;
            managersFile << "1111" << endl;
            managersFile << endl << endl << endl;
        }
    }

    bool BankManager::login(const string& usernameInput, const string& passwordInput) {
        ifstream check("managers.txt");
        if (!check.is_open()) {
            cout << "File not found!\n";
            return false;
        }

        string storedUsername, storedPassword;
        while (check >> storedUsername >> storedPassword) {
            if (storedUsername == usernameInput && storedPassword == passwordInput) {
                check.close();
                return true;
            }
        }
        check.close();
        return false;
    }

    void BankManager::viewAllUserAccountSummaries() {
        ifstream check("users.txt");
        if (!check.is_open()) {
            cout << "File not found!\n";
            return;
        }
        string line = "";
        while (getline(check, line))
        {
            if (line.substr(0, 10) == "Username: ")
            {
                string tempUser = line.substr(10);
                getline(check, line);
                string tempPass = line.substr(10);
                UserAccount user = UserAccount(tempUser, tempPass);
                user.print();
                user.~UserAccount();
                cout << endl << endl;
            }

        }
        check.close();
    }
