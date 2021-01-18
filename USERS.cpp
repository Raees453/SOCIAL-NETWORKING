#include "USERS.h"

USERS::USERS()
{
	setNumOfUsers();
}

//setter/ mutator

void USERS::setNumOfUsers()
{
	fstream dataFile("users.txt", ios::in);
	int a_id, count = 0;
	string line;
	while (!dataFile.eof())
	{
		dataFile >> a_id;
		getline(dataFile, line);
		count++;
	}
	numOfUsers = count;
}

void USERS::displayAllUsers(int a_userID)
{
	cout << "\n\n\t\t\t";
	for (int i = 0; i < 50; i++)
		cout << "*";
	cout << "\n\t\t\t\tNum\tUSERNAME\tEMAIL\n\t\t\t";
	for (int i = 0; i < 50; i++)
		cout << "*";
	cout << endl;
	extractUsers(a_userID);
	cout << "\n\t\t\t";
	for (int i = 0; i < 50; i++)
		cout << "*";
}

void USERS::displayProfile(int a_userID)
{
	cout << "\n\n\t\t";
	for (int i = 0; i < 60; i++)
		cout << "*";
	cout << "\n\t\t\t\tPROFILE DETAILS\n\t\t";
	for (int i = 0; i < 60; i++)
		cout << "*";
	cout << endl;
	extractProfile(a_userID);
	cout << "\n\t\t";
	for (int i = 0; i < 60; i++)
		cout << "*";
}

const int USERS::getNumOfUsers() const
{
	return numOfUsers;
}
