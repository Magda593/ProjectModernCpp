#include "QuestionManager.h"

int QuestionManager::GetRandomNumber(int x)
{
	srand(time(NULL));
	int res;
	res= rand() % x + 0;
	return res;
}

void QuestionManager::GetQuestionType(GrillQuestion grillQuestion, QuestionType2 questionType2, QuestionManager questionManager)
{
	//if(questionManager.GetRandomNumber(1)==0)
		//show a grill question
	//else
		//show a numeric question
}

void QuestionManager::GetRandomGrillQuestion(QuestionManager questionManager)
{
	int position;
	position=questionManager.GetRandomNumber(74);
	//std::cout << grillQuestion.at(position);
}
