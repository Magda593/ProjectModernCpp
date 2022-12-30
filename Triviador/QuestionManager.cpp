#include "QuestionManager.h"

int QuestionManager::GetRandomNumber(int x)
{
	srand(time(NULL));
	int res;
	res= rand() % x + 0;
	return res;
}
