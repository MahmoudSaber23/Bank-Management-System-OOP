#pragma once

#include <iomanip>
#include "ScreenHeader.h"
#include "BankUser.h"



class LoginRegisterScreen :protected ScreenHeader
{
private:

	static void _PrintLoginRegisterRecordLine(BankUser::stLoginRegisterRecord& User)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << User.DateTime;
		cout << "| " << setw(20) << left << User.UserName;
		cout << "| " << setw(20) << left << User.Password;
		cout << "| " << setw(15) << left << User.Permissions;
	}

public:

	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(BankUser::enPermissions::pLoginRegister))
		{
			return;
		}


		vector<BankUser::stLoginRegisterRecord>vUsers =BankUser::LoadRegisterLoginDataFromFileToVector();

		string Title = "\tLogin Register Screen\n";

		string SubTitle = "\t    (" + to_string(vUsers.size()) + ") Record(s).";

		DrawScreenHeader(Title, SubTitle);

		cout << "\n\t=================================================================================================\n";
		cout << left << setw(8) << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << "\n\t=================================================================================================\n";

		if (vUsers.size() == 0) {
			cout << "\t\t\t\tNo Logins Available In the System!";
		}
		else
		{
			for (BankUser::stLoginRegisterRecord &LogIn : vUsers)
			{
				_PrintLoginRegisterRecordLine(LogIn);
				cout << endl;
			}
		}

		cout << "\n\t=================================================================================================\n";
	}
};

