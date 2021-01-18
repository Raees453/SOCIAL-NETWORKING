#pragma once
#include"HANDLEFILING.h"
class USERS:public HANDLEFILING
{
private:
	int numOfUsers;

public:
	USERS();
	
	//setter/ mutator
	void setNumOfUsers();

	void displayAllUsers(int a_userID);
	void displayProfile(int a_userID);
	
	const int getNumOfUsers() const;
};

