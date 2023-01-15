#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <random>
#include "NumericQuestion.h"


class GrillQuestion
{
public:
	GrillQuestion();
	GrillQuestion(std::string question1, std::string option1, std::string option2, std::string option3, std::string option4);
	void ReadQuestion();
	void SaveQuestion(std::string question1, std::string option1, std::string option2, std::string option3, std::string option4, std::string correctAnswer);
	int GetRandomNumber();
	void GetQuestion();
	std::string GetRandomQuestion();

private:
	std::string m_question1;
	std::string m_option1;
	std::string m_option2;
	std::string m_option3;
	std::string m_option4;
	std::string m_correctAnswer;
	std::vector<std::string> m_grillQuestion;
};

