#include <iostream>
#include "AccountManager.h"

int main()
{
	AccountManager user;
	user.SaveUser("Yan", 0);
	user.SaveUser("Ash", 4);
	user.SaveUser("Kit", 2);
	user.PrintUsernames();

	user.SignUp("Yan");
	user.SignUp("Arei");
	user.PrintUsernames();

	user.Login("Ash");
	user.Login("Rei");
	user.PrintUsernames();

	
}