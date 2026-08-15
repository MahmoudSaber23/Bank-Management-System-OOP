
#pragma once


#include "ScreenHeader.h"
#include "BankClient.h"
#include "InputValidate.h"



class UpdateClientScreen :protected ScreenHeader
{
	static void _UpdateClientInfo(BankClient &Client)
	{
		cout << "\nEnter FirstName? "; Client.FirstName = InputValidate::ReadString();

		cout << "\nEnter LastName? "; Client.LastName = InputValidate::ReadString();

		cout << "\nEnter Email? "; Client.Email = InputValidate::ReadString();

		cout << "\nEnter Phone? "; Client.Phone = InputValidate::ReadString();

		cout << "\nEnter PinCode? "; Client.PinCode = InputValidate::ReadString();

		cout << "\nEnter Account Balance? "; Client.AccountBalance = InputValidate::ReadDblNumber();
	}

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

	static void _UpdateClient()
	{
		string AccountNumber = "";
		cout << "\n\nPlease Enter Account Number? ";

		AccountNumber = InputValidate::ReadString();

		while (!BankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Not Exists! | Please Enter Another Account Number? ";
			AccountNumber = InputValidate::ReadString();
		}

		BankClient UpdateClient = BankClient::Find(AccountNumber);

		_PrintClientInfo(UpdateClient);

		char Answer = 'n';
		cout << "\nAre you sure do you want to Update this client? (Y/N)?";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			cout << "\n\nUpdate Client Info:";
			cout << "\n=====================\n";

			_UpdateClientInfo(UpdateClient);

			BankClient::enSaveResults SaveResult;

			SaveResult = UpdateClient.Save();

			switch (SaveResult)
			{
			case BankClient::enSaveResults::svSucceeded:
				cout << "\n\nAccount Updated Successfully :-).\n";
				_PrintClientInfo(UpdateClient);
				break;

			case BankClient::enSaveResults::svFaildEmptyObject:
				cout << "Error Account Was Not Saved Because it's Empty!\n";
				break;
			}	
		}
		else
		{
			cout << "\n\nError Client Was Not Updated!\n\n";
		}
		
	}

public:

	static void ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(BankUser::enPermissions::pUpdateClient))
		{
			return;
		}


		DrawScreenHeader("\tUpdate Client Screen");

		_UpdateClient();
	}
};

