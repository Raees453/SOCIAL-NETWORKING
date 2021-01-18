#pragma once
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
class HANDLEFILING
{

public:

	void insertUser(int a_userID, string a_email, string a_password, string a_name, string a_phone, char a_gender);

	int getLastID(fstream& dataFile, string name);

	void extractUsers(int a_userID);

	void extractProfile(int a_userID);

	void replaceFiles(fstream& inputFile, fstream& outputFile, int a_userID);

	void showPosts(int a_id = 0);

	void editRequest(int a_choice, int a_userID, int a_friendID);

	string getName(int a_userId);

	void insertPost(int a_postID, int a_postedBy, string a_post);
};