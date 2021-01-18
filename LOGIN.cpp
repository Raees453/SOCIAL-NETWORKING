#include "LOGIN.h"

LOGIN::LOGIN(int a_userID, string a_userEmail, string a_userPass)
{
	set(a_userEmail, a_userPass);
}

//setter/mutators

void LOGIN::set(string a_userEmail, string a_userPass)
{
	if (a_userEmail.length() > 0 && a_userPass.length() > 0)
	{
		userEmail = a_userEmail;
		userPass = a_userPass;
		userID = setID(userEmail);
	}
}

int LOGIN::setID(string a_userEmail)
{
	fstream dataFile("users.txt", ios::in);
	int a_id; char a_gender, a_comm;
	string a_pass, a_email, a_phone, a_name;
	while (!dataFile.eof())
	{
		dataFile >> a_id >> a_comm;
		getline(dataFile, a_name, ',');
		getline(dataFile, a_email, ',');
		getline(dataFile, a_pass, ',');
		getline(dataFile, a_phone, ',');
		dataFile >> a_gender;
		if (a_email == a_userEmail)
			return a_id;
	}
}

//accessor functions.

const string LOGIN::getUserEmail() const
{
	return userEmail;
}

const string LOGIN::getUserPass() const
{
	return userPass;
}

const int LOGIN::getUserID() const
{
	return userID;
}

bool LOGIN::checkUser()
{
	int a_id; char a_gender;
	string a_pass, a_email, a_phone, a_name;
	fstream dataFile("users.txt", ios::in);
	if (dataFile.fail())
		cout << "Cannot open file!" << endl;
	else
	{
		while (!dataFile.eof())
		{
			dataFile >> a_id;
			getline(dataFile, a_name, ',');
			getline(dataFile, a_email, ',');
			getline(dataFile, a_pass, ',');
			getline(dataFile, a_phone, ',');
			dataFile >> a_gender;
			if (a_email == userEmail && a_pass == userPass)
			{
				dataFile.close();
				return true;
			}
		}
	}
	dataFile.close();
	return false;
}

void LOGIN::wellcome()
{
	cout << "\n\n\t\t\t";
	for (int i = 0; i < 62; i++)
		cout << "*";
	cout << "\n\t\t\t*   Dear " << userEmail << " you have been successfully loggedIn   *\n";
	cout << "\t\t\t";
	for (int i = 0; i < 62; i++)
		cout << "*";
}
