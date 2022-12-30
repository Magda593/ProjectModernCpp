#pragma once

#include <stdlib.h>
#include <time.h>
#include "GrillQuestion.h"
//#include <GrillQuestion.h>
//#include <QuestionType2.h>

class QuestionManager
{
public:

	int GetRandomNumber(int x);
	void GetQuestionType(GrillQuestion grillQuestion, QuestionType2 questionType2, QuestionManager questionManager);
};

