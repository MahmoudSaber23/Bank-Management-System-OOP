#pragma once

#include <iomanip>
#include "ScreenHeader.h"
#include "BankClient.h"

class ClientsListScreen :protected ScreenHeader
{
private:

	static void _PrintClientRecordLine(BankClient& Client)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.getAccountNumber();
		cout << "| " << setw(20) << left << Client.getFirstName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}

public:

	static void ShowClientsListScreen()
	{
		if (!CheckAccessRights(BankUser::enPermissions::pListClients))
		{
			return;
		}

		vector<BankClient>vClients = BankClient::getClientsList();

		string Title = "\tClients List Screen";
		string subTitle = "\t  (" + to_string(vClients.size()) + ") Client(s).";

		DrawScreenHeader(Title, subTitle);

		cout << "\n\t=================================================================================================\n";
		cout << left << setw(8) << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << setw(20) << left << "Client Name";
		cout << "| " << setw(12) << left << "Phone";
		cout << "| " << setw(20) << left << "Email";
		cout << "| " << setw(10) << left << "PinCode";
		cout << "| " << setw(12) << left << "Balance";
		cout << "\n\t=================================================================================================\n";

		if (vClients.size() == 0)
		{
			cout << "\nNo Clients Available In The System!\n";
		}
		else
		{
			for (BankClient& Client : vClients)
			{
				_PrintClientRecordLine(Client);
				cout << endl;
			}
		}

		cout << "\n\t=================================================================================================\n";
	}
};

