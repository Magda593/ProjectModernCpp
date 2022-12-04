#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "QuestionType1.h"
#include "QuestionType2.h"


class QuestionManager
{
public:
	QuestionManager();
	QuestionManager(std::string question1, std::string option1, std::string option2, std::string option3, std::string option4, std::string correctAnswer);
	void ReadQuestion(std::string question1, std::string option1, std::string option2, std::string option3, std::string option4, std::string correctAnswer);
	QuestionManager& operator=(QuestionManager&& questionManager);
	int Equal(std::string correctAnswer, std::string answer);
	
private:
	std::string m_question1;
	std::string m_option1;
	std::string m_option2;
	std::string m_option3;
	std::string m_option4;
	std::string m_correctAnswer;
};

