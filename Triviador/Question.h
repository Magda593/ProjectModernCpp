#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "QuestionType1.h"
#include "QuestionType2.h"


class Question
{
public:
	Question();
	Question(std::string question1, std::string option1, std::string option2, std::string option3, std::string option4, std::string correctAnswer);
	void ReadQuestion(std::string question1, std::string option1, std::string option2, std::string option3, std::string option4, std::string correctAnswer);
	Question& operator=(Question&& question);
	int Equal(std::string correctAnswer, std::string answer);
	friend std::ostream& operator<<(std::ostream& os, const Question& question);
	void ShowTwoOptions(Question question);
	
	
private:
	std::string m_question1;
	std::string m_option1;
	std::string m_option2;
	std::string m_option3;
	std::string m_option4;
	std::string m_correctAnswer;
};

