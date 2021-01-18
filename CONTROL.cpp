#include "CONTROL.h"


bool CONTROL::loginActivity(string a_email, string a_password)
{

	loginObj.set(a_email, a_password);
	if (loginObj.checkUser())
		return true;
	return false;
}

void CONTROL::signupActivity(string a_name, string a_email, string a_password, string a_phone, char a_gender)
{
	fstream file;
	int a_id = usersObj.getLastID(file, "users.txt");
	file.close();
	fstream dataFile("users.txt", ios::in);
	if (!dataFile.fail())
	{
		loginObj.set(a_email, a_password);
		signupObj.set(a_name, a_phone, a_gender);
		usersObj.insertUser(a_id + 1, a_email, a_password, a_name, a_phone, a_gender);
	}
	dataFile.close();
}

void CONTROL::getSignUpInputs(string& a_name, string& a_email, string& a_password, string& a_phone, char& a_gender)
{
	cin.ignore();
	cout << "Enter username: ";
	getline(cin, a_name);
	for (int i = 0; i < a_name.length(); i++)
		a_name[i] = toupper(a_name[i]);
	cout << "Enter gender: ";
	cin >> a_gender;
	while (toupper(a_gender) != 'F' && toupper(a_gender) != 'M')
	{
		cout << "GENDER CHARACTER INVALID! Plz enter M/F only!";
		cin >> a_gender;
	}
	a_gender = toupper(a_gender);
	cout << "Enter phone: ";
	cin >> a_phone;
	while (a_phone.length() != 11)
	{
		cout << "PHONE NUMBER INVALID! Plz enter 11 characters only!";
		cin >> a_phone;
	}
	cout << "Enter Email: ";
	cin >> a_email;
	while (!isEmailUnique(a_email))
	{
		cout << "EMAIL ALREADY EXISTS! Plz try another one!";
		cin >> a_email;
	}
	cout << "Enter password: ";
	cin >> a_password;
}

bool CONTROL::isEmailUnique(string a_email)
{
	fstream dataFile("users.txt", ios::in);
	if (!dataFile.fail())
	{
		int id; char gen;
		string name, email, line, line1;
		while (!dataFile.eof())
		{
			dataFile >> id;
			getline(dataFile, name, ',');
			getline(dataFile, email, ',');
			getline(dataFile, line1);
			//cout << "Email: " << a_email << " and File email: " << email << endl;
			if (email == a_email)
				return false;
		}
		return true;
	}
}

void CONTROL::modifyAccount(int a_userID)
{
	fstream dataFile, temp;
	dataFile.open("users.txt", ios::in);
	temp.open("temp.txt", ios::out);
	string a_email, a_password, a_phone, a_name;
	char a_gender;
	usersObj.replaceFiles(dataFile, temp, a_userID);
	dataFile.close();
	temp.close();
	remove("users.txt");
	rename("temp.txt", "users.txt");
	getSignUpInputs(a_name, a_email, a_password, a_phone, a_gender);
	usersObj.insertUser(a_userID, a_email, a_password, a_name, a_phone, a_gender);
}

void CONTROL::friendRequestsActivity()
{
	int choice;
	if (friendObj.friendRequests(loginObj.getUserID()))
	{
		cout << "You have pending requests for the following users." << endl;
		{
			for (int i = 0; i < friendObj.getNumOfFriendRequests(); i++)
			{
				usersObj.extractProfile(friendObj.getFriendRequestIndex(i));
				cout << "\nPress\n\t1. To Accept Request\n\t2. To Reject Request\n\t0. To Ignore Request" << endl;
				cout << "Enter your choice: ";
				cin >> choice;
				if (choice != 0)
					usersObj.editRequest(choice, loginObj.getUserID(), friendObj.getFriendRequestIndex(i));
				system("pause");
				system("cls");
			}
		}
	}
}
