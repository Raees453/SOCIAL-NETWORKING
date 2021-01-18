#pragma once
#include"CONTROL.h"
class MENU :public CONTROL
{

public:
	
	void clrScr();
	void showMenu(int& a_choice);
	/// <summary>
	/// this function will check the details entered
	/// returns true if user is found else returns false
	/// </summary>
	/// <param name="a_email"></param>
	/// <param name="a_password"></param>
	/// <returns></returns>
	bool checkLogin(string a_email, string a_password);
	void wellcomeScreen();
	/// <summary>
	/// will get inputs for useremail and passwords
	/// </summary>
	/// <param name="a_email"></param>
	/// <param name="a_password"></param>
	void getLoginInputs(string& a_email, string& a_password);
	void loggedInMenu();
	void myProfile();
	void myPosts();
	void addPost();
	void allPosts();
	void allUsers();
	void modify();
	void myFriends();
	void sendRequests();
	void pendingRequests();
	void logout();
	void rules();
	/// <summary>
	/// the main logic of the project, will pass through different functions to get results.
	/// </summary>
	void controlFunctions();
};
