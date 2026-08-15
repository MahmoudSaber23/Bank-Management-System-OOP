#pragma once


#include "ScreenHeader.h"
#include "BankUser.h"
#include "InputValidate.h"



class UpdateUserScreen :protected ScreenHeader
{
private:

    static void _UpdateUserInfo(BankUser& User)
    {
        cout << "\nEnter FirstName? "; User.FirstName = InputValidate::ReadString();

        cout << "\nEnter LastName? "; User.LastName = InputValidate::ReadString();

        cout << "\nEnter Email? "; User.Email = InputValidate::ReadString();

        cout << "\nEnter Phone? "; User.Phone = InputValidate::ReadString();

        cout << "\nEnter Password? "; User.Password = InputValidate::ReadString();

        cout << "\nEnter Permissions? "; User.Permissions = _ReadPermissionsToSet();
    }

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

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += BankUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += BankUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += BankUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += BankUser::enPermissions::pUpdateClient;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += BankUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += BankUser::enPermissions::pTransactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += BankUser::enPermissions::pManageUsers;
        }

        cout << "\nShow Login Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += BankUser::enPermissions::pLoginRegister;
        }

        return Permissions;
    }

    static void _UpdateUser()
    {
        string UserName = "";

        cout << "\nPlease Enter UserName? ";
        UserName = InputValidate::ReadString();

        while (!BankUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Not Found, Choose another UserName? ";
            UserName = InputValidate::ReadString();
        }

        BankUser UpdateUser = BankUser::Find(UserName);

        _PrintUser(UpdateUser);

        char Answer = 'n';
        cout << "\nAre you sure do you want to Update this user? (Y/N)?";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            cout << "\n\nUpdate User Info:";
            cout << "\n=====================\n";

            _UpdateUserInfo(UpdateUser);

            BankUser::enSaveResults SaveResult;

            SaveResult = UpdateUser.Save();

            switch (SaveResult)
            {
            case  BankUser::enSaveResults::svSucceeded:
            {
                cout << "\n\nUser Updated Successfully :-)\n";
                _PrintUser(UpdateUser);
                break;
            }
            case BankUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError User was not saved because it's Empty";
                break;

            }
            case BankUser::enSaveResults::svFaildUserExists:
            {

                cout << "\nError User was not saved because UserName is used!\n";
                break;
            }
            }
        }
        else
        {
            cout << "\n\nError User Was Not Updated!\n\n";
        }
    }


public:

    static void ShowUpdateUserScreen()
    {
        DrawScreenHeader("\tUpdate User Screen");

        _UpdateUser();
    }
};

