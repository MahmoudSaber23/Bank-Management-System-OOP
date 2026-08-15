#pragma once

#include <iomanip>
#include "ScreenHeader.h"
#include "BankClient.h"
#include "InputValidate.h"
#include "Util.h"


class TotalBalancesScreen : protected ScreenHeader
{
private:

	static void _PrintClientRecordLine(BankClient& Client)
	{
		cout << setw(16) << left << "" << "| " << setw(15) << left << Client.getAccountNumber();
		cout << "| " << setw(25) << left << Client.getFullName();
		cout << "| " << setw(18) << left << Client.AccountBalance;
	}

	static void _TotalBalancesList()
	{
		vector<BankClient>vClients = BankClient::getClientsList();

		cout << "\n\t\t\t\t\t      Balances List(" << vClients.size() << ") Client(s).\n";

		cout << "\n\t\t==============================================================================\n";
		cout << left << setw(16) << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(25) << "Client Name";
		cout << "| " << left << setw(18) << "Balance";
		cout << "\n\t\t==============================================================================\n";

		double TotalBalances = BankClient::getTotalBalances();

		if (vClients.size() == 0)
		{
			cout << "\t\t\t\t\tNo Clients Available In the System!\n";
		}
		else
		{
			for (BankClient& Client : vClients)
			{
				_PrintClientRecordLine(Client);
				cout << endl;
			}
		}

		cout << "\n\t\t==============================================================================\n";

		cout << "\t\t\t\t\tTotal Balances = " << BankClient::getTotalBalances() << endl;
		cout << "\n\t\t\t " << Util::NumberToText(TotalBalances);
	}

public:

	static void ShowTotalBalancesScreen()
	{
		DrawScreenHeader("\tTotal Balances Screen");

		_TotalBalancesList();
	}
};

