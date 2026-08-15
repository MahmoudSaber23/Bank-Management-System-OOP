#pragma once


#include <iomanip>
#include "ScreenHeader.h"
#include "BankUser.h"
#include "InputValidate.h"


class DeleteUserScreen :protected ScreenHeader
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

    static void _DeleteUser()
    {
        string UserName = "";

        cout << "\nPlease Enter UserName? ";
        UserName = InputValidate::ReadString();

        while (!BankUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Not Found, Please Enter Another UserName? ";
            UserName = InputValidate::ReadString();
        }

        BankUser DeleteUser = BankUser::Find(UserName);

        _PrintUser(DeleteUser);

        char Answer = 'n';
        cout << "\n\nAre you sure you want to delete this user? (y/n)? ";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (DeleteUser.Delete())
            {
                cout << "\nUser Deleted Successfully:-)\n";
                _PrintUser(DeleteUser);
            }
        }
        else
        {
            cout << "\nError User Was Not Deleted\n";
        }
    }

public:

    static void ShowDeleteUserScreen()
    {
        DrawScreenHeader("\tDelete User Screen");

        _DeleteUser();
    }
};

