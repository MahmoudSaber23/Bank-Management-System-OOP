#pragma once

#include <iostream>
#include <string>
#include "String.h"
#include <vector>
#include <fstream>

const string CurrencyFile = "Currencies.txt";



class Currency
{
private:

    enum enObjectMode { EmptyMode = 0, UpdateMode = 1 };
    enObjectMode _Mode;

    string _Country;
    string _currencyCode;
    string _currencyName;
    float _Rate;

    static Currency _ConvertLinetoCurrencyObjectRecord(string Line, string Seperator = "#//#")
    {
        vector<string> vCurrencyData;

        vCurrencyData = String::Split(Line, Seperator);

        return Currency(enObjectMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],stod(vCurrencyData[3]));

    }

    static string _ConverCurrencyObjectToLine(Currency& currency, string Seperator = "#//#")
    {
        string stCurrencyRecord = "";

        stCurrencyRecord += currency.getCountry() + Seperator;
        stCurrencyRecord += currency.getCurrencyCode() + Seperator;
        stCurrencyRecord += currency.getCurrencyName() + Seperator;
        stCurrencyRecord += to_string(currency.getRate());

        return stCurrencyRecord;
    }

    static  vector <Currency> _LoadCurrencysDataFromFileToVector()
    {
        vector <Currency> vCurrencys;

        fstream MyFile;
        MyFile.open(CurrencyFile, ios::in);

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                Currency currency = _ConvertLinetoCurrencyObjectRecord(Line);

                vCurrencys.push_back(currency);
            }

            MyFile.close();

        }

        return vCurrencys;

    }

    static void _SaveCurrencyDataToFile(vector <Currency>& vCurrencys)
    {

        fstream MyFile;
        MyFile.open(CurrencyFile, ios::out);

        string DataLine;

        if (MyFile.is_open())
        {

            for (Currency& C : vCurrencys)
            {
                DataLine = _ConverCurrencyObjectToLine(C);

                MyFile << DataLine << endl;

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <Currency> _vCurrencys;

        _vCurrencys = _LoadCurrencysDataFromFileToVector();

        for (Currency& C : _vCurrencys)
        {
            if (C.getCurrencyCode() == getCurrencyCode())
            {
                C = *this;
                break;
            }

        }

        _SaveCurrencyDataToFile(_vCurrencys);

    }

    static Currency _getEmptyCurrencyObject()
    {
        return Currency(enObjectMode::EmptyMode, "", "", "", 0);
    }


public:

    Currency(enObjectMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
        {
            _Mode = Mode;
            _Country = Country;
            _currencyCode = CurrencyCode;
            _currencyName = CurrencyName;
            _Rate = Rate;
        }

    bool IsEmpty()
        {
            return (_Mode == enObjectMode::EmptyMode);
        }

    string getCountry()
        {
            return _Country;
        }

    string getCurrencyCode()
        {
            return _currencyCode;
        }

    string getCurrencyName()
        {
            return _currencyName;
        }

    void UpdateRate(float NewRate)
        {
            _Rate = NewRate;

            _Update();
        }

    float getRate()
        {
            return _Rate;
        }

    static Currency FindByCode(string CurrencyCode)
        {
            CurrencyCode = String::UpperAllString(CurrencyCode);

            fstream MyFile;
            MyFile.open(CurrencyFile, ios::in);

            if (MyFile.is_open())
            {
                string Line;

                while (getline(MyFile, Line))
                {
                    Currency currency = _ConvertLinetoCurrencyObjectRecord(Line);

                    if (currency.getCurrencyCode() == CurrencyCode)
                    {
                        MyFile.close();
                        return currency;
                    }
                }
                MyFile.close();
            }

            return _getEmptyCurrencyObject();
        }

    static Currency FindByCountry(string Country)
        {
            Country = String::UpperAllString(Country);

            fstream MyFile;
            MyFile.open(CurrencyFile, ios::in);

            if (MyFile.is_open())
            {
                string Line;
                while (getline(MyFile, Line))
                {
                    Currency currency = _ConvertLinetoCurrencyObjectRecord(Line);

                    if (String::UpperAllString(currency.getCountry()) == Country)
                    {
                        MyFile.close();
                        return currency;
                    }
                }

                MyFile.close();

            }

            return _getEmptyCurrencyObject();

        }

    static bool IsCurrencyExist(string CurrencyCode)
        {
            Currency C1 = Currency::FindByCode(CurrencyCode);

            return (!C1.IsEmpty());

        }

    static vector <Currency> GetCurrenciesList()
        {
            return _LoadCurrencysDataFromFileToVector();
        }

    static vector <Currency> GetAllUSDRates()
        {
            return _LoadCurrencysDataFromFileToVector();
        }

    float ConvertToUSD(float Amount)
    {
        return float(Amount / getRate());
    }

    float ConvertToOtherCurrency(float Amount, Currency& CurrencyTo)
    {
        float AmoutInUSD = ConvertToUSD(Amount);

        if (CurrencyTo.getCurrencyCode() == "USD")
        {
            return AmoutInUSD;
        }


        return float(AmoutInUSD * CurrencyTo.getRate());
    }
};

