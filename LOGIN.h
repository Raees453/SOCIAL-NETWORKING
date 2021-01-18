#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class LOGIN
{
protected:
	string userEmail;
	string userPass;
	int userID;

public:
	LOGIN(int a_userID = 0, string a_userEmail = "", string a_userPass = "");

	//setter/mutators
	void set(string a_userEmail, string a_userPass);

	int setID(string a_userEmail);

	//accessor functions.
	const string getUserEmail() const;
	const string getUserPass() const;
	const int getUserID() const;

	bool checkUser();
	
	void wellcome();
};

