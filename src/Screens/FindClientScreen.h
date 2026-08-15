#pragma once



#include "ScreenHeader.h"
#include "BankClient.h"
#include "InputValidate.h"


class FindClientScreen : protected ScreenHeader
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

	static void _FindClient()
	{
		string AccountNumber = "";
		cout << "\n\nPlease Enter Account Number? ";

		AccountNumber = InputValidate::ReadString();

		while (!BankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Not Exists! | Please Enter Another Account Number? ";
			AccountNumber = InputValidate::ReadString();
		}

		BankClient FindClient = BankClient::Find(AccountNumber);

		cout << "\n\nClient Found :-)\n";
		_PrintClientInfo(FindClient);
	}

public:

	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(BankUser::enPermissions::pFindClient))
		{
			return;
		}

		DrawScreenHeader("\t Find Client Screen");

		_FindClient();
	}
};


