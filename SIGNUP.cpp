#include "SIGNUP.h"

SIGNUP::SIGNUP()
{
	set(" ", " ", ' ');
}

SIGNUP::SIGNUP(string a_userName, char a_gender, string a_phone)
{
	set(a_userName, a_phone, a_gender);
}

//setters/mutators

void SIGNUP::set(string a_name, string a_phone, char a_gender)
{
	if (a_name.length() > 0 && a_phone.length() > 10)
	{
		userName = a_name;
		userGender = a_gender;
		userPhone = a_phone;
	}
}

//accessor functions.

const string SIGNUP::getUserName() const
{
	return userName;
}

const char SIGNUP::getGender() const
{
	return userGender;
}

const string SIGNUP::getPhone() const
{
	return userPhone;
}
