#include<iostream>
#include"MENU.h"
using namespace std;

int main()
{
	MENU menuObj;
	int choice = 0;
	menuObj.showMenu(choice);
	string userEmail, userPassword;
	if (choice == 1)
	{
		do
		{
			menuObj.getLoginInputs(userEmail, userPassword);
			if (menuObj.checkLogin(userEmail, userPassword))
			{
				menuObj.wellcomeScreen();
				menuObj.loggedInMenu();
			}
			else
			{
				cout << "Invalid Credentials!\n\n" << endl;
				system("pause");
				system("cls");
				menuObj.showMenu(choice);
			}

		} while (!menuObj.checkLogin(userEmail, userPassword));
	}
	else if (choice == 2)
	{
		string userName, userPhone; char userGender;
		menuObj.getSignUpInputs(userName, userEmail, userPassword, userPhone, userGender);
		menuObj.signupActivity(userName, userEmail, userPassword, userPhone, userGender);
	}
	else
		return 0;

	return 0;
}