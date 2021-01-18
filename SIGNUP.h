#pragma once
#include<iostream>
using namespace std;
class SIGNUP
{
private:
	char userGender;
	string userName;
	string userPhone;
	
public:
	SIGNUP();

	SIGNUP(string a_userName, char a_gender, string a_phone);

	//setters/mutators
	void set(string a_name, string a_phone, char a_gender);

	//accessor functions.
	const string getUserName() const;
	const char getGender() const;
	const string getPhone() const;
};

