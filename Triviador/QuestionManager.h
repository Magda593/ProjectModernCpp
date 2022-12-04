#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "QuestionType1.h"
#include "QuestionType2.h"


class QuestionManager
{
public:
	void ReadQuestionType2();
private:
	std::string option1;
	std::string option2;
	std::string option3;
	std::string option4;
	std::string correctAnswer;
};

