#include "HANDLEFILING.h"

void HANDLEFILING::insertUser(int a_userID, string a_email, string a_password, string a_name, string a_phone, char a_gender)
{
	fstream dataFile;
	dataFile.open("users.txt", ios::app);
	dataFile << "\n" << a_userID << a_name + ',' << a_email + ',' << a_password + ',' << a_phone + ',' << a_gender;
	dataFile.close();
}

int HANDLEFILING::getLastID(fstream& dataFile, string name)
{
	dataFile.open(name.c_str(), ios::in);
	if (!dataFile.fail())
	{
		string line; int count = 0;
		while (!dataFile.eof())
		{
			getline(dataFile, line);
			count++;
		}
		return count;
	}
}

void HANDLEFILING::extractUsers(int a_userID)
{
	fstream dataFile("users.txt", ios::in);
	int a_id;
	string a_email, line, a_name;
	while (!dataFile.eof())
	{
		dataFile >> a_id;
		getline(dataFile, a_name, ',');
		getline(dataFile, a_email, ',');
		getline(dataFile, line);
		if (a_id != a_userID)
			cout << "\t\t\t\t" << a_id << "\t" << a_name << "\t" << a_email << endl;
	}
	dataFile.close();
}

void HANDLEFILING::extractProfile(int a_userID)
{
	fstream dataFile("users.txt", ios::in);
	int a_id; char a_gender;
	string a_pass, a_email, a_phone, a_name;
	while (!dataFile.eof())
	{
		dataFile >> a_id;
		getline(dataFile, a_name, ',');
		getline(dataFile, a_email, ',');
		getline(dataFile, a_pass, ',');
		getline(dataFile, a_phone, ',');
		dataFile >> a_gender;
		if (a_id == a_userID)
		{
			cout << "\t\t\tUSERNAME: " << "\t" << a_name << endl;
			cout << "\t\t\tEMAIL: " << "\t\t" << a_email << endl;
			cout << "\t\t\tCONTACT #: " << "\t" << a_phone << endl;
			cout << "\n\t\t";
			for (int i = 0; i < 60; i++)
				cout << "*";
			cout << "\n\t\t\t\tPOSTS FROM " << a_name << " :";
			cout << "\n\t\t";
			for (int i = 0; i < 60; i++)
				cout << "*";
			cout << endl;
			showPosts(a_userID);
			break;
		}
	}
}

void HANDLEFILING::replaceFiles(fstream& inputFile, fstream& outputFile, int a_userID)
{
	int a_id; char a_gender;
	string line;
	while (!inputFile.eof())
	{
		inputFile >> a_id;
		getline(inputFile, line);
		if (a_id != a_userID)
			outputFile << "\n" << a_id << line;
	}
}

void HANDLEFILING::showPosts(int a_id)
{
	int count = 0;
	fstream file("posts.txt", ios::in);
	if (file.fail())
		cout << "Error! opeing the file!" << endl;
	else
	{
		int id, aid;
		char com;
		string post, name;
		if (a_id == 0)
		{
			cout << "\n\n\t\t";
			for (int i = 0; i < 60; i++)
				cout << "*";
			cout << endl;
			cout << "\t\t*  USERNAME\t\t" << "POST" << endl;
			cout << "\t\t";
			for (int i = 0; i < 60; i++)
				cout << "*";
			cout << endl;
			while (file.good())
			{
				file >> id >> com >> aid >> com;
				getline(file, post);
				cout << "\t\t| " << getName(aid) << "\t\t" << post << endl;
			}
			cout << "\t\t";
			for (int i = 0; i < 60; i++)
				cout << "*";
		}
		else
		{
			cout << "\n\n\t\t";
			for (int i = 0; i < 60; i++)
				cout << "*";
			cout << endl;
			cout << "\t\t*  POST NUMBER\t\t" << "POST" << endl;
			cout << "\t\t";
			for (int i = 0; i < 60; i++)
				cout << "*";
			cout << endl;

			while (file.good())
			{
				file >> id >> com >> aid >> com;
				getline(file, post);
				if (aid == a_id)
				{
					cout << "\t\t\t" << count + 1 << "\t\t" << post << endl;

					count++;
				}
			}
			if (count == 0)
				cout << "\t\t\t\tHavn't added any post yet!" << endl;
		}
	}
}

void HANDLEFILING::editRequest(int a_choice, int a_userID, int a_friendID)
{
	fstream dataFile("friendRequests.txt", ios::in);
	fstream tempFile("temp.txt", ios::app);
	fstream friendFile("friends.txt", ios::app);

	if (a_choice == 1)
	{
		friendFile << "\n" << a_userID << "," << a_friendID;
	}
	int id, aid; char comm;
	while (!dataFile.eof())
	{
		dataFile >> id >> comm >> aid;
		if (id != a_userID && aid != a_userID)
			tempFile << "\n" << id << comm << aid;
	}
	friendFile.close();
	dataFile.close();
	tempFile.close();
	remove("friendRequests.txt");
	rename("temp.txt", "friendRequests.txt");
}

string HANDLEFILING::getName(int a_userId)
{
	fstream dataFile("users.txt", ios::in);
	if (dataFile.fail())
		cout << "Error!opeing the file!" << endl;
	else
	{
		int a_id;
		string line, a_name;
		while (!dataFile.eof())
		{
			dataFile >> a_id;
			getline(dataFile, a_name, ',');
			getline(dataFile, line);
			if (a_id == a_userId)
			{
				return a_name;
			}
		}
	}
	dataFile.close();
}

void HANDLEFILING::insertPost(int a_postID, int a_postedBy, string a_post)
{
	fstream inputPostFile;
	inputPostFile.open("posts.txt", ios::app);
	if (inputPostFile.fail())
		cout << "Error! openeing the file!" << endl;
	else
	{
		if (a_postID > 0 && a_post.length() > 0)
			inputPostFile << "\n" << a_postID << ',' << a_postedBy << ',' << a_post;
	}
}
