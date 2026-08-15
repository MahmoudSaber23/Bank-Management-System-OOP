#pragma once


#include "ScreenHeader.h"
#include "BankClient.h"
#include "InputValidate.h"


class DepositScreen :protected ScreenHeader
{
private:

	static void _PrintClientInfo(BankClient& Client)
	{
		cout << "\n\n=======================\n";
		cout << "Client Info:\n";
		cout << "=======================\n";
		cout << "FirstName: " << Client.FirstName;
		cout << "\nLastName: " << Client.LastName;
		cout << "\nFullName: " << Client.getFullName();
		cout << "\nEmail: " << Client.Email;
		cout << "\nPhone: " << Client.Phone;
		cout << "\nAccount Number:" << Client.getAccountNumber();
		cout << "\nPassword: " << Client.PinCode;
		cout << "\nAccount Balance:" << Client.AccountBalance;
		cout << "\n=======================\n";
	}

	static void _Deposit()
	{
		string AccountNumber = "";
		cout << "\n\nPlease Enter Account Number? ";

		AccountNumber = InputValidate::ReadString();

		while (!BankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With[" << AccountNumber << "] Does Not Exist!" << "\n\nPlease Enter Another Account Number ? ";
			AccountNumber = InputValidate::ReadString();
		}

		BankClient DepositClient = BankClient::Find(AccountNumber);

		_PrintClientInfo(DepositClient);

		double Amount = 0;
		cout << "\nPlease enter Deposit amount? ";
		Amount = InputValidate::ReadDblNumber();

		char Answer = 'n';
		cout << "\nAre you sure do you want to Deposit this client? (Y/N)?";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			DepositClient.Deposit(Amount);
			cout << "\n\nAmount Deposited Successfully :-)\n\n";
			cout << "New Balance Is = " << DepositClient.AccountBalance << endl;
		}
		else
		{
			cout << "\nOperation Was Cancelled!\n";
		}


	}

public:

	static void ShowDepositScreen()
	{
		DrawScreenHeader("\tDeposit Screen");

		_Deposit();
	}
};

