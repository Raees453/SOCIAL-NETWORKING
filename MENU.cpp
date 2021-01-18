#include "MENU.h"

void MENU::clrScr()		//for code reuseability
{
	cout << "\n\n";
	system("pause");
	system("cls");
}

void MENU::showMenu(int& a_choice)		//will display login/signup menu to help user find choice
{
	cout << "\n\n";
	cout << "\t01. LOG IN" << endl;
	cout << "\t02. SIGN UP" << endl;
	cout << "\t03. TERMINATE PROGRAM" << endl;
	cout << "\nSelect Your option (1-3) ";
	cin >> a_choice;
	inputValidation(0, 3, a_choice);
}

/// <summary>
/// this function will check the details entered
/// returns true if user is found else returns false
/// </summary>
/// <param name="a_email"></param>
/// <param name="a_password"></param>
/// <returns></returns>

bool MENU::checkLogin(string a_email, string a_password)
{
	if (loginActivity(a_email, a_password))
		return true;
	else
		return false;
}

void MENU::wellcomeScreen()		//if user gets loggedin then this function will be shown through login
{
	clrScr();
	loginObj.wellcome();
	rules();
	clrScr();
}

/// <summary>
/// will get inputs for useremail and passwords
/// </summary>
/// <param name="a_email"></param>
/// <param name="a_password"></param>

void MENU::getLoginInputs(string& a_email, string& a_password)
{
	cout << "Enter email: ";
	cin >> a_email;
	cout << "Enter Password: ";
	cin >> a_password;
}

void MENU::loggedInMenu()			//the main menu for the user and will then give the responce to controlfunctions
{
	cout << "\n\n\tCheck out what we've for you!" << endl;
	cout << "\t  01. My Profile" << endl;
	cout << "\t  02. All Posts" << endl;
	cout << "\t  03. My Posts" << endl;
	cout << "\t  04. Add Post" << endl;
	cout << "\t  05. Users" << endl;
	cout << "\t  06. Modify My Account" << endl;
	cout << "\t  07. My Friends" << endl;
	cout << "\t  08. Send Friend Request" << endl;
	cout << "\t  09. My Friend Requests" << endl;
	cout << "\t  10. LOG OUT" << endl;
	controlFunctions();
}

void MENU::myProfile()		//will display the profile of the user if user gets loggedin
{
	if (loginObj.checkUser())
		usersObj.displayProfile(loginObj.getUserID());
	else
		cout << "\nERROR: Record does not exists!" << endl;
}

void MENU::myPosts()
{
	postObj.displayPosts(loginObj.getUserID());
}

void MENU::addPost()
{
	string post;
	cin.ignore();
	cout << "Enter your post: ";
	getline(cin, post);
	postObj.set(loginObj.getUserID(), post);

}

void MENU::allPosts()
{
	postObj.displayPosts();
}

void MENU::allUsers()
{
	usersObj.displayAllUsers(loginObj.getUserID());
}

void MENU::modify()
{
	modifyAccount(loginObj.getUserID());
	cout << "You will have to log out to update the changes!\n\n";
}

void MENU::myFriends()
{
	friendObj.setFriends(loginObj.getUserID());
	if (friendObj.getNumOfFriends() > 0)
	{
		for (int i = 0; i < friendObj.getNumOfFriends(); i++)
		{
			cout << "\n\n";
			usersObj.displayProfile(friendObj.getFriendIndex(i));
			clrScr();
		}
	}
	else
	{
		cout << "\n\n\t\t\tYou have no friends yet!" << endl;
		clrScr();
	}
}

void MENU::sendRequests()
{
	int id;
	cout << "Here are the users." << endl;
	usersObj.displayAllUsers(loginObj.getUserID());
	cin.ignore();
	cout << "\n\nEnter userID to send request: ";
	cin >> id;
	friendObj.sendRequest(loginObj.getUserID(), id);
	cout << "Your request has been sent successfully.\n\n";
}

void MENU::pendingRequests()
{
	friendRequestsActivity();
}

void MENU::logout()
{
	clrScr();
	cout << "\n\nYou have been successfully logged out." << endl;
	clrScr();
}

void MENU::rules()
{
	cout << "\n\n";
	cout << "\t\t1. No 18+ talsk allowed!" << endl;
	cout << "\t\t1. No 18+ talsk allowed!" << endl;
	cout << "\t\t1. No 18+ talsk allowed!" << endl;
	cout << "\t\t1. No 18+ talsk allowed!" << endl;
	cout << "\t\t1. No 18+ talsk allowed!" << endl;
	cout << "\n\n";
}

/// <summary>
/// the main logic of the project, will pass through different functions to get results.
/// </summary>

void MENU::controlFunctions()
{
	int choice;
	cout << "\nSelect Your option (1-10) ";
	cin >> choice;
	inputValidation(0, 11, choice);
	cout << "\n\n";
	system("pause");
	switch (choice)
	{
	case 1:
		system("cls");
		myProfile();
		clrScr();
		loggedInMenu();
		break;

	case 2:
		system("cls");
		allPosts();
		clrScr();
		loggedInMenu();
		break;
	case 3:
		system("cls");
		cout << "\n\n";
		myPosts();
		clrScr();
		loggedInMenu();
		break;
	case 4:
		cout << "\n\n";
		addPost();
		clrScr();
		loggedInMenu();
		break;
	case 5:
		system("cls");
		cout << "\n\n";
		allUsers();
		clrScr();
		loggedInMenu();
		break;
	case 6:
		system("cls");
		cout << "\n\n";
		modify();
		logout();
		clrScr();
		showMenu(choice);
		break;
	case 7:
		system("cls");
		myFriends();
		system("cls");
		loggedInMenu();
		break;
	case 8:
		system("cls");
		cout << "\n\n";
		sendRequests();
		clrScr();
		loggedInMenu();
		break;
	case 9:
		system("cls");
		cout << "\n\n";
		pendingRequests();
		clrScr();
		loggedInMenu();
		break;
	case 10:
		logout();
		showMenu(choice);
		break;
	default:
		cout << "Invalid Input!" << endl;
		loggedInMenu();
		break;
	}
}
