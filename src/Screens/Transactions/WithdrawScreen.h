#pragma once

#include "ScreenHeader.h"
#include "BankClient.h"
#include "InputValidate.h"

class WithdrawScreen :protected ScreenHeader
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

	static void _Withdraw()
	{
		string AccountNumber = "";
		cout << "\n\nPlease Enter Account Number? ";

		AccountNumber = InputValidate::ReadString();

		while (!BankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With[" << AccountNumber << "] Does Not Exist!" << "\n\nPlease Enter Another Account Number ? ";
			AccountNumber = InputValidate::ReadString();
		}

		BankClient WithdrawClient = BankClient::Find(AccountNumber);

		_PrintClientInfo(WithdrawClient);

		double Amount = 0;
		cout << "\nPlease enter Withdraw amount? ";
		Amount = InputValidate::ReadDblNumber();

		while (Amount > WithdrawClient.AccountBalance)
		{
			cout << "\n\nYou Exceed Your Balance ,Enter Amount That Is Equal Or LessThan To Your Balance?";
			Amount = InputValidate::ReadDblNumber();
		}

		char Answer = 'n';
		cout << "\nAre you sure do you want to Withdraw this client? (Y/N)?";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (WithdrawClient.Withdraw(Amount)) 
			{
				cout << "\n\nAmount Withdrawed Successfully :-)\n\n";
				cout << "New Balance Is = " << WithdrawClient.AccountBalance << endl;
			}
			else
			{
				cout << "\nCannot Withdraw, Insuffecient Balance!\n";
				cout << "\nAmount to Withdraw Is: " << Amount;
				cout << "\nYour Balance Is: " << WithdrawClient.AccountBalance;
			
			}

		}
		
	}

public:

	static void ShowWithdrawScreen()
	{
		DrawScreenHeader("\tWithdraw Screen");

		_Withdraw();
	}
};


