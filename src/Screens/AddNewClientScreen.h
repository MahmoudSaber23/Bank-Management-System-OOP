
#pragma once

#include <iomanip>
#include "ScreenHeader.h"
#include "BankClient.h"
#include "InputValidate.h"




class  :protected ScreenHeader
{
private:

	static void _ReadNewClientInfo(BankClient& Client)
	{
		cout << "\nEnter FirstName? ";Client.FirstName = InputValidate::ReadString();

		cout << "\nEnter LastName? "; Client.LastName = InputValidate::ReadString();

		cout << "\nEnter Email? "; Client.Email = InputValidate::ReadString();

		cout << "\nEnter Phone? "; Client.Phone = InputValidate::ReadString();

		cout << "\nEnter PinCode? "; Client.PinCode = InputValidate::ReadString();

		cout << "\nEnter Account Balance? "; Client.AccountBalance = InputValidate::ReadDblNumber();
	}

	static void _PrintClientInfo(BankClient& Client)
	{
		cout << "=======================\n";
		cout << "Client Info:\n";
		cout << "=======================\n";
		cout << "FirstName: " << Client.FirstName;
		cout << "\nLastName: " << Client.LastName;
		cout << "\nFullName: " << Client.getFullName();
		cout << "\nEmail: " << Client.Email;
		cout << "\nPhone: " << Client.Phone;
		cout << "\nAccount Number:"<< Client.getAccountNumber();
		cout << "\nPassword: " << Client.PinCode;
		cout << "\nAccount Balance:"<< Client.AccountBalance;
		cout << "\n=======================\n";
	}

	static void _AddNewClient()
	{
		string AccountNumber = "";
		cout << "\n\nPlease Enter Account Number? ";
		AccountNumber = InputValidate::ReadString();

		while (BankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Already In Used! | Enter Another Account Number? ";
			AccountNumber = InputValidate::ReadString();
		}

		BankClient NewClient = BankClient::getAddNewClientObject(AccountNumber);

		_ReadNewClientInfo(NewClient);

		BankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case BankClient::enSaveResults::svSucceeded:
			cout << "\n\nAccount Added Successfully :-)\n\n";
			_PrintClientInfo(NewClient);
			break;

		case BankClient::enSaveResults::svFaildEmptyObject:
			cout << "\nError Account Was Not Saved Because it's Empty!\n\n";
			break;


		case BankClient::enSaveResults::svFaildAccountNumberExists:
			cout << "\nError Account Was Not Saved Because Account Number In Used!\n\n";
			break;
		}
	}

public:

	static void ShowAddNewClinetScreen()
	{
		if (!CheckAccessRights(BankUser::enPermissions::pAddNewClient))
		{
			return;
		}

		DrawScreenHeader("\t Add New Client Screen");

		_AddNewClient();
	}
};

