#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "QuestionType1.h"
#include "QuestionType2.h"


class QuestionManager :public QuestionType1, QuestionType2
{
public:
	QuestionManager();
	QuestionManager(std::string m_question1, std::string m_option1, std::string m_option2, std::string m_option3, std::string m_option4, std::string m_correctAnswer);

private:
	std::string m_question1;
	std::string m_option1;
	std::string m_option2;
	std::string m_option3;
	std::string m_option4;
	std::string m_correctAnswer;
};

