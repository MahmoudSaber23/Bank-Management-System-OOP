#pragma once


#include <iomanip>
#include "ScreenHeader.h"
#include "BankUser.h"


class UsersListScreen :protected ScreenHeader
{
private:

	static void _PrintUserRecordLine(BankUser& User)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << User.getUserName();
		cout << "| " << setw(20) << left << User.getFullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions;
	}										


public:

	static void ShowUsersListScreen()
	{
		vector<BankUser>vUsers = BankUser::getUserList();

		string Title = "\tUsers List Screen";

		string SubTitle = "\t   (" + to_string(vUsers.size()) + ") Users(s).";

		DrawScreenHeader(Title, SubTitle);

		cout << "\n\t====================================================================================================\n";
		cout << left << setw(8) << "" << "| " << left << setw(15) << "UserName";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << "\n\t====================================================================================================\n";



		if (vUsers.size() == 0)
		{
			cout << "\t\t\t\t\tNo Users Available In the System!\n";
		}
		else
		{
			for (BankUser& User : vUsers)
			{
				_PrintUserRecordLine(User);
				cout << endl;
			}
		}
		cout << "\n\t====================================================================================================\n";
	}
};

