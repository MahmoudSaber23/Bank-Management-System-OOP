#pragma once


#include "ScreenHeader.h"
#include "Currency.h"
#include "InputValidate.h"

class FindCurrencyScreen :protected ScreenHeader
{
private:

    static void _PrintCurrency(Currency& currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << currency.getCountry();
        cout << "\nCode       : " << currency.getCurrencyCode();
        cout << "\nName       : " << currency.getCurrencyName();
        cout << "\nRate(1$) = : " << currency.getRate();

        cout << "\n_____________________________\n";

    }

    static void _ShowResults(Currency& currency)
    {
        if (!currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:

    static void ShowFindCurrencyScreen()
    {
        DrawScreenHeader("\t  Find Currency Screen");

        short Answer = 0;
        cout << "\nFind By: [1]:Code Or [2]:Country ?";
        cin >> Answer;


        if (Answer == 1)
        {
            string CurrencyCode;
            cout << "\nPlease Enter CurrencyCode? ";
            CurrencyCode = InputValidate::ReadString();

            Currency currency = Currency::FindByCode(CurrencyCode);

            _ShowResults(currency);
        }
        else
        {
            string CurrencyName;
            cout << "\nPlease Enter Country Name? ";
            CurrencyName = InputValidate::ReadString();

            Currency currency = Currency::FindByCountry(CurrencyName);

            _ShowResults(currency);
        }
    }
};

