#pragma once
#include"LOGIN.h"
#include"SIGNUP.h"
#include"USERS.h"
#include"FRIENDS.h"
#include"POSTS.h"
class CONTROL
{
	
protected:
	LOGIN loginObj;
	SIGNUP signupObj;
	USERS usersObj;
	FRIENDS friendObj;
	POSTS postObj;

	template <class T>
	void inputValidation(T min, T max, T& input);

public:
	bool loginActivity(string a_email, string a_password);

	void signupActivity(string a_name, string a_email, string a_password, string a_phone, char a_gender);

	void getSignUpInputs(string& a_name, string& a_email, string& a_password, string& a_phone, char& a_gender);

	bool isEmailUnique(string a_email);

	void modifyAccount(int a_userID);

	void friendRequestsActivity();
};

template<class T>
void CONTROL::inputValidation(T min, T max, T& input)
{
	while (input < min || input > max)
	{
		cout << "ERROR: Enter valid inputs: ";
		cin >> input;
	}
}

