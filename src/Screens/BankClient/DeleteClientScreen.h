
#pragma once

#include "ScreenHeader.h"
#include "BankClient.h"
#include "InputValidate.h"





class DeleteClientScreen :protected ScreenHeader
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

	static void _DeleteClient()
	{
		string AccountNumber = "";
		cout << "\n\nPlease Enter Account Number? ";
		AccountNumber = InputValidate::ReadString();

		while (!BankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Not Exists! | Please Enter Another Account Number? ";
			AccountNumber = InputValidate::ReadString();
		}

		BankClient DeleteClient = BankClient::Find(AccountNumber);

		_PrintClientInfo(DeleteClient);

		char Answer = 'n';
		cout << "\nAre you sure do you want to delete this client? (Y/N)?";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (DeleteClient.Delete())
			{
				cout << "\n\nAccount Deleted Successfully :-)\n\n";
				_PrintClientInfo(DeleteClient);
			}
		}
		else
		{
			cout << "\n\nError Client Was Not Deleted\n\n";
		}
	}

public:

	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(BankUser::enPermissions::pDeleteClient))
		{
			return;
		}

		DrawScreenHeader("\tDelete Client Screen");

		_DeleteClient();
	}
};

