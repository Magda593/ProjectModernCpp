#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <tuple>
#include <random>
#include "QuestionType1.h"
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
	GrillQuestion& operator=(GrillQuestion&& question);
	int Equal(std::string correctAnswer, std::string answer);
	std::string GetRandomQuestion();
	friend std::ostream& operator<<(std::ostream& os, const GrillQuestion& question);
	void ShowTwoOptions();
	
	
private:
	std::string m_question1;
	std::string m_option1;
	std::string m_option2;
	std::string m_option3;
	std::string m_option4;
	std::string m_correctAnswer;
	std::vector<std::string> m_grillQuestion;
};

