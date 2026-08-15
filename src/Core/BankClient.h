
#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "Person.h"
#include "String.h"

using namespace std;

const string ClientsFileName = "Clients.txt";
const string TransferFile = "Transfer.txt";



class BankClient :public Person
{
private:

	enum enObjectMode { EmptyMode, UpdateMode, AddNewMode };
	enObjectMode _Mode;

	string _accountNumber;
	string _pinCode;
	double _accountBalance;
	bool _markForDelete = false;

	static BankClient _ConvertClientObjectLineToRecord(string Line, string Seperator = "#//#")
	{
		vector<string>vObjectData;
		vObjectData = String::Split(Line, Seperator);

		return BankClient(enObjectMode::UpdateMode, vObjectData[0], vObjectData[1], vObjectData[2], vObjectData[3], vObjectData[4], vObjectData[5], stod(vObjectData[6]));
	}

	static string _ConvertClientObjectToLine(BankClient& Client, string Seperator = "#//#")
	{
		string ObjectDataLine = "";

		ObjectDataLine += Client.FirstName + Seperator;
		ObjectDataLine += Client.LastName + Seperator;
		ObjectDataLine += Client.Email + Seperator;
		ObjectDataLine += Client.Phone + Seperator;
		ObjectDataLine += Client.getAccountNumber() + Seperator;
		ObjectDataLine += Client._pinCode + Seperator;
		ObjectDataLine += to_string(Client._accountBalance);

		return ObjectDataLine;
	}

	static vector<BankClient>_LoadClientsDataFromFileToVector()
	{
		vector<BankClient>vClients;

		fstream MyFile;
		MyFile.open(ClientsFileName, ios::in);//Read Mode;

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				BankClient Client = _ConvertClientObjectLineToRecord(Line);
				vClients.push_back(Client);
			}

