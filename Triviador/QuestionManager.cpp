#include "QuestionManager.h"

QuestionManager::QuestionManager()
{
}

void ReadNumericQuestions(std::ifstream& infile, std::string question2, int answer)
{
	QuestionType2 question;
	infile.open("questionType2.txt");
	while (!infile.fail())
	{
		getline(infile, question2);
		infile >> answer;
		std::string questionTwo2;

		getline(infile, questionTwo2);
		question.SaveQuestion(questionTwo2, answer);
	}
	infile.close();
}

int QuestionManager::GetRandomNumber(int x)
{
	srand(time(NULL));
	int res;
	res= rand() % x + 0;
	return res;
}

void QuestionManager::GetRandomGrillQuestion(GrillQuestion grillQuestion, QuestionManager questionManager)
{
	int position;
	position = questionManager.GetRandomNumber(50);
	//acces a member of an unordered_map
}

void QuestionManager::GetRandomNumericQuestion(QuestionType2 questionType2, QuestionManager questionManager)
{
	int position;
	position = questionManager.GetRandomNumber(74);
	//std::cout << grillQuestion.at(position);
}
