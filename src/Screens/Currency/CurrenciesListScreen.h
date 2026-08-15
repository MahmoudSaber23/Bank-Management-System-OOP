#pragma once

#include <iomanip>
#include "ScreenHeader.h"
#include "Currency.h"





class CurrenciesListScreen :protected ScreenHeader
{
private:

    static void PrintCurrencyRecordLine(Currency &currency)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << currency.getCountry();
        cout << "| " << setw(8) << left << currency.getCurrencyCode();
        cout << "| " << setw(45) << left << currency.getCurrencyName();
        cout << "| " << setw(10) << left << currency.getRate();

    }
public:

    static void ShowCurrenciesListScreen()
    {


        vector <Currency> vCurrencys = Currency::GetCurrenciesList();

        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencys.size()) + ") Currency.";

        DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        if (vCurrencys.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (Currency& currency : vCurrencys)
            {

                PrintCurrencyRecordLine(currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

    }

};

