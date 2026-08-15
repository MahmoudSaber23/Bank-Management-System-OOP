#pragma once


#include "ScreenHeader.h"
#include "BankUser.h"
#include "InputValidate.h"




class FindUserScreen :protected ScreenHeader
{
private:

    static void _PrintUser(BankUser& User)
    {
        cout << "\nUser Card:";
        cout << "\n====================";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.getFullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n===================\n";

    }

    static void _FindUser()
    {
        string UserName = "";

        cout << "\nPlease Enter UserName? ";
        UserName = InputValidate::ReadString();

        while (!BankUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Not Found, Enter another UserName? ";
            UserName = InputValidate::ReadString();
        }

        BankUser FindUser = BankUser::Find(UserName);

        cout << "\nUser Found:-)\n";
        _PrintUser(FindUser);

    }

public:

    static void ShowFindUserScreen()
    {
        DrawScreenHeader("\tFind User Screen");

        _FindUser();
    }
};
