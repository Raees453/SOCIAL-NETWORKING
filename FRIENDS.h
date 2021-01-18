#pragma once
#include"HANDLEFILING.h"
class FRIENDS:private HANDLEFILING
{
private:
	int numOfFriends;
	int numOfFriendRequests;
	int* arr;
	int* friendRequest;

public:
	FRIENDS();

	bool setFriends(int a_id);

	void sendRequest(int a_senderID, int a_recieverID);

	void displayFriendIDs();

	int getFriendIndex(int a_index);

	int getFriendRequestIndex(int a_index);

	bool friendRequests(int a_userID);

	const int getNumOfFriends() const;
	const int getNumOfFriendRequests() const;

	~FRIENDS();
};

