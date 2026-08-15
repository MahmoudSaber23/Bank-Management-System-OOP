#pragma once

#include <iostream>
#include <iomanip>
#include "ScreenHeader.h"
#include "InputValidate.h"
#include "ClientsListScreen.h"
#include "AddNewClientScreen.h"
#include "DeleteClientScreen.h"
#include "UpdateClientScreen.h"
#include "FindClientScreen.h"
#include "TransactionsScreen.h"
#include "ManageUsersScreen.h"
#include "LoginRegisterScreen.h"
#include "CurrencyScreen.h"
#include "Global.h"


class MainScreen :protected ScreenHeader
{
private:
	enum enMainMenuOptions { ShowClientsList = 1, AddNewClient, DeleteClient, UpdateClient, FindClient, Transactions, ManageUsers, LoginRegister, CurrencyExchange, Logout };

	static short _ReadMainMenuOptions()
	{
		cout << setw(37) << left << "" << "Enter what do you want to do?[1 To 10]? ";
		short Choice = InputValidate::ReadShortNumberBetween(1, 10, "Enter Number Between 1 To 10 ?");
		return Choice;
	}

	static void _GoBackToMainMenu()
	{
		cout << "\n\nPress any key to go back to main menu...";

		system("pause>0");
		ShowMainMenuScreen();
	}

	static void _ShowClientsListScreen()
	{
		ClientsListScreen::ShowClientsListScreen();
	}

	static void _ShowAddNewClientScreen()
	{
		AddNewClientScreen::ShowAddNewClinetScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		DeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		UpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		FindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsScreen()
	{
		TransactionsScreen::ShowTransactionsMenuScreen();
	}

	static void _ShowManageUsersScreen()
	{
		ManageUsersScreen::ShowManageUsersScreen();
	}

	static void _ShowLoginRegisterScreen()
	{
		LoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchange()
	{
		CurrencyScreen::ShowCurrenciesMenueScreen();
	}

	static void _Logout()
	{
		CurrentUser = BankUser::Find("", ""); 
	}

	static void _PerformMainMenuOptions(enMainMenuOptions MainMenuOptions)
	{
		switch (MainMenuOptions)
		{
		case enMainMenuOptions::ShowClientsList:
			system("cls");
			_ShowClientsListScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::AddNewClient:
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::DeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::UpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::FindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::Transactions:
			system("cls");
			_ShowTransactionsScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::ManageUsers:
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::LoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::CurrencyExchange:
			system("cls");
			_ShowCurrencyExchange();
			_GoBackToMainMenu();
			break;

		case enMainMenuOptions::Logout:
			_Logout();
			break;
		}

	}

public:
	static void ShowMainMenuScreen()
	{
		system("cls");
		system("color B");

		DrawScreenHeader("\t\tMain Menu");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1]: Show Clients List.\n";
		cout << setw(37) << left << "" << "\t[2]: Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3]: Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4]: Update Client.\n";
		cout << setw(37) << left << "" << "\t[5]: Find Client.\n";
		cout << setw(37) << left << "" << "\t[6]: Transactions.\n";
		cout << setw(37) << left << "" << "\t[7]: Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8]: Login Register.\n";
		cout << setw(37) << left << "" << "\t[9]: Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10]: Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformMainMenuOptions(enMainMenuOptions(_ReadMainMenuOptions()));
	}
};

