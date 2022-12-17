#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"
#include "QuestionManager.h"
#include "PowerUps.h"
int main()
{
	////Source.cpp is currently just for checking if our methods work properly
	//AccountManager user;
	//user.SignUp("Yan");
	////user.SignUp("Arei");
	////user.PrintUsernames();

	//user.Login("Yan");
	//std::string score = user.GetScoreForXUsername("Yan");
	//std::cout << "Yan's score is: " << score;
	//std::cout << std::endl;
	//std::string score2 = user.GetScoreForXUsername("Ash");
	//std::cout << "Ash's score is: " << score2;
	//std::cout << std::endl;

	//user.SetScoreForXUsername("Yan", 250);
	//score = user.GetScoreForXUsername("Yan");
	//std::cout << "Yan's score is now: " << score;
	//std::cout << std::endl;
	//user.SetScoreForXUsername("Ash", 250);
	//score2 = user.GetScoreForXUsername("Ash");
	//std::cout << "Ash's score is now: " << score2;
	//std::cout << std::endl;
	////user.Login("Rei");
	////user.PrintUsernames();
	////std::cout << std::endl;


	//QuestionType1 question1;

	//std::ifstream question;
	//std::string questionOne;
	//std::vector<std::string> answerOne;
	//std::string option;
	//questions.open("questionType1.txt");
	//while (!question.fail())
	//{
	//	getline(question, questionOne);
	//	for (int i = 0; i < 4; i++)
	//		answerOne.push_back(option);
	//	question1.saveQuestion(questionOne, answerOne);
	//}
	//questions.close();
	//question1.GetQuestion1();

	/*QuestionType2 question2;
	std::ifstream questions;
	std::string questionTwo;
	int answerTwo;
	questions.open("questionType2.txt");
	while (!questions.fail())
	{
		getline(questions, questionTwo);
		questions >> answerTwo;
		std::string questionTwo2;

		getline(questions, questionTwo2);
		question2.SaveQuestion(questionTwo, answerTwo);
	}
	questions.close();
	question2.GetQuestion();*/

	//Board board;
	//std::cout << "What is the number of players you'd like this game to have?\n";
	//int numberOfPlayers;
	//std::cin >> numberOfPlayers;
	//board.SetNumberOfPlayers(numberOfPlayers);
	//board.SetBoard();
	//board.MakeBoard();
	//std::cout << board;
	//board.Test();

	Game game;
	game.MenuForTheGame();

	/*QuestionManager questionManager;
	std::string question1;
	std::string option1;
	std::string option2;
	std::string option3;
	std::string option4;
	std::string correctAnswer;
	questionManager.ReadQuestion(question1, option1, option2, option3, option4, correctAnswer);*/

	//PowerUps powerUps;
	//std::vector<int> powers;
	//powerUps.AllPowers(powers);
	//powerUps.UsedPowers(powers);

	/*AccountManager am;
	am.SignUp("Ash");
	am.SignUp("Yan");
	am.Login("Cathy");
	std::cout << "Ash user: " << am.FoundUserInFile("Ash");
	std::cout << "\n";
	std::cout << "Cathy user: " << am.FoundUserInFile("Cathy");*/


	return 0;
}