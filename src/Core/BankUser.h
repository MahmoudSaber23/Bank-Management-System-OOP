#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "Person.h"
#include "String.h" 
#include "Date.h"
#include "Util.h"
#include "Global.h"

using namespace std;

const string UsersFileName = "Users.txt";
const string LoginRegisterFileName = "LoginRegister.txt";


class BankUser :public Person
{
private:

	enum enObjectMode { EmptyMode = 0, UpdateMode, AddNewMode };
	enObjectMode _Mode;

	string _userName;
	string _Password;
	int _Permissions = 0;
	bool _markForDelete = false;

	static BankUser _ConvertUserObjectLineToRecord(string Line, string Seperator = "#//#")
	{
		vector<string>vObjectData;
		vObjectData = String::Split(Line, Seperator);

		return BankUser(enObjectMode::UpdateMode, vObjectData[0], vObjectData[1], vObjectData[2], vObjectData[3], vObjectData[4],Util::DecryptText(vObjectData[5]), stoi(vObjectData[6]));
	}

	static string _ConvertUserObjectToLine(BankUser& User, string Seperator = "#//#")
	{
		string UserObjDataLine = "";

		UserObjDataLine += User.FirstName + Seperator;
		UserObjDataLine += User.LastName + Seperator;
		UserObjDataLine += User.Email + Seperator;
		UserObjDataLine += User.Phone + Seperator;
		UserObjDataLine += User.UserName + Seperator;
		UserObjDataLine +=Util::EncryptText(User.Password) + Seperator;
		UserObjDataLine += to_string(User.Permissions);

		return UserObjDataLine;
	}

	static vector<BankUser>_LoadUserDataFromFileToVector()
	{
		vector<BankUser>vUsers;

		fstream MyFile;

		MyFile.open(UsersFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				BankUser User = _ConvertUserObjectLineToRecord(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;
	}

	static void _SaveUserDataToFile(vector<BankUser>& vUsers)
	{
		fstream MyFile;

		MyFile.open(UsersFileName, ios::out);

		string DataLine;

		if (MyFile.is_open()) {

			for (BankUser& User : vUsers)
			{
				if (User._markForDelete == false)
				{
					DataLine = _ConvertUserObjectToLine(User);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}

	static void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	string _PerpareRegisterLoginLine(string Seperator = "#//#")
	{
		string LoginDataLine = "";

		LoginDataLine += Date::GetSystemDateTimeString() + Seperator;
		LoginDataLine += UserName + Seperator;
		LoginDataLine += Util::EncryptText(Password) + Seperator;
		LoginDataLine += to_string(Permissions);

		return LoginDataLine;
	}

	struct stLoginRegisterRecord;

	static stLoginRegisterRecord _ConvertRegisterLoginToRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegisterRecord LoginRegister;

		vector <string>vLoginRegisterRecord = String::Split(Line, Seperator);

		LoginRegister.DateTime = vLoginRegisterRecord[0];
		LoginRegister.UserName = vLoginRegisterRecord[1];
		LoginRegister.Password =Util::DecryptText(vLoginRegisterRecord[2]);
		LoginRegister.Permissions = stoi(vLoginRegisterRecord[3]);

		return LoginRegister;	
	}

	void _Update()
	{
		vector<BankUser>vUsers;

		vUsers = _LoadUserDataFromFileToVector();

		for (BankUser& User : vUsers)
		{
			if (User.getUserName() == UserName)
			{
				User = *this; //Current Object Will Be Updated
				break;
			}
		}
		_SaveUserDataToFile(vUsers);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	static BankUser _getEmptyUserObject()
	{
		return BankUser(enObjectMode::EmptyMode, "", "", "", "", "", "", 0);
	}


public:

	enum enPermissions { pAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64, pLoginRegister = 128 };

	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};

	BankUser(enObjectMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions) :
		Person(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_userName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return (_Mode == enObjectMode::EmptyMode);
	}

	bool getMarkForDelete()
	{
		return _markForDelete;
	}

	void setUserName(string UserName)
	{
		_userName = UserName;
	}

	string getUserName()
	{
		return _userName;
	}

	_declspec(property(get = getUserName, put = setUserName))string UserName;

	void setPassword(string Password)
	{
		_Password = Password;
	}

	string getPassword()
	{
		return _Password;
	}

	_declspec(property(get = getPassword, put = setPassword))string Password;

	void setPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int getPermissions()
	{
		return _Permissions;
	}

	_declspec(property(get = getPermissions, put = setPermissions))int Permissions;

	static BankUser Find_User(string UserName, string Password, bool MatchWithPassword)
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{

				if (Line != "")
				{
					BankUser User = _ConvertUserObjectLineToRecord(Line);

					if (MatchWithPassword)
					{
						if (User.getUserName() == UserName && User.getPassword() == Password)
						{
							MyFile.close();
							return User;
						}
					}
					else
					{
						if (User.getUserName() == UserName)
						{
							MyFile.close();
							return User;

						}
					}

				}
			}
			MyFile.close();
		}
		return _getEmptyUserObject();
	}

	static BankUser Find(string UserName)
	{
		return Find_User(UserName, "", false);
	}

	static BankUser Find(string UserName, string Password)
	{
		return Find_User(UserName, Password, true);
	}

	static bool IsUserExist(string UserName)
	{
		BankUser User = BankUser::Find(UserName);
		return (!User.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded, svFaildUserExists };

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
			if (BankUser::IsUserExist(_userName))
			{
				return enSaveResults::svFaildUserExists;
			}
			else
			{
				_AddNew();

				_Mode = enObjectMode::AddNewMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}
	}

	bool Delete()
	{
		vector<BankUser>vUsers = _LoadUserDataFromFileToVector();

		for (BankUser& User : vUsers)
		{
			if (User.getUserName() == _userName)
			{
				User._markForDelete = true;
				break;
			}
		}

		_SaveUserDataToFile(vUsers);

		*this = _getEmptyUserObject();

		return true;
	}

	static BankUser getAddNewUserObject(string UserName)
	{
		return BankUser(enObjectMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector<BankUser>getUserList()
	{
		return _LoadUserDataFromFileToVector();
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::pAll)
			return true;
		

		if ((Permission & this->Permissions) == Permission)
			return true;
		else
			return false;
		
	}

	void RegisterLogin()
	{
		string DataLine = _PerpareRegisterLoginLine();

		fstream MyFile;

		MyFile.open(LoginRegisterFileName, ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << DataLine << endl;

			MyFile.close();
		}
	}

	static vector<stLoginRegisterRecord>LoadRegisterLoginDataFromFileToVector()
	{
		vector <stLoginRegisterRecord> vLoginRegisters;

		fstream MyFile;
		MyFile.open(LoginRegisterFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line;


			while (getline(MyFile, Line))
			{
				stLoginRegisterRecord LogIn = _ConvertRegisterLoginToRecord(Line);

				vLoginRegisters.push_back(LogIn);
			}

			MyFile.close();
		}

		return vLoginRegisters;
	}
};

