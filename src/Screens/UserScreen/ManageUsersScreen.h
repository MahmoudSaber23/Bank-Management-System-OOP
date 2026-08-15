#pragma once


#include <iostream>
#include <iomanip>
#include "ScreenHeader.h"
#include "InputValidate.h"
#include "UsersListScreen.h"
#include "AddNewUserScreen.h"
#include "DeleteUserScreen.h"
#include "UpdateUserScreen.h"
#include "FindUserScreen.h"


class ManageUsersScreen :protected ScreenHeader
{
	enum enManageUsersOptions { ShowUsersList = 1, AddNewUser, DeleteUser, UpdateUser, FindUser, MainMenu };

	static short _ReadManageUsersOptions()
	{
		cout << setw(37) << left << "" << "Enter what do you want to do?[1 To 6]? ";
		short Choice = InputValidate::ReadShortNumberBetween(1, 6, "Enter Number Between 1 To 6 ?");
		return Choice;
	}

	static void _GoBackToManageUsersMenu()
	{
		cout << "\n\nPress any key to go back to manage users menu...";
		system("pause>0");
		ShowManageUsersScreen();
	}

	static void _ShowUsersListScreen()
	{
		UsersListScreen::ShowUsersListScreen();
	}

	static void _ShowAddNewUserScreen()
	{
		AddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		DeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		UpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		FindUserScreen::ShowFindUserScreen();
	}

	static void _PerformMainMenuOptions(enManageUsersOptions ManageUsersOptions)
	{
		system("cls");
		switch (ManageUsersOptions)
		{
		case enManageUsersOptions::ShowUsersList:
			_ShowUsersListScreen();
			break;

		case enManageUsersOptions::AddNewUser:
			_ShowAddNewUserScreen();
			break;

		case enManageUsersOptions::DeleteUser:
			_ShowDeleteUserScreen();
			break;

		case enManageUsersOptions::UpdateUser:
			_ShowUpdateUserScreen();
			break;

		case enManageUsersOptions::FindUser:
			_ShowFindUserScreen();
			break;

		case enManageUsersOptions::MainMenu:
			break;
		}

		if (ManageUsersOptions != enManageUsersOptions::MainMenu)
		{
			_GoBackToManageUsersMenu();
		}

	}

public:

	static void ShowManageUsersScreen()
	{
		if (!CheckAccessRights(BankUser::enPermissions::pManageUsers))
		{
			return;
		}

		system("cls");
		system("color B");

		DrawScreenHeader("\tManage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tManage Users Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1]: Show Users List.\n";
		cout << setw(37) << left << "" << "\t[2]: Add New User.\n";
		cout << setw(37) << left << "" << "\t[3]: Delete User.\n";
		cout << setw(37) << left << "" << "\t[4]: Update User.\n";
		cout << setw(37) << left << "" << "\t[5]: Find User.\n";
		cout << setw(37) << left << "" << "\t[6]: Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformMainMenuOptions(enManageUsersOptions(_ReadManageUsersOptions()));
	}
};

