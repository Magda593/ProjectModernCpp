#include <iostream>
#include <fstream>
#include <string>
#include "AccountManager.h"
#include "QuestionType1.h"
#include "QuestionType2.h"
#include "Board.h"

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

	user.SetScoreForXUsername("Yan", 250);
	score = user.GetScoreForXUsername("Yan");
	std::cout << "Yan's score is now: " << score;
	std::cout << std::endl;
	user.SetScoreForXUsername("Ash", 250);
	score2 = user.GetScoreForXUsername("Ash");
	std::cout << "Ash's score is now: " << score2;
	std::cout << std::endl;
	//user.Login("Rei");
	//user.PrintUsernames();
	//std::cout << std::endl;

	QuestionType2 question2;
	//question2.SaveQuestion("2+2?", 4);

	std::ifstream questions;
	std::string questionTwo;
	int answerTwo;
	questions.open("questionType2.txt");
	while (!questions.fail())
	{
		getline(questions, questionTwo);
		questions >> answerTwo;
		question2.SaveQuestion(questionTwo, answerTwo);
	}
	questions.close();
	question2.GetQuestion();

	QuestionType1 question1;

	std::ifstream question;
	std::string questionOne;
	std::vector<std::string> answerOne;
	std::string option;
	questions.open("questionType1.txt");
	while (!question.fail())
	{
		getline(question, questionOne);
		for (int i = 0; i < 4; i++)
			answerOne.push_back(option);
		question1.saveQuestion(questionOne, answerOne);
	}
	questions.close();
	question1.GetQuestion1();

	Board board;
	std::cout << "What is the number of players you'd like this game to have?\n";
	int numberOfPlayers;
	std::cin >> numberOfPlayers;
	board.SetNumberOfPlayers(numberOfPlayers);
	board.SetBoard();
	board.MakeBoard();
	std::cout << board;
	board.Test();

	return 0;
}