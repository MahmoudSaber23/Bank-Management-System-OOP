#pragma once

#include "ScreenHeader.h"
#include "BankUser.h"
#include "MainScreen.h"
#include "Global.h"



class LoginScreen :protected ScreenHeader
{
private:

	static bool _Login()
	{
		bool LoginFaild = false;

		string UserName = "", Password = "";

		short LoginTrials = 3;

		do
		{
			if (LoginFaild)
			{
				LoginTrials--;
				cout << "\n\nInvalid UserName | Password!\n";
				cout << "You Have " << LoginTrials << " Trial(s) Left To Login!\n\n";
			}

			if (LoginTrials == 0)
			{
				cout << "You Are Locked After 3 Faild Trails\n\n";
				return false;
			}

			cout << "\nEnter UserName? ";
			cin >> UserName;
			cout << "\nEnter Password? ";
			cin >> Password;

			
			CurrentUser = BankUser::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		CurrentUser.RegisterLogin();
		MainScreen::ShowMainMenuScreen();

		return true;
	}


public:

	static bool ShowLoginScreen()
	{
		system("cls");
		system("Color B");
		DrawScreenHeader("\t    Login Screen");

		return _Login();
	}

};

