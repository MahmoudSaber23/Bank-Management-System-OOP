#pragma once

#include "ScreenHeader.h"
#include "Currency.h"
#include "InputValidate.h"


class CurrencyCalculatorScreen :protected ScreenHeader
{
private:

	static double _ReadAmount()
	{
		double Amount = 0;
		cout << "\nEnter Amount To Exchange? ";

		Amount = InputValidate::ReadDblNumber();
		return Amount;
	}

	static Currency _getCurrency(string Message)
	{
		string CurrencyCode;
		cout << Message << endl;

		CurrencyCode = InputValidate::ReadString();

		while (!Currency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Is Not Found, Choose Another One? ";
			CurrencyCode = InputValidate::ReadString();
		}

		Currency Currency = Currency::FindByCode(CurrencyCode);

		return Currency;
	}

	static void _PrintCurrencyCard(Currency currency, string Title = "Currency Card:")
	{
		cout << "\n" << Title << "\n";
		cout << "_____________________________\n";
		cout << "\nCountry       : " << currency.getCountry();
		cout << "\nCode          : " << currency.getCurrencyCode();
		cout << "\nName          : " << currency.getCurrencyName();
		cout << "\nRate(1$) =    : " << currency.getRate();
		cout << "\n_____________________________\n\n";

	}

	static void _PrintCalculationsResults(float Amount, Currency Currency1, Currency Currency2)
	{
		_PrintCurrencyCard(Currency1, "Convert From:");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.getCurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.getCurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";
		_PrintCurrencyCard(Currency2, "To:");

		float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.getCurrencyCode()
			<< " = " << AmountInCurrency2 << " " << Currency2.getCurrencyCode();

	}

public:


	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';

		do
		{
			system("cls");

			DrawScreenHeader("\tCurrency Calculator Screen");

			Currency CurrencyFrom = _getCurrency("\nPlease Enter Currency1 Code? ");

			Currency CurrencyTo = _getCurrency("\nPlease Enter Currency2 Code? ");

			float Amount = _ReadAmount();


			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);



			cout << "\n\nDo You Want To Do More Calculations? y/n? ";
			cin >> Continue;

		} while (Continue == 'y' || Continue == 'Y');
	}

};

