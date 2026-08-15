#pragma once

#include <string>
#include <vector>

using namespace std;

class String
{
private:
    string _value;

public:

    String()
    {
        _value = "";
    }

    String(string value)
    {
        this->_value = value;
    }

    void setValue(string value)
    {
        this->_value = value;
    }

    string getValue()
    {
        return this->_value;
    }

    __declspec(property(get = getValue, put = setValue)) string Value;//put==set

    static size_t  Length(string String)
    {
        return String.length();
    };

    size_t  Length()
    {
        return Length(_value);
    }

    static size_t CountWords(string String)
    {

        string delim = " ";
        short Counter = 0;
        size_t pos = 0;
        string sWord;

        while ((pos = String.find(delim)) != std::string::npos)
        {
            sWord = String.substr(0, pos);
            if (sWord != "")
            {
                Counter++;
            }

            String.erase(0, pos + delim.length());
        }

        if (String != "")
        {
            Counter++;
        }

        return Counter;

    }

    size_t CountWords()
    {
        return CountWords(_value);
    }

    static string  UpperFirstLetterOfEachWord(string String)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < String.length(); i++)
        {

            if (String[i] != ' ' && isFirstLetter)
            {
                String[i] = toupper(String[i]);

            }

            isFirstLetter = (String[i] == ' ' ? true : false);

        }

        return String;
    }

    void UpperFirstLetterOfEachWord()
    {
        _value = UpperFirstLetterOfEachWord(_value);
    }

    static string  LowerFirstLetterOfEachWord(string String)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < String.length(); i++)
        {

            if (String[i] != ' ' && isFirstLetter)
            {
                String[i] = tolower(String[i]);

            }

            isFirstLetter = (String[i] == ' ' ? true : false);

        }

        return String;
    }

    void  LowerFirstLetterOfEachWord()
    {
        _value = LowerFirstLetterOfEachWord(_value);
    }

    static string  UpperAllString(string String)
    {
        for (short i = 0; i < String.length(); i++)
        {
            String[i] = toupper(String[i]);
        }
        return String;
    }

    void  UpperAllString()
    {
        _value = UpperAllString(_value);
    }

    static string  LowerAllString(string String)
    {
        for (short i = 0; i < String.length(); i++)
        {
            String[i] = tolower(String[i]);
        }
        return String;
    }

    void  LowerAllString()
    {
        _value = LowerAllString(_value);
    }

    static char  InvertLetterCase(char char1)
    {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }

    static string  InvertAllLettersCase(string String)
    {
        for (short i = 0; i < String.length(); i++)
        {
            String[i] = InvertLetterCase(String[i]);
        }
        return String;
    }

    void  InvertAllLettersCase()
    {
        _value = InvertAllLettersCase(_value);
    }

    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

    static size_t CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {

        if (WhatToCount == enWhatToCount::All)
        {
            return S1.length();
        }

        short Counter = 0;

        for (size_t i = 0; i < S1.length(); i++)
        {

            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
                Counter++;


            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
                Counter++;


        }

        return Counter;

    }

    static size_t   CountCapitalLetters(string String)
    {

        short Counter = 0;

        for (size_t i = 0; i < String.length(); i++)
        {

            if (isupper(String[i]))
                Counter++;

        }

        return Counter;
    }

    size_t  CountCapitalLetters()
    {
        return CountCapitalLetters(_value);
    }

    static size_t   CountSmallLetters(string String)
    {

        short Counter = 0;

        for (size_t i = 0; i < String.length(); i++)
        {

            if (islower(String[i]))
                Counter++;

        }

        return Counter;
    }

    size_t  CountSmallLetters()
    {
        return CountSmallLetters(_value);
    }

    static size_t   CountSpecificLetter(string String, char Letter, bool MatchCase = true)
    {

        short Counter = 0;

        for (size_t i = 0; i < String.length(); i++)
        {

            if (MatchCase)
            {
                if (String[i] == Letter)
                    Counter++;
            }
            else
            {
                if (tolower(String[i]) == tolower(Letter))
                    Counter++;
            }

        }

        return Counter;
    }

    size_t  CountSpecificLetter(char Letter, bool MatchCase = true)
    {
        return CountSpecificLetter(_value, Letter, MatchCase);
    }

    static bool IsVowel(char Ch1)
    {
        Ch1 = tolower(Ch1);

        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

    }

    static size_t   CountVowels(string String)
    {

        short Counter = 0;

        for (size_t i = 0; i < String.length(); i++)
        {

            if (IsVowel(String[i]))
                Counter++;

        }

        return Counter;
    }

    size_t   CountVowels()
    {
        return CountVowels(_value);
    }

    static vector<string> Split(string String, string Delim)
    {

        vector<string> vString;

        size_t pos = 0;
        string sWord;


        while ((pos = String.find(Delim)) != std::string::npos)
        {
            sWord = String.substr(0, pos);
            if (sWord != "")
            {
                vString.push_back(sWord);
            }

            String.erase(0, pos + Delim.length());
        }

        if (String != "")
        {
            vString.push_back(String);
        }

        return vString;

    }

    vector<string> Split(string Delim)
    {
        return Split(_value, Delim);
    }

    static string TrimLeft(string String)
    {


        for (size_t i = 0; i < String.length(); i++)
        {
            if (String[i] != ' ')
            {
                return String.substr(i, String.length() - i);
            }
        }
        return "";
    }

    void TrimLeft()
    {
        _value = TrimLeft(_value);
    }

    static string TrimRight(string String)
    {


        for (size_t i = String.length() - 1; i >= 0; i--)
        {
            if (String[i] != ' ')
            {
                return String.substr(0, i + 1);
            }
        }
        return "";
    }

    void TrimRight()
    {
        _value = TrimRight(_value);
    }

    static string Trim(string String)
    {
        return (TrimLeft(TrimRight(String)));

    }

    void Trim()
    {
        _value = Trim(_value);
    }

    static string JoinString(vector<string> vString, string Delim)
    {

        string S1 = "";

        for (string& s : vString)
        {
            S1 = S1 + s + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());


    }

    static string JoinString(string arrString[], short Length, string Delim)
    {

        string S1 = "";

        for (size_t i = 0; i < Length; i++)
        {
            S1 = S1 + arrString[i] + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());

    }

    static string ReverseWordsInString(string String)
    {

        vector<string> vString;
        string S2 = "";

        vString = Split(String, " ");

        vector<string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {

            --iter;

            S2 += *iter + " ";

        }

        S2 = S2.substr(0, S2.length() - 1);

        return S2;
    }

    void ReverseWordsInString()
    {
        _value = ReverseWordsInString(_value);
    }

    static string ReplaceWord(string String, string StringToReplace, string sRepalceTo, bool MatchCase = true)
    {

        vector<string> vString = Split(String, " ");

        for (string& s : vString)
        {

            if (MatchCase)
            {
                if (s == StringToReplace)
                {
                    s = sRepalceTo;
                }

            }
            else
            {
                if (LowerAllString(s) == LowerAllString(StringToReplace))
                {
                    s = sRepalceTo;
                }

            }

        }

        return JoinString(vString, " ");
    }

    string ReplaceWord(string StringToReplace, string sRepalceTo)
    {
        return ReplaceWord(_value, StringToReplace, sRepalceTo);
    }

    static string RemovePunctuations(string String)
    {

        string S2 = "";

        for (short i = 0; i < String.length(); i++)
        {
            if (!ispunct(String[i]))
            {
                S2 += String[i];
            }
        }

        return S2;

    }

    void RemovePunctuations()
    {
        _value = RemovePunctuations(_value);
    }
};

