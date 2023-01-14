#pragma once

#include <stdlib.h>
#include <time.h>
#include "GrillQuestion.h"
#include "Question.h"

#include "QuestionType2.h"
#include <fstream>


class QuestionManager
{
public:

	QuestionManager();
	void ReadNumericQuestions(std::ifstream& infile, std::string question2, int answer);

	int GetRandomNumber(int x);

	void GetRandomGrillQuestion(GrillQuestion grillQuestion, QuestionManager questionManager);
	void GetRandomNumericQuestion(QuestionType2 questionType2, QuestionManager questionManager);

private:
	GrillQuestion m_grillQuestion;
	QuestionType2 m_questionType2;
};