			MyFile.close();// Important For No Memory Leak;
		}
		return vClients;
	}

	static void _SaveClientsDataToFile(vector<BankClient>& vClients)
	{
		fstream MyFile;
		MyFile.open(ClientsFileName, ios::out);

		if (MyFile.is_open())
		{
			

			for (BankClient& Client : vClients)
			{
				if (Client.getMarkForDelete() == false)
				{
					string DataLine = _ConvertClientObjectToLine(Client);

					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	static void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;
		MyFile.open(ClientsFileName, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;

			MyFile.close();
		}
	}

	void _Update()
	{
		vector<BankClient>vClients;

		vClients = _LoadClientsDataFromFileToVector();

		for (BankClient &Client : vClients)
		{
			if (Client.getAccountNumber() == getAccountNumber())
			{
				Client = *this; //Current Object Will Be Updated
				break;
			}	
		}
		_SaveClientsDataToFile(vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	static BankClient _getEmptyClientObject()
	{
		return BankClient(enObjectMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	struct stTransferLogRecord;

	string _PrepareTransferLogRecord(double Amount, BankClient &Receiver, string UserName, string Seperator = "#//#")
	{
		string TransferLogRecord = "";

		TransferLogRecord += Date::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += getAccountNumber() + Seperator;
		TransferLogRecord += Receiver.getAccountNumber() + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(Receiver.AccountBalance) + Seperator;
		TransferLogRecord += UserName;

		return TransferLogRecord;
	}

	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTransferLogRecord TrnsferLogRecord;

		vector <string> vTrnsferLogRecordLine = String::Split(Line, Seperator);

		TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
		TrnsferLogRecord.SenderAccountNumber = vTrnsferLogRecordLine[1];
		TrnsferLogRecord.RecevierAccountNumber = vTrnsferLogRecordLine[2];
		TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
		TrnsferLogRecord.SenderBalanceAfter = stod(vTrnsferLogRecordLine[4]);
		TrnsferLogRecord.RecevierBalanceAfter = stod(vTrnsferLogRecordLine[5]);
		TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

		return TrnsferLogRecord;

	}

	void _RegisterTransferLog(double Amount, BankClient &Receiver, string UserName)
	{
		string TransferDataLine = _PrepareTransferLogRecord(Amount, Receiver, UserName);

		fstream MyFile;
		MyFile.open(TransferFile, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << TransferDataLine << endl;

			MyFile.close();
		}
	}

public:

	struct stTransferLogRecord
	{
		string DateTime;
		string SenderAccountNumber;
		string RecevierAccountNumber;
		double Amount;
		double SenderBalanceAfter;
		double RecevierBalanceAfter;
		string UserName;
	};

	BankClient(enObjectMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double AccountBalance):
	Person(FirstName,LastName,Email,Phone)
	{
		_Mode = Mode;
		_accountNumber = AccountNumber;
		_pinCode = PinCode;
		_accountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enObjectMode::EmptyMode);
	}

	string getAccountNumber()
	{
		return _accountNumber;
	}

	bool getMarkForDelete()
	{
		return _markForDelete;
	}

	void setPinCode(string PinCode)
	{
		_pinCode = PinCode;
	}

	string getPinCode()
	{
		return _pinCode;
	}

	_declspec(property(get = getPinCode, put = setPinCode))string PinCode;

	void setAccountBalance(double AccountBalance)
	{
		_accountBalance = AccountBalance;
	}

	double getAccountBalance()
	{
		return _accountBalance;
	}

	_declspec(property(get = getAccountBalance, put = setAccountBalance))double AccountBalance;

	static BankClient Find_Client(string AccountNumber, string PinCode, bool MatchWithPinCode)
	{
		fstream MyFile;
		MyFile.open(ClientsFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{

				if (Line != "")
				{
					BankClient Client = _ConvertClientObjectLineToRecord(Line);

					if (MatchWithPinCode)
					{
						if (Client.getAccountNumber() == AccountNumber && Client.getPinCode() == PinCode)
						{
							MyFile.close();
							return Client;
						}
					}
					else
					{
						if (Client.getAccountNumber() == AccountNumber)
						{
							MyFile.close();
							return Client;

						}
					}
					
				}
			}
			MyFile.close();
		}
		return _getEmptyClientObject();
	}

	static BankClient Find(string AccountNumber)
	{
		return Find_Client(AccountNumber, "", false);
	}

	static BankClient Find(string AccountNumber,string PinCode)
	{
		return Find_Client(AccountNumber, PinCode, true);
	}

	static bool IsClientExist(string AccountNumber)
	{
		BankClient Client = BankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	static BankClient getAddNewClientObject(string AccountNumber)
	{
		return BankClient(enObjectMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded, svFaildAccountNumberExists };

	enSaveResults Save()
	{
		switch (_Mode)
		{
			case enObjectMode::EmptyMode: 
			{
				if (IsEmpty())
				{
					return enSaveResults::svFaildEmptyObject;
				}
			}
			case enObjectMode::UpdateMode:
			{
				_Update();

				return enSaveResults::svSucceeded;

				break;
			}
			case enObjectMode::AddNewMode:
			{
				// this will Add New Line To FILE;

				if (BankClient::IsClientExist(_accountNumber))
				{
					return enSaveResults::svFaildAccountNumberExists;
				}
				else
				{
					_AddNew();

					_Mode = enObjectMode::UpdateMode;
					return enSaveResults::svSucceeded;
				}
			}



		}

	}

	bool Delete()
	{
		vector<BankClient>vClients;

		vClients = _LoadClientsDataFromFileToVector();

		for (BankClient& Client : vClients)
		{
			if (Client.getAccountNumber()==_accountNumber)
			{
				Client._markForDelete = true;
				break;
			}
		}
		_SaveClientsDataToFile(vClients);

		*this = _getEmptyClientObject();

		return true;
	}

	static vector<BankClient> getClientsList()
	{
		return _LoadClientsDataFromFileToVector();
	}
	
	static double getTotalBalances()
	{
		vector<BankClient>vClients;

		vClients = BankClient::getClientsList();

		double TotalBalances = 0;

		for (BankClient& Client : vClients)
		{
			TotalBalances += Client.AccountBalance;
		}
		return TotalBalances;
	}

	void Deposit(double Amount)
	{
		_accountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _accountBalance)
		{
			return false;
		}
		else
		{
			_accountBalance -= Amount;
			Save();
		}
	}

	bool Transfer(double Amount, BankClient& Receiver,string UserName)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}

		Withdraw(Amount);

		Receiver.Deposit(Amount);

		_RegisterTransferLog(Amount, Receiver, UserName);

		return true;
	}

	static vector<stTransferLogRecord>getTransferLogList()
	{
		vector<stTransferLogRecord>vTransferLogRecord;

		fstream MyFile;
		MyFile.open(TransferFile, ios::in);

		if (MyFile.is_open())
		{
			string Line;

			stTransferLogRecord TransferRecord;

			while (getline(MyFile, Line))
			{
				TransferRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferRecord);
			}
			MyFile.close();
		}

		return vTransferLogRecord;

	}
};



