#include "FRIENDS.h"

FRIENDS::FRIENDS()
{
	numOfFriends = numOfFriendRequests = 0;
	arr = nullptr;
	friendRequest = nullptr;
}

bool FRIENDS::setFriends(int a_id)
{
	this->friendRequests(a_id);
	bool flag = false;
	fstream dataFile("friends.txt", ios::in);
	if (dataFile.fail())
		cout << "Error openeing the file " << endl;
	else
	{
		int id, aid, count = 0;
		char com;
		while (dataFile.good())
		{
			dataFile >> id >> com >> aid;
			if (id == a_id)
			{
				count++;
				flag = true;
			}
			else if (aid == a_id)
			{
				count++;
				flag = true;
			}
		}
		dataFile.close();
		numOfFriends = count;
		arr = new int[numOfFriends];
		count = 0;
		dataFile.open("friends.txt", ios::in);
		while (dataFile.good())
		{
			dataFile >> id >> com >> aid;
			if (id == a_id)
			{
				arr[count] = aid;
				count++;
			}
			else if (aid == a_id)
			{
				arr[count] = id;
				count++;
			}
		}
	}
	return flag;
}

void FRIENDS::sendRequest(int a_senderID, int a_recieverID)
{
	fstream friendFile;
	friendFile.open("friendRequests.txt", ios::app);
	friendFile << "\n" << a_senderID << ',' << a_recieverID;
}

void FRIENDS::displayFriendIDs()
{
	for (int i = 0; i < numOfFriends; i++)
		cout << "You are a friend of: " << arr[i] << endl;
}

int FRIENDS::getFriendIndex(int a_index)
{
	if (a_index >= 0 && a_index <= numOfFriends)
		return arr[a_index];
}

int FRIENDS::getFriendRequestIndex(int a_index)
{
	if (a_index >= 0 && a_index <= numOfFriendRequests)
		return friendRequest[a_index];

}

bool FRIENDS::friendRequests(int a_userID)
{
	int id, aid, count = 0; char comm;
	bool flag = false;
	fstream friendFile("friendRequests.txt", ios::in);
	while (friendFile.good())
	{
		friendFile >> id >> comm >> aid;
		if (id == a_userID)
		{
			flag = true;
			count++;
		}
		else if (aid == a_userID)
		{
			flag = true;
			count++;
		}
	}
	friendFile.close();
	if (!flag)
		return false;
	friendRequest = new int[count];
	count = 0;
	friendFile.open("friendRequests.txt", ios::in);
	while (friendFile.good())
	{
		friendFile >> id >> comm >> aid;
		if (id == a_userID)
		{
			friendRequest[count] = aid;
			count++;
		}
		else if (aid == a_userID)
		{
			friendRequest[count] = id;
			count++;
		}
	}

	numOfFriendRequests = count;
	friendRequest[count] = -1;
	friendFile.close();
	return true;
}

const int FRIENDS::getNumOfFriends() const
{
	return numOfFriends;
}

const int FRIENDS::getNumOfFriendRequests() const
{
	return numOfFriendRequests;
}

FRIENDS::~FRIENDS()
{
	if (numOfFriends > 0)
		delete[] arr;
	if (numOfFriendRequests > 0)
		delete[] friendRequest;
}
