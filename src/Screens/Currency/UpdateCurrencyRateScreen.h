#pragma once

#include "ScreenHeader.h"
#include "Currency.h"
#include "InputValidate.h"


class UpdateCurrencyRateScreen :protected ScreenHeader
{
private:

    static double _ReadRate()
    {
        cout << "\nEnter New Rate: ";
        double NewRate = 0;

        NewRate = InputValidate::ReadDblNumber();
        return NewRate;
    }

    static void _PrintCurrency(Currency currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << currency.getCountry();
        cout << "\nCode       : " << currency.getCurrencyCode();
        cout << "\nName       : " << currency.getCurrencyName();
        cout << "\nRate(1$) = : " << currency.getRate();

        cout << "\n_____________________________\n";

    }

public:

    static void ShowUpdateCurrencyRateScreen()
    {
        DrawScreenHeader("\tUpdate Currency Screen");

        string CurrencyCode = "";

        cout << "Please Enter Currency Code? ";
        CurrencyCode = InputValidate::ReadString();

        while (!Currency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency Is Not Found, Choose Another One? ";
            CurrencyCode = InputValidate::ReadString();
        }


        Currency currency = Currency::FindByCode(CurrencyCode);

        _PrintCurrency(currency);

        cout << "\nAre You Sure You Want To Update The Rate Of This Currency y/n? ";

        char Answer = 'n';

        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\nUpdate Currency Rate:";
            cout << "\n======================\n";

            currency.UpdateRate(_ReadRate());

            cout << "\nCurrency Rate Updated Successfully :-)\n";

            _PrintCurrency(currency);
        }
        else
        {
            cout << "\nCurrency Rate Was Not Updated!\n";
        }
    }
};

