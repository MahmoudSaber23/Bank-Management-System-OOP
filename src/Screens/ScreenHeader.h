#pragma once

#include <iostream>
#include "Date.h"
#include "Global.h"

using namespace std;

class ScreenHeader
{
protected:
	static void DrawScreenHeader(string Title, string subTitle = "")
	{
		cout << "\t\t\t\t\t=====================================";
		cout << "\n\n\t\t\t\t\t" << Title;

		if (subTitle != "")
		{
			cout << "\n\t\t\t\t\t" << subTitle;
		}
		cout << "\n\n\t\t\t\t\t=====================================\n";

		cout << "\n\t\t\t\t\tUser: " << CurrentUser.UserName;
		cout << "\n\t\t\t\t\tDate: " << Date::DateToString(Date())<<"\n\n";
	}

	static bool CheckAccessRights(BankUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\t\t\t\t\t============================================\n";
			cout << "\n\t\t\t\t\t     Access Denied! Contact Your Admin!\n\n";
			cout << "\t\t\t\t\t============================================\n";

			return false;
		}
		else
		{
			return true;
		}
	}
};

