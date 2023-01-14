#pragma once

#include <stdlib.h>
#include <time.h>
#include "GrillQuestion.h"
#include "Question.h"

#include "NumericQuestion.h"
#include <fstream>


class QuestionManager
{
public:

	QuestionManager();
	void ReadNumericQuestions();

	int GetRandomNumber(int x);

	void GetRandomGrillQuestion(GrillQuestion grillQuestion, QuestionManager questionManager);
	std::string GetRandomNumericQuestion(NumericQuestion questionType2, QuestionManager questionManager);

private:
	GrillQuestion m_grillQuestion;
	NumericQuestion m_questionType2;
};

