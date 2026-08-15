#pragma once

#include <iomanip>
#include "ScreenHeader.h"
#include "BankClient.h"
#include "InputValidate.h"
#include "DepositScreen.h"
#include "WithdrawScreen.h"
#include "TotalBalancesScreen.h"
#include "TransferScreen.h"
#include "TransferLogScreen.h"

class TransactionsScreen : protected ScreenHeader
{
	enum enTransactionsMenuOptions { Deposit = 1, Withdraw, TotalBalances, Transfer, TransferLog, MainMenu };

	static short _ReadTransactionsMenuOptions()
	{
		cout << setw(37) << left << "" << "Enter what do you want to do?[1 To 6]? ";
		short Choice = InputValidate::ReadShortNumberBetween(1, 6, "Enter Number Between 1 To 6 ?");
		return Choice;
	}

	static void _GoBackToTransactionsMenu()
	{
		cout << "\n\nPress any key to go back to transactions menu...";
		system("pause>0");
		ShowTransactionsMenuScreen();
	}

	static void _ShowDepositScreen()
	{
		DepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		WithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		TotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen()
	{
		TransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		TransferLogScreen::ShowTransferLogScreen();
	}

	static void _PerformTransactionsMenuOptions(enTransactionsMenuOptions TransactionsMenuOptions)
	{
		if (TransactionsMenuOptions == enTransactionsMenuOptions::MainMenu)
			return;

		system("cls");
		switch (TransactionsMenuOptions)
		{
		case enTransactionsMenuOptions::Deposit:
			_ShowDepositScreen();
			break;

		case enTransactionsMenuOptions::Withdraw:
			_ShowWithdrawScreen();
			break;

		case enTransactionsMenuOptions::TotalBalances:
			_ShowTotalBalancesScreen();
			break;

		case enTransactionsMenuOptions::Transfer:
			_ShowTransferScreen();
			break;

		case enTransactionsMenuOptions::TransferLog:
			_ShowTransferLogScreen();
			break;

		case enTransactionsMenuOptions::MainMenu:
			break;
		}

		_GoBackToTransactionsMenu();
	}

public:

	static void ShowTransactionsMenuScreen()
	{
		if (!CheckAccessRights(BankUser::enPermissions::pTransactions))
		{
			return;
		}

		system("cls");
		system("color B");

		DrawScreenHeader("\tTransactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tTransactions Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1]: Deposit.\n";
		cout << setw(37) << left << "" << "\t[2]: Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3]: TotalBalances.\n";
		cout << setw(37) << left << "" << "\t[4]: Transfer.\n";
		cout << setw(37) << left << "" << "\t[5]: Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6]: Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionsMenuOptions(enTransactionsMenuOptions(_ReadTransactionsMenuOptions()));
	}
};

