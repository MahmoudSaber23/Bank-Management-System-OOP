#pragma once

#include <iostream>
#include "InterfaceCommunication.h"

using namespace std;

class Person :public InterfaceCommunication
{
private:

	string _firstName;
	string _lastName;
	string _Email;
	string _Phone;

public:

	Person(string FirstName, string LastName, string Email, string Phone)
	{
		_firstName = FirstName;
		_lastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	void setFirstName(string FirstName)
	{
		_firstName = FirstName;
	}

	string getFirstName()
	{
		return _firstName;
	}

	_declspec(property(get = getFirstName, put = setFirstName))string FirstName;

	void setLastName(string LastName)
	{
		_lastName = LastName;
	}

	string getLastName()
	{
		return _lastName;
	}

	_declspec(property(get = getLastName, put = setLastName))string LastName;

	void setEmail(string Email)
	{
		_Email = Email;
	}

	string getEmail ()
	{
		return _Email;
	}

	_declspec(property(get = getEmail, put = setEmail))string Email;

	void setPhone(string Phone)
	{
		_Phone = Phone;
	}

	string getPhone()
	{
		return _Phone;
	}

	_declspec(property(get = getPhone, put = setPhone))string Phone;

	string getFullName()
	{
		return _firstName + " " + _lastName;
	}


	void SendEmail(string Title, string Body)
	{

	}

	void SendFax(string Title, string Body)
	{

	}

	void SendSMS(string Title, string Body)
	{

	}
};

