#include <iostream>
#include "AccountManager.h"
#include "QuestionType1.h"
#include "QuestionType2.h"

int main()
{
	//Source.cpp is currently just for checking if our methods work properly
	AccountManager user;
	user.SignUp("Yan");
	//user.SignUp("Arei");
	//user.PrintUsernames();

	user.Login("Yan");
	std::string score = user.GetScoreForXUsername("Yan");
	std::cout << "Yan's score is: " << score;
	std::cout << std::endl;
	std::string score2 = user.GetScoreForXUsername("Ash");
	std::cout << "Ash's score is: " << score2;
	std::cout << std::endl;
	//user.Login("Rei");
	//user.PrintUsernames();
	//std::cout << std::endl;

	//QuestionType2 question2;
	//question2.SaveQuestion("2+2?", 4);
	//question2.GetQuestion();
}