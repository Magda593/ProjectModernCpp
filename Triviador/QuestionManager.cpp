#include "QuestionManager.h"

QuestionManager::QuestionManager()
{
}

//void QuestionManager::ReadNumericQuestions()
//{
//	QuestionType2 question;
//	std::ifstream inFile;
//	std::string line;
//	int line2;
//	inFile.open("grillQuestion.txt");
//
//	if (!inFile) std::cout << "Unable to open file.";
//	while (inFile.good())
//	{
//		std::getline(inFile, line);
//		inFile >> line2;
//		question.SaveQuestion(line, line2);
//	}
//	question.GetQuestion();
//}

//void QuestionManager::GetQuestion()
//{
//	for (auto& x : m_questionType2)
		//std::cout << x.first << ": " << x.second << std::endl;
//}


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

//std::string QuestionManager::GetRandomNumericQuestion(QuestionType2 questionType2, QuestionManager questionManager)
//{
//	int position;
//	int nr = 0;
//	std::pair<std::string, int> p;
//	auto x = questionType2.begin();
//	auto y = questionType2.end();
//	position = questionManager.GetRandomNumber(74);
//	for (auto el : questionType2)
//	{
//		if (nr == position)
//		{
//			p = el;
//			break;
//		}
//		nr++;
//	}
//	return p.first;
//}
