#pragma once

#include <stdlib.h>
#include <time.h>
#include "GrillQuestion.h"
#include "Question.h"

//#include <QuestionType2.h>

class QuestionManager
{
public:

	QuestionManager();

	int GetRandomNumber(int x);
	void GetQuestionType(GrillQuestion grillQuestion, QuestionType2 questionType2, QuestionManager questionManager);

	void GetRandomGrillQuestion(GrillQuestion grillQuestion, QuestionManager questionManager);
	void GetRandomNumericQuestion(QuestionType2 questionType2, QuestionManager questionManager);

private:
	GrillQuestion m_grillQuestion;
	QuestionType2 m_questionType2;
};

