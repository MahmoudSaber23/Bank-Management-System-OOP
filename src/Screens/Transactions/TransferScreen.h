#pragma once



#include "ScreenHeader.h"
#include "BankClient.h"
#include "InputValidate.h"


class TransferScreen :protected ScreenHeader
{
private:

	static void _PrintClientCard(BankClient& Client)
	{
		cout << "\n========================";
		cout << "\nClient Card:\n";
		cout << "========================";
		cout << "\nFull Name: " << Client.getFullName();
		cout << "\nAccount Number: " << Client.getAccountNumber();
		cout << "\nBalance: " << Client.AccountBalance;
		cout << "\n========================\n";
	}

	static string _ReadAccountNumberFrom()
	{
		string AccountNumber = "";

		cout << "\nPlease Enter Account Number To Transfer From: ";
		AccountNumber = InputValidate::ReadString();

		while (!BankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Not Found! ,Enter Another Account Number? ";
			AccountNumber = InputValidate::ReadString();
		}

		return AccountNumber;
	}

	static string _ReadAccountNumberTo()
	{
		string AccountNumber = "";

		cout << "\nPlease Enter Account Number To Transfer To: ";
		AccountNumber = InputValidate::ReadString();

		while (!BankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Not Found! ,Enter Another Account Number? ";
			AccountNumber = InputValidate::ReadString();
		}

		return AccountNumber;
	}

	static double _ReadAmount(BankClient& Sender)
	{
		double Amount = 0;

		cout << "\nEnter Transfer Amount? ";
		Amount = InputValidate::ReadDblNumber();

		while (Amount > Sender.AccountBalance)
		{
			cout << "\nAmount Exceeds The Avilable Balance :Enter Another Amount? ";
			Amount = InputValidate::ReadDblNumber();
		}
		return Amount;
	}

public:

	static void ShowTransferScreen()
	{
		DrawScreenHeader("\t Transfer Screen");

		BankClient Sender = BankClient::Find(_ReadAccountNumberFrom());

		_PrintClientCard(Sender);
		

		BankClient Receiver = BankClient::Find(_ReadAccountNumberTo());

		_PrintClientCard(Receiver);

		double Amount = _ReadAmount(Sender);

		char Answer = 'n';
		cout << "\nAre You Sure You Want To Do This Operation? y/n? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Sender.Transfer(Amount, Receiver,CurrentUser.UserName))
			{
				cout << "\nTransfer Done Successfully:-)\n\n";
			}
		}
		else
		{
			cout << "\nTransfer Faild!\n\n";
		}


		_PrintClientCard(Sender);
		cout << "\n";
		_PrintClientCard(Receiver);
	}
};

