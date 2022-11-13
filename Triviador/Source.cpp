#include <iostream>
#include "AccountManager.h"
#include "QuestionType1.h"
#include "QuestionType2.h"

int main()
{
	//Source.cpp is currently just for checking if our methods work properly
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
	std::cout << std::endl;

	QuestionType2 question2;
	question2.SaveQuestion("2+2?", 4);
	question2.GetQuestion();
}