#pragma once

#include <iomanip>
#include "ScreenHeader.h"
#include "BankClient.h"


class TransferLogScreen :ScreenHeader
{
private:

	static void _PrintTransferLogRecordLine(BankClient::stTransferLogRecord TransferLogRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateTime;
		cout << "| " << setw(8) << left << TransferLogRecord.SenderAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.RecevierAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.Amount;
		cout << "| " << setw(10) << left << TransferLogRecord.SenderBalanceAfter;
		cout << "| " << setw(10) << left << TransferLogRecord.RecevierBalanceAfter;
		cout << "| " << setw(8) << left << TransferLogRecord.UserName;
	}

public:


	static void ShowTransferLogScreen()
	{

		vector <BankClient::stTransferLogRecord> vTransferLogRecord = BankClient::getTransferLogList();

		string Title = "\tTransfer Log List Screen";
		string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

		DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "S.Acct";
		cout << "| " << left << setw(8) << "R.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "S.Balance";
		cout << "| " << left << setw(10) << "R.Balance";
		cout << "| " << left << setw(8) << "User";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vTransferLogRecord.size() == 0)
			cout << "\t\t\t\tNo Transfers Available In the System!";
		else

			for (BankClient::stTransferLogRecord& Record : vTransferLogRecord)
			{

				_PrintTransferLogRecordLine(Record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}


};

